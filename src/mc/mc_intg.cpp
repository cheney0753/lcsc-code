//
// Created by zhong on 14-3-18.
//

#include "mc/mc_intg.hpp"
#include <iostream>

namespace lcsc{
//    class mc_HoM{
//    public:
//        mc_HoM(std::function< double (double)> f):
//                f_(f) {}; // constructor
//        double integrate( double a = 0, double b = 1,  uint64_t N = 10000); // N is the number of samples
//
//    private:
//        std::function< double ( double ) > f_ ; // the function f()
//    };

    double mc_intg::integrate_hm( double a, double b,  uint64_t N ) {

        if ( b < a){
            throw "b must be larger than a!";
        }
        if (N < 1) throw "N must be larger than 1!";

        // find the maximum of f() in [a, b]
        double max_f = 0;
        double min_f = 0;

        for( double i = 0; i < N; i++){

            if( f_( i/(b-a) ) > max_f){
                max_f = f_( i/(b-a));
            }

            if(f_( i/(b-a) ) < min_f) {
                min_f = f_(i/(b-a));
            }
        }
        auto r = mt19937_rng(12321);
        auto dist = uniform_real_distribution(r, a,  b);
        auto dist_f = uniform_real_distribution(r, min_f, max_f);

        std::cout<< "min_f is " << min_f << std::endl;
        std::cout<< "max_f is " << max_f << std::endl;

        uint64_t n_intg = 0;
        for( uint64_t i = 0; i < N; i++){

            double x = dist();
            double y = dist_f();

            if ( y < f_(x) ) n_intg ++;
        }

        return double_t(n_intg)/double(N);
    }

    double mc_intg::integrate_ss(double a, double b, uint64_t N) {
        if ( b < a){
            throw "b must be larger than a!";
        }
        if (N < 1) throw "N must be larger than 1!";

        // find the maximum of f() in [a, b]
        double max_f = 0;
        double min_f = 0;

        for( double i = 0; i < N; i++){

            if( f_( i/(b-a) ) > max_f){
                max_f = f_( i/(b-a));
            }

            if(f_( i/(b-a) ) < min_f) {
                min_f = f_(i/(b-a));
            }
        }


    }

}
