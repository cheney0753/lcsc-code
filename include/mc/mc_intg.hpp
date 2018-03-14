//
// Created by zhong on 14-3-18.
//

#pragma once

#include <cstdint>
#include <functional>
#include "rng/distributions.hpp"
#include "rng/mt19937.hpp"
namespace lcsc{

class mc_intg{

    public:
    mc_intg(std::function< double (double)> f): f_(f) {}; // constructor
        double integrate_hm( double a = 0.0, double b  =1.0,  uint64_t N = 10000 ); // N is the number of samples
        double integrate_ss( double a = 0.0, double b  =1.0,  uint64_t N = 10000 ); // N is the number of samples

    private:
        std::function< double ( double ) > f_ ; // the function f()
};

}