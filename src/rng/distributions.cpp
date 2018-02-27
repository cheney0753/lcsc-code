#include "rng/distributions.hpp"
#include <iostream>

namespace lcsc{


    uint64_t uniform_int_distribution::operator()()  {
    return engine_.next() * (max_ - min_) / engine_.max();
}


    double uniform_real_distribution::operator()() {
        return double(engine_.next())  * (max_ - min_) / ( engine_.max() );
        };

    double normal_distribution::operator()() {
        auto d_unif = lcsc::uniform_real_distribution( engine_, 0.0f,  1.0f);


        double omega = d_unif();
        double mu = d_unif();

        double x = omega * ( max_ - min_ ) + min_;

        if ( mu * M_ <= pdf ( x ) ) {
            return x;
        } else{
            return normal_distribution::operator()();
        }

        };
    double normal_distribution::pdf(double x){
        return 1 / sqrt( 2 * M_PI ) / stddev_ * exp( -pow(x - mean_, 2.0)/ 2 / pow( stddev_, 2 ));

    }
}