## This seems to be working now, with a decent speed up
## It is all implemented using the perm-reducing re-ordering, which gives a good speed up to the fixed_effect sampling, 
##    and moderate speed-ups to the other two steps.
## potentially strange results with limited discritization

library(MCMCglmm)
source('../R_BSFG/BSFG_discreteRandom_functions.R')
Data <- as.data.frame(read.table(file = "./gryphon.dat", header = TRUE))
names(Data)[1] <- "animal"
Data$animal <- as.factor(Data$animal)
Data$MOTHER <- as.factor(Data$MOTHER)
Data$BYEAR <- as.factor(Data$BYEAR)
Data$SEX <- as.factor(Data$SEX)
Data$BWT <- as.numeric(Data$BWT)
Data$TARSUS <- as.numeric(Data$TARSUS)
head(Data)
Ped <- as.data.frame(read.table(file = "./gryphon.ped", header = TRUE))
for (x in 1:3) Ped[, x] <- as.factor(Ped[, x])
head(Ped)

# Data$BWT = matrix(rnorm(nrow(Data),0,sd(Data$BWT,na.rm=T)),nc=1)

prior1.1 <- list(G = list(G1 = list(V = 1, nu = 0.002)), R = list(V = 1,nu = 0.002))
prior1.1 = list(R = list(V = 1/3, nu = 3), G = list(G1 = list(V = 1/3,nu=3)))
model1.1 <- MCMCglmm(BWT ~ 1, random = ~animal, pedigree = Ped, data = Data, prior = prior1.1)

model1.2 <- MCMCglmm(BWT ~ SEX, random = ~animal, pedigree = Ped,
    data = Data, prior = prior1.1, nitt = 6500, thin = 5, burnin = 1500,
    verbose = FALSE)

prior1.3 <- list(G = list(G1 = list(V = 1, n = 0.002), G2 = list(V = 1,n = 0.002)), R = list(V = 1, n = 0.002))
prior1.3 = list(R = list(V = 1/3, nu = 3), G = list(G1 = list(V = 1/3,nu=3),G2 = list(V = 1/3,nu=3)))
model1.3 <- MCMCglmm(BWT ~ SEX, random = ~animal + BYEAR, pedigree = Ped,
    data = Data, nitt = 6500, thin = 5, burnin = 1500, prior = prior1.3,pr=T,
    verbose = FALSE)
posterior.mode(model1.3$VCV)

mcmc_model = model1.3
mcmc_model = model1.2

# now BSFG

discrete_divisions = 15
priors = list(
    tot_Y_var      =   list(V = 2.2/3.1, nu = 3.1)
)
priors$tot_Y_prec_shape = with(priors$tot_Y_var,V * nu)
priors$tot_Y_prec_rate  = with(priors$tot_Y_var,nu - 2)

data = droplevels(subset(Data,!is.na(BWT)))
data$animal = factor(as.character(data$animal),levels = data$animal)

index = match(data$animal,Ped[,1])


A_inv_mats = list(animal = forceSymmetric(inverseA(Ped)[[1]]))
A_mats = c()

# build Z matrices from random model
RE_names = c(names(A_inv_mats),'BYEAR')
n_RE = length(RE_names)
Z_matrices = lapply(RE_names,function(re) {
	# Diagonal(r_RE[re],1)
	Z = Matrix(model.matrix(formula(sprintf('~0 + %s',re)),data),sparse = TRUE)
	Z[,paste0(re,levels(data[[re]]))]
})
names(Z_matrices) = RE_names
r_RE = sapply(Z_matrices,function(x) ncol(x))
# r_RE = sapply(RE_names,function(x) dim(randomEffects[[x]])[1])

Z_all = do.call(cbind,Z_matrices)

# for(re in RE_names[RE_names %in% names(randomEffects) == F]){
# 	randomEffects[[re]] = Diagonal(ncol(Z_matrices[[re]]),1)
# 	rownames(randomEffects[[re]]) = levels(data[[re]])
# }


fix_A = function(x) forceSymmetric(drop0(x,tol = 1e-10))

A_mats = lapply(RE_names,function(re) {
	if(re %in% names(A_mats)) {
		A = A_mats[[re]]
	} else if(re %in% names(A_inv_mats)){
			A = solve(A_inv_mats[[re]])
			rownames(A) = rownames(A_inv_mats[[re]])
	} else{
		A = Diagonal(ncol(Z_matrices[[re]]))
		rownames(A) = sub(re,'',colnames(Z_matrices[[re]]))
	}
	index = match(sub(re,'',colnames(Z_matrices[[re]])),rownames(A))  # A must have rownames
	fix_A(A[index,index])
})
names(A_mats) = RE_names

Ai_mats = lapply(RE_names,function(re) {
	if(re %in% names(A_inv_mats)){
		Ai = A_inv_mats[[re]]
		index = match(sub(re,'',colnames(Z_matrices[[re]])),rownames(Ai))  # Ai must have rownames
		Ai = Ai[index,index]
	} else {
		Ai = solve(A_mats[[re]])
	}
	Ai = fix_A(Ai)
	Ai
})
chol_Ai_mats = lapply(Ai_mats,chol)

