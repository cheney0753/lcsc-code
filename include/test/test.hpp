//
// Created by zhong on 21-2-18.
//
#pragma once

#include <cstdint>
#include "lcsc.hpp"
#include <iostream>
#include <map>
namespace lcsc{

    // A class to generate a histogram of samples and provide the plot function
    class hist {

    public:
        hist(auto & dist, uint64_t N, double scaling = 1.0);
        void plot(uint64_t star_width);
        double get_N();
        const & std::map<double, int> get_hist_map(); //  the compilation, implicit cast like double(int)

    private:
        uint64_t    N_;
        double      scaling_;
        std::map <double, int> hist_map_{};

    };

    // A class to compute the chi-square value
    class chi_square {

    public: chi_square(){};

    };

}