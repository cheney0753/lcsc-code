#include "rng/distributions.hpp"
#include <iostream>


namespace lcsc{


    uint64_t uniform_int_distribution::operator()()  {
    return engine_.next() * (max_ - min_) / double(engine_.max()) + min_;
}

    double uniform_int_distribution::pdf(uint64_t x) {
        if (x <= max_ & x >= min_){
            return 1.0f/(max_-min_);
        } else{
            return 0.0f;
        }

    }

    double uniform_real_distribution::operator()() {
        return double(engine_.next())  * (max_ - min_) / double(engine_.max()) + min_;
        };

    double uniform_real_distribution::pdf(double x) {
        if (x <= max_ & x >= min_){
            return 1.0f/(max_-min_);
        } else{
            return 0.0f;
        }
    }

    double normal_distribution::operator()() {
        auto d_unif = uniform_real_distribution( engine_, 0.0f,  1.0f);
        double omega = d_unif();
        double mu = d_unif();

        double x = omega * (max_ - min_) + min_;

        if(mu * M_ <= pdf(x)){
            return x;
        }
        else{
            return normal_distribution::operator()();
        }
    };

    double normal_distribution::pdf(double x){
        return 1 / sqrt( 2 * M_PI ) / stddev_ * exp( -pow(x - mean_, 2.0)/ 2 / pow( stddev_, 2 ));

    }

    uint64_t poisson_distribution::operator()() {

        auto d_unif = uniform_real_distribution( engine_, 0.0f,  1.0f);
        auto d_unif_int = uniform_int_distribution(engine_, min_, max_);
        double mu = d_unif();
        uint64_t x = d_unif_int();

        if( x < 3* mean_ && mu * M_ <= pdf(x)){
            return x;
        }
        else{
            return poisson_distribution::operator()();
        }
    }

    double poisson_distribution::pdf(uint64_t k) {
        return exp(-mean_) * pow(mean_, k) / factorial(k);
    }
}

uint64_t factorial( uint64_t n ){
    if (n == 1 || n == 0){
        return 1;
    } else {
        return factorial( n -1 ) * n;
    }
}