h2_divisions = expand.grid(lapply(RE_names,function(re) 0:discrete_divisions)) / discrete_divisions
colnames(h2_divisions) = RE_names
h2_divisions = t(h2_divisions[rowSums(h2_divisions) < 1,,drop=FALSE])

library(MCMCpack)
priors$discrete_priors = sapply(1:ncol(h2_divisions),function(x) {
    h2s = h2_divisions[,x]
    pmax(pmin(ddirichlet(c(h2s,1-sum(h2s)),rep(2,length(h2s)+1)),10),1e-10)
})/100


ZAZts = list()
for(i in 1:n_RE){
	ZAZts[[i]] = forceSymmetric(Z_matrices[[i]] %*% A_mats[[i]] %*% t(Z_matrices[[i]]))
}

#C
ZtZ = crossprod(Z_all)
make_Ai = function(Ai_mats,h2s) {
	do.call(bdiag,lapply(1:length(h2s),function(j) {
		if(h2s[j] == 0) {  # if h2==0, then we want a Diagonal matrix with Inf diagonal. This will allow Cinv = 0
			Diagonal(nrow(Ai_mats[[j]]),Inf)
		} else{
			Ai_mats[[j]]/h2s[j]  
		}
	}))
}

make_Chol_Ai = function(chol_Ai_mats,h2s){
	do.call(bdiag,lapply(1:length(h2s),function(i) {
		if(h2s[i] == 0) return(Diagonal(nrow(chol_Ai_mats[[i]]),Inf))  # if h2==0, then we want a Diagonal matrix with Inf diagonal.
		chol_Ai = chol_Ai_mats[[i]]
		chol_Ai@x = chol_Ai@x / sqrt(h2s[i])
		chol_Ai
	}))
}
# setup of symbolic Cholesky of C
Ai = forceSymmetric(make_Ai(Ai_mats,rep(1,n_RE)/(n_RE+1)))
Cholesky_C = Cholesky(ZtZ + Ai)

randomEffect_C_Choleskys = lapply(1:ncol(h2_divisions),function(i) {    	
	if(i %% 100 == 0) print(i)
	h2s = h2_divisions[,i]
	Ai = make_Ai(Ai_mats,h2s)
	C = ZtZ/(1-sum(h2s))
	C = C + Ai
	Cholesky_C_i = update(Cholesky_C,forceSymmetric(C))


	chol_A_inv = make_Chol_Ai(chol_Ai_mats,h2s)

})

# Sigma
make_Sigma = function(ZAZts,h2s){
	R = 0
	for(i in 1:length(h2s)){
		R = R + h2s[i]*ZAZts[[i]]
	}
	forceSymmetric(R + (1-sum(h2s)) * Diagonal(nrow(R)))
}

# setup of symbolic Cholesky of Sigma
Sigma = make_Sigma(ZAZts,h2_divisions[,2])
Cholesky_Sigma_base = Cholesky(Sigma,perm=T,super=T)
# Cholesky_Sigma_base = Cholesky(Sigma,LDL=F,perm=T)
Sigma_Perm = expand(Cholesky_Sigma_base)$P
if(all(diag(Sigma_Perm))) Sigma_Perm = NULL

Sigma_Choleskys = lapply(1:ncol(h2_divisions),function(i) {
	if(i %% 100 == 0) print(i)
	Sigma = forceSymmetric(make_Sigma(ZAZts,h2_divisions[,i]))
	stopifnot(class(Sigma) == 'dsCMatrix')
	Cholesky_Sigma = update(Cholesky_Sigma_base,Sigma)
	log_det = 2*determinant(Cholesky_Sigma,logarithm=T)$modulus
	if(is.null(Sigma_Perm)) {
		chol_Sigma = expand(Cholesky_Sigma)$L
	} else{
		chol_Sigma = t(Sigma_Perm) %*% expand(Cholesky_Sigma)$L
	}
	list(log_det = log_det,Cholesky_Sigma = Cholesky_Sigma,chol_Sigma=chol_Sigma)
})


Y = as.matrix(data[,'BWT',drop=F])
fixed = formula(~SEX)

# build X from fixed model
X = model.matrix(fixed,data)
b = ncol(X)
p=1

tot_Y_prec = with(priors,rgamma(1,shape = tot_Y_prec_shape,rate = tot_Y_prec_rate))
tot_Y_prec = .13

h2_index = sample(1:ncol(h2_divisions),1,replace=T)
h2_index = 40
h2 = h2_divisions[,h2_index,drop=FALSE]


a = do.call(rbind,lapply(RE_names,function(effect){
	rnorm(r_RE[effect], 0, sqrt(h2[effect,] / tot_Y_prec))
}))

B = rnorm(b)
B = c(6,2.4)

nIter = 500
burn = 50
thin = 1

