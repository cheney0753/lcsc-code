//
// Created by zhong on 14-3-18.
//

#pragma once

#include <cstdint>
#include <functional>
#include <vector>
#include <stdexcept>
#include "rng/rng.hpp"
namespace lcsc{

class mc_intg{

    public:
    mc_intg(std::function< double (double)> f): f_(f) {}; // constructor
        double integrate_hm(rng_engine & r,  const double & a,  const double &  b, const uint64_t & N  = 10000); // N is the number of samples
        double integrate_ss( rng_engine & r,  const double & a,  const double &  b, const uint64_t & N  = 10000); // N is the number of samples
    private:
        std::function< double ( double ) > f_ ; // the function f()
//        std::function< double ( std::vector<double> ) > f_md_;
};

}