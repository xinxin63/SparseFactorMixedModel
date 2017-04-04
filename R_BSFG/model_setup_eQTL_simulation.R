library(microbenchmark)
library(MCMCpack)
library(BSFG)

# set the directory to the location of the setup.RData or setup.mat file

setwd("~/Box Sync/DER_projects/BSFG/R_BSFG/Sim_FE1_1")

# create a folder for holding the posterior samples of the current chain (multiple folders could be used for different chains)
rep = "2"
folder = sprintf('R_rep_%s',rep)
try(dir.create(folder))
setwd(folder)


# initialize priors
run_parameters = list(
    sampler = 'fast_BSFG',
    # sampler = 'general_BSFG',
    Posterior_folder = 'Posterior',
    simulation   = T,
    scale_Y      = FALSE,
    b0           = 1,
    b1           = 0.0005,
    epsilon      = 1e-1,
    prop         = 1.00,
    k_init       = 20,
    h2_divisions = 10,
    burn         = 100,
    thin         = 2
    )

priors = list(
    # fixed_var = list(V = 5e5,   nu = 2.001),
    fixed_var = list(V = 1,     nu = 3),
    tot_Y_var = list(V = 0.5,   nu = 3),
    tot_F_var = list(V = 18/20, nu = 20),
    delta_1   = list(shape = 2.1,  rate = 1/20),
    delta_2   = list(shape = 3, rate = 1),
    Lambda_df =   3,
    B_df =   3,
    B_F_df =   3,
    h2_priors_factors   =   c(run_parameters$h2_divisions-1,rep(1,run_parameters$h2_divisions-1))/(2*(run_parameters$h2_divisions-1)),
    h2_priors_resids   =   c(0,rep(1,99))*dbeta(seq(0,1,length=102),2,2)[2:101]
)

print('Initializing')
# setup = load_simulation_data()
# setup = load_simulation_FE_data()
load('../Sim_data.RData')
sim_data$data = with(sim_data,data.frame(TRT = X[,'TRT'],Line = colnames(Z1)[apply(Z1,1,function(x) which(x==1))]))
sim_data$B = rbind(sim_data$mu,sim_data$B)
BSFG_state = with(sim_data,BSFG_init(Y, model=~TRT+(1|Line), data, #factor_model_fixed = ~1,
                                  priors=priors,run_parameters=run_parameters,
                                  cis_genotypes = lapply(1:ncol(cisGenotypes),function(x) matrix(cisGenotypes[,x],ncol=1)),
                                  setup = sim_data))
BSFG_state$current_state$F_h2

h2_divisions = run_parameters$h2_divisions
BSFG_state$priors$Resid_discrete_priors = with(BSFG_state$data_matrices, sapply(1:ncol(h2s_matrix),function(x) {
    h2s = h2s_matrix[,x]
    pmax(pmin(ddirichlet(c(h2s,1-sum(h2s)),rep(2,length(h2s)+1)),10),1e-10)
}))
BSFG_state$priors$Resid_discrete_priors = BSFG_state$priors$Resid_discrete_priors/sum(BSFG_state$priors$Resid_discrete_priors)
BSFG_state$priors$F_discrete_priors = c(h2_divisions-1,rep(1,h2_divisions-1))/(2*(h2_divisions-1))

# BSFG_state$priors$F_discrete_priors = with(BSFG_state$data_matrices, sapply(1:nrow(h2s_matrix),function(x) {
#     h2s = h2s_matrix[x,]
#     pmax(pmin(ddirichlet(c(h2s,1-sum(h2s)),rep(2,length(h2s)+1)),10),1e-10)
# }))

save(BSFG_state,file="BSFG_state.RData")

BSFG_state = clear_Posterior(BSFG_state)


# # optional: To load from end of previous run, run above code, then run these lines:
# load('Posterior.RData')
# load('BSFG_state.RData')
# load('Priors.RData')
#  BSFG_state$current_state = current_state
#  BSFG_state$Posterior = Posterior
#  BSFG_state$priors = priors
# start_i = run_parameters$nrun;

# Run Gibbs sampler. Run in smallish chunks. Output can be used to re-start chain where it left off.
# burn in

n_samples = 100;
for(i  in 1:70) {
    print(sprintf('Run %d',i))
    # microbenchmark(
    #     BSFG_sampler(BSFG_state,2,detectCores()),
    #     BSFG_sampler(BSFG_state,2,1),
    #     times = 10
    #     )
    BSFG_state = sample_BSFG(BSFG_state,n_samples,ncores=1)
    if(BSFG_state$current_state$nrun < BSFG_state$run_parameters$burn) {
      BSFG_state = reorder_factors(BSFG_state)
    }
    BSFG_state = save_posterior_chunk(BSFG_state)
    print(BSFG_state)
    plot(BSFG_state)
}

library(shinystan)
library(MCMCpack)
samples = BSFG_state$Posterior$F_h2
samples = list(A=BSFG_state$Posterior$Lambda[,,1])
samples[[1]][] = samples[[1]][,order(-abs(colMeans(samples[[1]])))]
my_sso <- as.shinystan(samples)
my_sso <- launch_shinystan(my_sso)