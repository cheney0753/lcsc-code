//
// Created by zhong on 21-2-18.
//
#pragma once

#include <cstdint>
#include "lcsc.hpp"
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

namespace lcsc{

    // define a simple test class to test the mean ans standard deviation values of a distribution.e
    template <typename T>
    class test_dist{
    public:
        test_dist( distribution<T> & dist): dist_(dist) {}

        double test_mean(uint64_t N = 10000) {
            double sum_ = 0.0;
            for (int i = 0; i < N; i++) {
                sum_ += dist_();
            }

            return sum_ / double(N);
        }

        double test_stdv(uint64_t N = 10000){
            double mean_ = test_dist::test_stdv(N);

            double sum_diff_ = 0.0;
            for(int i =0; i < N; i++){
                auto d = double(dist_());
                sum_diff_ += ( d - mean_) * (d-mean_);
            }

            return pow( sum_diff_/double(N), 0.5);
        }

    private:
        distribution<T> & dist_ ;
    };

    // A class to generate a histogram of samples and provide the plot function
    class hist_cont{
    public:
        hist_cont(distribution<double > & dist, uint64_t N = 10000, double precision = 1.0): N_(N) {
            for (int i = 0; i < N_; ++i) {
                ++ hist_map_[ floor( dist() / precision) * precision];
            }

            cout << N_ << " samples has been generated. \n";
        }

        void plot(uint64_t star_width);

        uint64_t get_N();

        const  map<double, uint64_t > & get_hist_map(); //  the compilation, implicit cast like double(int)

    private:
        uint64_t    N_;
        map <double, uint64_t> hist_map_;

    };


    // A class to generate a histogram of samples and provide the plot function
    class hist_disc{
    public:
        hist_disc(distribution<uint64_t> & dist, uint64_t N = 10000, uint64_t bin = 1 ): N_(N) {

            if(bin < 1){
                cerr<< "The bin number should be an integer larger than 1.";
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

            cout <<  N_ << " samples has been generated. \n";

        }

        void plot(uint64_t star_width);

        uint64_t get_N();

        const  map<double, uint64_t > & get_hist_map(); //  the compilation, implicit cast like double(int)

    private:
        uint64_t    N_;
        map <double, uint64_t> hist_map_;

    };


    // A class to compute the chi-square value
    class chi_square {

    public: chi_square(){};

    };

}