//
// Created by zhong on 28-2-18.
//

#include "test/test.hpp"
#include <iomanip>
namespace lcsc{

    uint64_t hist_cont::get_N() {return N_;}

    const  std::map<double, uint64_t > & hist_cont::get_hist_map() { return hist_map_; }

    void hist_cont::plot( uint64_t star_width = 50){

        std::cout << "Plot the histogram for "<< N_
                  << " samples, with each * means "<< star_width << " samples. \n";

        for(auto p : hist_map_) {
            std::cout << std::setw(2)
                      << p.first  << ' ' << std::string(p.second/star_width, '*') << '\n';
        }
    }



    uint64_t hist_disc::get_N() {return N_;}

    const  std::map<double, uint64_t > & hist_disc::get_hist_map() { return hist_map_; }

    void hist_disc::plot( uint64_t star_width = 50){

        std::cout << "Plot the histogram for "<< N_
                  << " samples, with each * means "<< star_width << " samples. \n";

        for(auto p : hist_map_) {
            std::cout << std::setw(2)
                      << p.first  << ' ' << std::string(p.second/star_width, '*') << '\n';
        }
    }



}//namespace lcsc