posterior = c();#matrix(NA,nrow = (nIter-burn)/thin,ncol = length(B)+length(h2)+1)
as = c()
sp = 0
start = Sys.time()
for(i in 1:nIter){
	if(i %% 100 == 0) print(i)

	Design = X
	rows = b
	prior_meanB = matrix(0,rows,p)
	prior_precB = matrix(rep(1e-10,b),nc=1)
	# prior_precB = matrix(rep(0,b),nc=1)
	# recover()
	B = sample_MME_fixedEffects(Y,Design,Sigma_Choleskys, Sigma_Perm,  h2_index, tot_Y_prec, prior_meanB, prior_precB,1)

	Y_tilde = as.matrix(Y - X %*% B)
	tot_Y_prec = sample_tot_prec(Y_tilde, priors$tot_Y_prec_shape, priors$tot_Y_prec_rate, Sigma_Choleskys, Sigma_Perm,  h2_index,1)
	h2_index = sample_h2s_discrete(Y_tilde,tot_Y_prec, Sigma_Choleskys, Sigma_Perm, priors$discrete_priors,8)
	# h2_index = sample_h2s_discrete_MH(Y_tilde,tot_Y_prec, Sigma_Choleskys,Sigma_Perm, priors$discrete_priors,h2_divisions,h2_index,step_size = 0.02,ncores=1)
	h2 = h2_divisions[,h2_index,drop=FALSE]
	# a_prec = tot_Y_prec / colSums(h2)

	# prior_meanA = matrix(0,ncol(Z_all),p)
	# a = sample_MME_ZAZts(Y_tilde, Z_all, tot_Y_prec, prior_meanA, randomEffect_C_Choleskys, h2, h2_index,chol_Ai_mats,1)
	# a = sapply(1:1000,function(x) sample_MME_ZAZts_inv(Y_tilde, Z_all, tot_Y_prec, prior_meanA, randomEffect_C_Choleskys, h2, h2_index,chol_Ai_mats,1))	
	# a = a[1:nrow(A_mats[[1]]),]
	# i = sample(1:nrow(a)^2,10000)
	# plot(cov(t(as.matrix(a)))[i],as.matrix(A_mats[[1]])[i])
	# as = cbind(as,a)

	if((i > burn) & (i-burn)%%thin == 0){
		sp = sp + 1
		posterior = rbind(posterior,c(B, h2/tot_Y_prec, (1-sum(h2))/tot_Y_prec,h2))
	}

}
Sys.time()-start

boxplot(posterior[,1:5])
boxplot(cbind(mcmc_model$Sol[,1:2],mcmc_model$VCV))
effectiveSize(posterior[1:sp,])
effectiveSize(cbind(mcmc_model$Sol[,1:2],mcmc_model$VCV))
i=2;qqplot(posterior[,i],mcmc_model$Sol[,i]);abline(0,1)
i=1;qqplot(posterior[,2+i],mcmc_model$VCV[,i]);abline(0,1)
i=2;qqplot(posterior[,2+i],mcmc_model$VCV[,i]);abline(0,1)
i=3;qqplot(posterior[,2+i],mcmc_model$VCV[,i]);abline(0,1)

for(i in 1:ncol(posterior)) plot(posterior[,i],type='l',main = i)

microbenchmark(
	sample_MME_fixedEffects_inv(Y,Design,Sigma_invs, h2_index, tot_Y_prec, prior_meanB, prior_precB,1),
	sample_MME_fixedEffects_inv_v2(as.matrix(Y),Design,Sigma_Choleskys, Sigma_Perm,  h2_index, tot_Y_prec, prior_meanB, prior_precB,1),
	sample_MME_ZAZts_inv(Y_tilde, Z_all, tot_Y_prec, prior_meanA, randomEffect_C_Choleskys, h2, h2_index,chol_As,1)
	)

microbenchmark(
	sample_tot_prec_inv(Y_tilde, priors$tot_Y_prec_shape, priors$tot_Y_prec_rate, Sigma_invs, h2_index,1),
	sample_tot_prec_inv_v2(Y_tilde, priors$tot_Y_prec_shape, priors$tot_Y_prec_rate, Sigma_Choleskys, Sigma_Perm,  h2_index,1)
	)

microbenchmark(
	sample_h2s_discrete_inv(Y_tilde,tot_Y_prec, Sigma_invs,priors$discrete_priors,1),
	sample_h2s_discrete_inv_v2(Y_tilde,tot_Y_prec, Sigma_Choleskys, Sigma_Perm, priors$discrete_priors,1)
	)

microbenchmark(
	sample_h2s_discrete_inv_v2(Y_tilde,tot_Y_prec, Sigma_Choleskys, Sigma_Perm, priors$discrete_priors,1),
	sample_h2s_discrete_inv_v2(Y_tilde,tot_Y_prec, Sigma_Choleskys, Sigma_Perm, priors$discrete_priors,8)
	,times=10)

Ymat = matrix(Y,nrow = nrow(Y),nc = 100)

microbenchmark(
	sample_h2s_discrete_inv_v2(Ymat,tot_Y_prec, Sigma_Choleskys, Sigma_Perm, priors$discrete_priors,8),
	sample_h2s_discrete_MH(Ymat,rep(tot_Y_prec,ncol(Ymat)), Sigma_Choleskys,Sigma_Perm, priors$discrete_priors,h2_divisions,rep(h2_index,ncol(Ymat)),step_size = 0.02,ncores=1)
	,times = 2)