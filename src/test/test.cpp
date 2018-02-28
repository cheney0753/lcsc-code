//
// Created by zhong on 28-2-18.
//

#include "test/test.hpp"
#include <iostream>
#include <iomanip>
namespace lcsc{

    hist::hist(auto & dist, uint64_t N, double scaling):
            N_(N), scaling_(scaling) {

        for (int i = 0; i < N_; ++i) {
            ++ hist_map_[ std::floor( dist() / scaling) * scaling];
        }

        std::cout << "A histogram of "<< N_ << " samples has been generated. \n";
    }

    double hist::get_N() {return N_;}
    const & std::map<double, int> hist::get_hist_map() { return hist_map_; }

    void hist::plot( uint64_t star_width = 50){

        std::cout << "Plot the histogram for "<< N_
                  << " samples, with each * means "<< star_width << " samples. \n";

        for(auto p : hist_map_) {
            std::cout << std::setw(2)
                      << p.first  << ' ' << std::string(p.second/star_width, '*') << '\n';
        }
    }


}//namespace lcsc