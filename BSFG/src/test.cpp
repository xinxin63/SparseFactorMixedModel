#include <math.h>
#include <iostream>
#include "BSFG_types.h"

// [[Rcpp::depends(RcppEigen)]]
using namespace Eigen;
using namespace RcppParallel;

//
// // [[Rcpp::export()]]
// MatrixXd sample_randomEffects_parallel_sparse_c_Eigen2 (
//     Map<MatrixXd> Eta,
//     MSpMat Z,
//     Map<ArrayXd> tot_prec,
//     Map<ArrayXd> h2,
//     List invert_aZZt_Kinv,
//     Map<ArrayXXd> randn_draws,
//     int grainSize) {
//   //samples genetic effects on factors (F_a) conditional on the factor scores F:
//   // F_i = F_{a_i} + E_i, E_i~N(0,s2*(1-h2)*I) for each latent trait i
//   // U_i = zeros(r,1) if h2_i = 0
//   // it is assumed that s2 = 1 because this scaling factor is absorbed in
//   // Lambda
//   // invert_aZZt_Kinv has parameters to diagonalize a*Z*Z' + b*K for fast
//   // inversion:
//
//   ArrayXd a_prec = tot_prec / h2;
//   ArrayXd e_prec = tot_prec / (1.0-h2);
//
//   SpMat U = as<MSpMat>(invert_aZZt_Kinv["U"]);
//   VectorXd s1 = as<VectorXd>(invert_aZZt_Kinv["s1"]);
//   VectorXd s2 = as<VectorXd>(invert_aZZt_Kinv["s2"]);
//
//   int p = Eta.cols();
//   int r = Z.cols();
//   // MatrixXd b = U.transpose() * Z.transpose() * (Eta * e_prec.matrix().asDiagonal());
//   MatrixXd b = (Z*U).transpose() * (Eta * e_prec.matrix().asDiagonal());
//
//   // MatrixXd z = randn(r,p);
//
//   MatrixXd effects(r,p);
//   Rcout << r << " " << p << std::endl;
//   Rcout << a_prec(p-1) << std::endl;
//   Rcout << e_prec(p-1) << std::endl;
//   Rcout << b.rows() << " " << b.cols() << std::endl;
//
//   struct sampleColumn : public Worker {
//     VectorXd s1, s2;
//     ArrayXd a_prec, e_prec;
//     SpMat U;
//     MatrixXd b;
//     ArrayXXd randn_draws;
//     MatrixXd &effects;
//
//     sampleColumn(VectorXd s1, VectorXd s2, ArrayXd a_prec, ArrayXd e_prec, SpMat U, MatrixXd b, ArrayXXd randn_draws, MatrixXd &effects)
//       : s1(s1), s2(s2), a_prec(a_prec), e_prec(e_prec), U(U), b(b), randn_draws(randn_draws), effects(effects) {}
//
//     void operator()(std::size_t begin, std::size_t end) {
//       for(std::size_t j = begin; j < end; j++){
//         ArrayXd d = s2*a_prec(j) + s1*e_prec(j);
//         ArrayXd mlam = b.col(j).array() / d;
//         effects.col(j) = U * (mlam + randn_draws.col(j) / sqrt(d)).matrix();
//       }
//     }
//   };
//   for(int j = 0; j < p; j++){
//     ArrayXd d = s2*a_prec(j) + s1*e_prec(j);
//     Rcout << j << d.size() <<  std::endl;
//     ArrayXd mlam = b.col(j).array() / d;
//     Rcout << mlam + randn_draws.col(j) / sqrt(d) << std::endl;
//     effects.col(j) = U * (mlam + randn_draws.col(j) / sqrt(d)).matrix();
//   }
//
//   sampleColumn sampler(s1, s2, a_prec, e_prec, U, b, randn_draws, effects);
//   RcppParallel::parallelFor(0,p,sampler,grainSize);
//
//   return(effects);
// }

// [[Rcpp::export()]]
VectorXd tot_prec_scores_withX_c2 (
    Map<MatrixXd> UtEta,
    Map<MatrixXd> B_F,
    Map<VectorXd> h2,
    Map<VectorXd> s,
    Map<MatrixXd> prec_B_F
) {

  int p = UtEta.cols();

  VectorXd scores(p);

  for(int i = 0; i < p; i++){
    ArrayXd Sigma_sqrt = sqrt(h2(i) * s.array() + (1.0 - h2(i)));
    VectorXd SiUtEta_i = UtEta.col(i).array() / Sigma_sqrt;
    VectorXd b_std = B_F.col(i).cwiseProduct(prec_B_F.cwiseSqrt());
    scores(i) = SiUtEta_i.dot(SiUtEta_i) + b_std.dot(b_std);
  }
  return scores;
}
