//
// Created by zhong on 14-3-18.
//
#include <iostream>
#include "mc/mc_intg.hpp"
#include "utils/utils.hpp"
#include "rng/distributions.hpp"
namespace lcsc{

    double mc_intg::integrate_hm(rng_engine & r,  const double & a,  const double &  b, const uint64_t & N ) {

        if ( b < a){
            throw std::invalid_argument( "b must be larger than a!");
        }
        if (N < 1) throw std::invalid_argument("N must be larger than 1!");

        // find the maximum of f() in [a, b]
        double max_f = 0;
        double min_f = 0;

        auto boundary_f = utils::findMinMax( f_, a, b, N);

        auto dist = uniform_real_distribution(r, a,  b);
        auto dist_f = uniform_real_distribution(r, boundary_f["min"], boundary_f["max"]);

        uint64_t n_intg = 0;
        for( uint64_t i = 0; i < N; i++){

            double x = dist();
            double y = dist_f();

            if ( y < f_(x) ) n_intg ++;
        }

        return double_t(n_intg)/double(N);
    } // hit and miss method

    double mc_intg::integrate_ss( rng_engine & r,  const double & a,  const double &  b, const uint64_t & N ) {

        if ( b < a){
            throw std::invalid_argument( "b must be larger than a!");
        }
        if (N < 1) throw std::invalid_argument("N must be larger than 1!");

        auto dist = uniform_real_distribution(r, a, b);

        double sum_f = 0.0;

        for( uint64_t i=0 ; i < N; i++){
            double x = dist();
            sum_f += f_(x);

        }
        return double((b-a)*sum_f)/double(N);
    } // ss method

}
