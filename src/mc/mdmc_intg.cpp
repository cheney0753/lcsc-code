//
// Created by zhong on 21-3-18.
//
#include <iostream>
#include <exception>
#include "mc/mdmc_intg.hpp"
#include "utils/utils.hpp"
#include "rng/distributions.hpp"


// in the cpp file, never include lcsc.hpp, because it is for the users
// in the cpp file, include the exact header files for what is needed
namespace lcsc{

    double mdmc_intg::integrate_hm(rng_engine & r, const std::vector<double> & a_s, const std::vector<double> & b_s, const uint64_t & N ){

        if (a_s.size() !=  b_s.size()  ) throw std::invalid_argument("Size of a_s and b_s must be the same.");

        for (int i = 0; i < a_s.size(); i++){
            if (b_s[i] < a_s[i]) throw std::invalid_argument( "All elements in b_s must be larger than a_s.");
        }

        if (N < 1) throw std::invalid_argument("N must be larger than 1!");


        // find the minimum and maximum
        auto boundary_f = utils::findMinMaxVec( f_, a_s, b_s, N);

        auto dist = uniform_real_distribution(r); // generate a [0.0 1.0] uniform distriubiton
        auto dist_f = uniform_real_distribution(r);//, double(boundary_f["min"]), boundary_f["max"]);

//        std::cout<<boundary_f["max"]<<std::endl;
        std::vector<double> rand_x = a_s;

        uint64_t n_intg = 0;

        for (int n = 0; n < N; n++){

            for (int d = 0; d < a_s.size() ; d++){
                rand_x[d] = dist()* (b_s[d] - a_s[d]) + a_s[d];
            }
            auto y = dist_f();
//            cout<<f_( rand_x )<<endl;
//            cout<<y<<endl;
            if ( f_( rand_x ) >y ) n_intg++;

        }

        return double_t(n_intg)/double(N);


    }


    double mdmc_intg::integrate_ss(rng_engine & r, const std::vector<double> & a_s, const std::vector<double> & b_s, const uint64_t & N ){

        if (a_s.size() !=  b_s.size()  ) throw std::invalid_argument("Size of a_s and b_s must be the same.");

        for (int i = 0; i < a_s.size(); i++){
            if (b_s[i] < a_s[i]) throw std::invalid_argument( "All elements in b_s must be larger than a_s.");
        }

        if (N < 1) throw std::invalid_argument("N must be larger than 1!");


        // find the minimum and maximum
        auto boundary_f = utils::findMinMaxVec( f_, a_s, b_s, N);

//        std::cout<<boundary_f["max"]<<std::endl;
        auto dist_f = uniform_real_distribution(r);
        auto seq_random = rng_seq( dist_f, a_s, b_s);

        double sum_f = 0.0;
        for (int n = 0; n < N; n++){

            seq_random.next();

            sum_f +=  f_( seq_random.rand_x );

        }

        return sum_f/double(N);
    }

    void rng_seq::next(){
        for (int d = 0; d < a_s_.size() ; d++) {
            rand_x[d] = dist_() * (b_s_[d] - a_s_[d]) + a_s_[d];
        }
    }

}