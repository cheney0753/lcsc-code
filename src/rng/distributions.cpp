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

    };
}