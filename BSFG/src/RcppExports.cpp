// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "BSFG_types.h"
#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

// sample_coefs_parallel_sparse_c_Eigen
MatrixXd sample_coefs_parallel_sparse_c_Eigen(MSpMat Ut, Map<MatrixXd> Eta, Map<MatrixXd> W, Map<VectorXd> h2, Map<VectorXd> tot_Eta_prec, Map<VectorXd> s, Map<MatrixXd> prior_mean, Map<MatrixXd> prior_prec, Map<MatrixXd> randn_theta, Map<MatrixXd> randn_e, int grainSize);
RcppExport SEXP BSFG_sample_coefs_parallel_sparse_c_Eigen(SEXP UtSEXP, SEXP EtaSEXP, SEXP WSEXP, SEXP h2SEXP, SEXP tot_Eta_precSEXP, SEXP sSEXP, SEXP prior_meanSEXP, SEXP prior_precSEXP, SEXP randn_thetaSEXP, SEXP randn_eSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< MSpMat >::type Ut(UtSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type W(WSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type h2(h2SEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type s(sSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prior_mean(prior_meanSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prior_prec(prior_precSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randn_theta(randn_thetaSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randn_e(randn_eSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_coefs_parallel_sparse_c_Eigen(Ut, Eta, W, h2, tot_Eta_prec, s, prior_mean, prior_prec, randn_theta, randn_e, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// sample_coefs_set_c
MatrixXd sample_coefs_set_c(Rcpp::List model_matrices, Rcpp::List randn_draws, Rcpp::List s_vectors, Map<VectorXd> h2s, Map<VectorXd> tot_Eta_prec, Map<MatrixXd> prior_mean, Map<MatrixXd> prior_prec, int n, int grainSize);
RcppExport SEXP BSFG_sample_coefs_set_c(SEXP model_matricesSEXP, SEXP randn_drawsSEXP, SEXP s_vectorsSEXP, SEXP h2sSEXP, SEXP tot_Eta_precSEXP, SEXP prior_meanSEXP, SEXP prior_precSEXP, SEXP nSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type model_matrices(model_matricesSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type randn_draws(randn_drawsSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type s_vectors(s_vectorsSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type h2s(h2sSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prior_mean(prior_meanSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prior_prec(prior_precSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_coefs_set_c(model_matrices, randn_draws, s_vectors, h2s, tot_Eta_prec, prior_mean, prior_prec, n, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// tot_prec_scores_c
VectorXd tot_prec_scores_c(Map<MatrixXd> UtEta, Map<VectorXd> h2, Map<VectorXd> s);
RcppExport SEXP BSFG_tot_prec_scores_c(SEXP UtEtaSEXP, SEXP h2SEXP, SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type UtEta(UtEtaSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type h2(h2SEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type s(sSEXP);
    rcpp_result_gen = Rcpp::wrap(tot_prec_scores_c(UtEta, h2, s));
    return rcpp_result_gen;
END_RCPP
}
// tot_prec_scores_withX_c
VectorXd tot_prec_scores_withX_c(Map<MatrixXd> UtEta, Map<MatrixXd> B_F, Map<VectorXd> h2, Map<VectorXd> s, Map<MatrixXd> prec_B_F);
RcppExport SEXP BSFG_tot_prec_scores_withX_c(SEXP UtEtaSEXP, SEXP B_FSEXP, SEXP h2SEXP, SEXP sSEXP, SEXP prec_B_FSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type UtEta(UtEtaSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type B_F(B_FSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type h2(h2SEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type s(sSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prec_B_F(prec_B_FSEXP);
    rcpp_result_gen = Rcpp::wrap(tot_prec_scores_withX_c(UtEta, B_F, h2, s, prec_B_F));
    return rcpp_result_gen;
END_RCPP
}
// log_p_h2s_fast
MatrixXd log_p_h2s_fast(Map<MatrixXd> UtEta, Map<VectorXd> tot_Eta_prec, Map<VectorXd> discrete_priors, Map<VectorXd> s, int grainSize);
RcppExport SEXP BSFG_log_p_h2s_fast(SEXP UtEtaSEXP, SEXP tot_Eta_precSEXP, SEXP discrete_priorsSEXP, SEXP sSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type UtEta(UtEtaSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type discrete_priors(discrete_priorsSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type s(sSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(log_p_h2s_fast(UtEta, tot_Eta_prec, discrete_priors, s, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// sample_randomEffects_parallel_sparse_c_Eigen
MatrixXd sample_randomEffects_parallel_sparse_c_Eigen(Map<MatrixXd> Eta, MSpMat Z, Map<ArrayXd> tot_prec, Map<ArrayXd> h2, List invert_aZZt_Kinv, Map<ArrayXXd> randn_draws, int grainSize);
RcppExport SEXP BSFG_sample_randomEffects_parallel_sparse_c_Eigen(SEXP EtaSEXP, SEXP ZSEXP, SEXP tot_precSEXP, SEXP h2SEXP, SEXP invert_aZZt_KinvSEXP, SEXP randn_drawsSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< MSpMat >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< Map<ArrayXd> >::type tot_prec(tot_precSEXP);
    Rcpp::traits::input_parameter< Map<ArrayXd> >::type h2(h2SEXP);
    Rcpp::traits::input_parameter< List >::type invert_aZZt_Kinv(invert_aZZt_KinvSEXP);
    Rcpp::traits::input_parameter< Map<ArrayXXd> >::type randn_draws(randn_drawsSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_randomEffects_parallel_sparse_c_Eigen(Eta, Z, tot_prec, h2, invert_aZZt_Kinv, randn_draws, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// sample_factors_scores_sparse_c_Eigen
MatrixXd sample_factors_scores_sparse_c_Eigen(Map<MatrixXd> Eta_tilde, Map<MatrixXd> prior_mean, Map<MatrixXd> Lambda, Map<VectorXd> resid_Eta_prec, Map<VectorXd> F_e_prec, Map<MatrixXd> randn_draws);
RcppExport SEXP BSFG_sample_factors_scores_sparse_c_Eigen(SEXP Eta_tildeSEXP, SEXP prior_meanSEXP, SEXP LambdaSEXP, SEXP resid_Eta_precSEXP, SEXP F_e_precSEXP, SEXP randn_drawsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Eta_tilde(Eta_tildeSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prior_mean(prior_meanSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type resid_Eta_prec(resid_Eta_precSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type F_e_prec(F_e_precSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randn_draws(randn_drawsSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_factors_scores_sparse_c_Eigen(Eta_tilde, prior_mean, Lambda, resid_Eta_prec, F_e_prec, randn_draws));
    return rcpp_result_gen;
END_RCPP
}
// sample_delta_c_Eigen
VectorXd sample_delta_c_Eigen(VectorXd delta, VectorXd tauh, Map<MatrixXd> Lambda_prec, double delta_1_shape, double delta_1_rate, double delta_2_shape, double delta_2_rate, Map<MatrixXd> randg_draws, Map<MatrixXd> Lambda2);
RcppExport SEXP BSFG_sample_delta_c_Eigen(SEXP deltaSEXP, SEXP tauhSEXP, SEXP Lambda_precSEXP, SEXP delta_1_shapeSEXP, SEXP delta_1_rateSEXP, SEXP delta_2_shapeSEXP, SEXP delta_2_rateSEXP, SEXP randg_drawsSEXP, SEXP Lambda2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< VectorXd >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< VectorXd >::type tauh(tauhSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Lambda_prec(Lambda_precSEXP);
    Rcpp::traits::input_parameter< double >::type delta_1_shape(delta_1_shapeSEXP);
    Rcpp::traits::input_parameter< double >::type delta_1_rate(delta_1_rateSEXP);
    Rcpp::traits::input_parameter< double >::type delta_2_shape(delta_2_shapeSEXP);
    Rcpp::traits::input_parameter< double >::type delta_2_rate(delta_2_rateSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randg_draws(randg_drawsSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Lambda2(Lambda2SEXP);
    rcpp_result_gen = Rcpp::wrap(sample_delta_c_Eigen(delta, tauh, Lambda_prec, delta_1_shape, delta_1_rate, delta_2_shape, delta_2_rate, randg_draws, Lambda2));
    return rcpp_result_gen;
END_RCPP
}
// sample_MME_single_diagK_c
VectorXd sample_MME_single_diagK_c(Map<VectorXd> y, Map<MatrixXd> W, Map<VectorXd> prior_mean, Map<VectorXd> prior_prec, MSpMat chol_R, double tot_Eta_prec, Map<VectorXd> randn_theta, Map<VectorXd> randn_e);
RcppExport SEXP BSFG_sample_MME_single_diagK_c(SEXP ySEXP, SEXP WSEXP, SEXP prior_meanSEXP, SEXP prior_precSEXP, SEXP chol_RSEXP, SEXP tot_Eta_precSEXP, SEXP randn_thetaSEXP, SEXP randn_eSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<VectorXd> >::type y(ySEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type W(WSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type prior_mean(prior_meanSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type prior_prec(prior_precSEXP);
    Rcpp::traits::input_parameter< MSpMat >::type chol_R(chol_RSEXP);
    Rcpp::traits::input_parameter< double >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type randn_theta(randn_thetaSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type randn_e(randn_eSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_MME_single_diagK_c(y, W, prior_mean, prior_prec, chol_R, tot_Eta_prec, randn_theta, randn_e));
    return rcpp_result_gen;
END_RCPP
}
// sample_MME_fixedEffects_c
MatrixXd sample_MME_fixedEffects_c(Map<MatrixXd> Y, Map<MatrixXd> W, Rcpp::List Sigma_Choleskys, Rcpp::IntegerVector h2s_index, Map<VectorXd> tot_Eta_prec, Map<MatrixXd> prior_mean, Map<MatrixXd> prior_prec, Map<MatrixXd> randn_theta, Map<MatrixXd> randn_e, int grainSize);
RcppExport SEXP BSFG_sample_MME_fixedEffects_c(SEXP YSEXP, SEXP WSEXP, SEXP Sigma_CholeskysSEXP, SEXP h2s_indexSEXP, SEXP tot_Eta_precSEXP, SEXP prior_meanSEXP, SEXP prior_precSEXP, SEXP randn_thetaSEXP, SEXP randn_eSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type W(WSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type Sigma_Choleskys(Sigma_CholeskysSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type h2s_index(h2s_indexSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prior_mean(prior_meanSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type prior_prec(prior_precSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randn_theta(randn_thetaSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randn_e(randn_eSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_MME_fixedEffects_c(Y, W, Sigma_Choleskys, h2s_index, tot_Eta_prec, prior_mean, prior_prec, randn_theta, randn_e, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// sample_MME_single_diagR
VectorXd sample_MME_single_diagR(VectorXd Y, SpMat W, SpMat chol_C, double pe, SpMat chol_K_inv, double tot_Eta_prec, VectorXd randn_theta, VectorXd randn_e);
RcppExport SEXP BSFG_sample_MME_single_diagR(SEXP YSEXP, SEXP WSEXP, SEXP chol_CSEXP, SEXP peSEXP, SEXP chol_K_invSEXP, SEXP tot_Eta_precSEXP, SEXP randn_thetaSEXP, SEXP randn_eSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< SpMat >::type W(WSEXP);
    Rcpp::traits::input_parameter< SpMat >::type chol_C(chol_CSEXP);
    Rcpp::traits::input_parameter< double >::type pe(peSEXP);
    Rcpp::traits::input_parameter< SpMat >::type chol_K_inv(chol_K_invSEXP);
    Rcpp::traits::input_parameter< double >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< VectorXd >::type randn_theta(randn_thetaSEXP);
    Rcpp::traits::input_parameter< VectorXd >::type randn_e(randn_eSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_MME_single_diagR(Y, W, chol_C, pe, chol_K_inv, tot_Eta_prec, randn_theta, randn_e));
    return rcpp_result_gen;
END_RCPP
}
// sample_MME_ZKZts_c
MatrixXd sample_MME_ZKZts_c(Map<MatrixXd> Y, MSpMat W, Map<VectorXd> tot_Eta_prec, Rcpp::List randomEffect_C_Choleskys, Map<MatrixXd> h2s, Rcpp::IntegerVector h2s_index, Map<MatrixXd> randn_theta, Map<MatrixXd> randn_e, int grainSize);
RcppExport SEXP BSFG_sample_MME_ZKZts_c(SEXP YSEXP, SEXP WSEXP, SEXP tot_Eta_precSEXP, SEXP randomEffect_C_CholeskysSEXP, SEXP h2sSEXP, SEXP h2s_indexSEXP, SEXP randn_thetaSEXP, SEXP randn_eSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Y(YSEXP);
    Rcpp::traits::input_parameter< MSpMat >::type W(WSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type randomEffect_C_Choleskys(randomEffect_C_CholeskysSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type h2s(h2sSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type h2s_index(h2s_indexSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randn_theta(randn_thetaSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type randn_e(randn_eSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_MME_ZKZts_c(Y, W, tot_Eta_prec, randomEffect_C_Choleskys, h2s, h2s_index, randn_theta, randn_e, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// tot_prec_scores
VectorXd tot_prec_scores(Map<MatrixXd> Y, Rcpp::List Sigma_Choleskys, Rcpp::IntegerVector h2s_index, int grainSize);
RcppExport SEXP BSFG_tot_prec_scores(SEXP YSEXP, SEXP Sigma_CholeskysSEXP, SEXP h2s_indexSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type Sigma_Choleskys(Sigma_CholeskysSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type h2s_index(h2s_indexSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(tot_prec_scores(Y, Sigma_Choleskys, h2s_index, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// log_p_h2s
MatrixXd log_p_h2s(Map<MatrixXd> Y, Map<VectorXd> tot_Eta_prec, Rcpp::List Sigma_Choleskys, Map<VectorXd> discrete_priors, int grainSize);
RcppExport SEXP BSFG_log_p_h2s(SEXP YSEXP, SEXP tot_Eta_precSEXP, SEXP Sigma_CholeskysSEXP, SEXP discrete_priorsSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type Sigma_Choleskys(Sigma_CholeskysSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type discrete_priors(discrete_priorsSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(log_p_h2s(Y, tot_Eta_prec, Sigma_Choleskys, discrete_priors, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// sample_h2s
Rcpp::IntegerVector sample_h2s(Map<ArrayXXd> log_ps, Map<VectorXd> rs, int grainSize);
RcppExport SEXP BSFG_sample_h2s(SEXP log_psSEXP, SEXP rsSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<ArrayXXd> >::type log_ps(log_psSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type rs(rsSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_h2s(log_ps, rs, grainSize));
    return rcpp_result_gen;
END_RCPP
}
// sample_h2s_discrete_MH_c
Rcpp::IntegerVector sample_h2s_discrete_MH_c(Map<MatrixXd> Y, Map<VectorXd> tot_Eta_prec, Map<VectorXd> discrete_priors, Rcpp::IntegerVector h2_index, Map<MatrixXd> h2s_matrix, Rcpp::List Sigma_Choleskys, Map<VectorXd> r_draws, double step_size, int grainSize);
RcppExport SEXP BSFG_sample_h2s_discrete_MH_c(SEXP YSEXP, SEXP tot_Eta_precSEXP, SEXP discrete_priorsSEXP, SEXP h2_indexSEXP, SEXP h2s_matrixSEXP, SEXP Sigma_CholeskysSEXP, SEXP r_drawsSEXP, SEXP step_sizeSEXP, SEXP grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type tot_Eta_prec(tot_Eta_precSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type discrete_priors(discrete_priorsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type h2_index(h2_indexSEXP);
    Rcpp::traits::input_parameter< Map<MatrixXd> >::type h2s_matrix(h2s_matrixSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type Sigma_Choleskys(Sigma_CholeskysSEXP);
    Rcpp::traits::input_parameter< Map<VectorXd> >::type r_draws(r_drawsSEXP);
    Rcpp::traits::input_parameter< double >::type step_size(step_sizeSEXP);
    Rcpp::traits::input_parameter< int >::type grainSize(grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_h2s_discrete_MH_c(Y, tot_Eta_prec, discrete_priors, h2_index, h2s_matrix, Sigma_Choleskys, r_draws, step_size, grainSize));
    return rcpp_result_gen;
END_RCPP
}
