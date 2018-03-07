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
    class hist_cont{
    public:
        hist_cont(distribution_cont & dist, uint64_t N = 10000, double precision = 1.0): N_(N) {
            for (int i = 0; i < N_; ++i) {
                ++ hist_map_[ std::floor( dist() / precision) * precision];
            }

            std::cout << "A histogram of "<< N_ << " samples has been generated. \n";
        }

        void plot(uint64_t star_width);

        uint64_t get_N();

        const  std::map<double, uint64_t > & get_hist_map(); //  the compilation, implicit cast like double(int)

    private:
        uint64_t    N_;
        std::map <double, uint64_t> hist_map_;

    };


    // A class to generate a histogram of samples and provide the plot function
    class hist_disc{
    public:
        hist_disc(distribution_disc & dist, uint64_t N = 10000, uint64_t bin = 1 ): N_(N) {

            if(bin < 1){
                std::cerr<< "The bin number should be an integer larger than 1.";
            }

            if( bin != 1){
                for (int i = 0; i < N_; ++i) {
                    ++hist_map_[(dist() / bin) * bin];
                }
            } else {
                for (int i = 0; i < N_; ++i) {
                    ++ hist_map_[ dist() ];
                }
            }

            std::cout << "A histogram of "<< N_ << " samples has been generated. \n";

        }

        void plot(uint64_t star_width);

        uint64_t get_N();

        const  std::map<double, uint64_t > & get_hist_map(); //  the compilation, implicit cast like double(int)

    private:
        uint64_t    N_;
        std::map <double, uint64_t> hist_map_;

    };


    // A class to compute the chi-square value
    class chi_square {

    public: chi_square(){};

    };

}