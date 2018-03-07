#include <iostream>

#include "lcsc.hpp"
#include <map>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <rng/xorshift.hpp>
#include <random>
#include <rng/mt19937.hpp>

int main() {
//    auto r = lcsc::lcrng();
//    for (int i = 0; i < 100; ++i) {
//        std::cout << r.next() << "\n";
//    }
//
//    std::cout << r.max() << " max \n";
//    for (int i = 0; i < 100; ++i) {
//        std::cout << r.next_schrage() << "\n";
//    }
//    auto r = lcsc::lcrng( 9);
//    for (int i = 0; i < 100; ++i) {
//        std::cout << r.next() << "\n";
//    }
//
//    std::cout << r.max() << " max \n";

    // question, how to implment mt19937? !!!!!!!!!!!!
    auto r = lcsc::mt19937_rng(9);
    for (int i = 0; i < 100; ++i) {
        std::cout <<r.next() << "\n";
    }


    auto d_unif_int = lcsc::uniform_int_distribution( r, 0, 100);

    auto d = lcsc::uniform_real_distribution( r);

    auto d_normal = lcsc::normal_distribution(r,  1.0f, 1.0f, -1.0f, 6.0f);

    auto hist_normal = lcsc::hist_cont(d_normal, 1000000, 0.1);
    hist_normal.plot(500);


    auto hist_unif_int = lcsc::hist_disc(d_unif_int, 100000, 1.0f);
    hist_unif_int.plot(50);


    // compute the chi-square value

    std::cout << "The pdf of uniform_int_dist is " << d_unif_int.pdf(50) << std::endl;

    double  chisq_unif_int;

    std::vector<int> v_vec;

    for(auto p : hist_unif_int.get_hist_map()){
        double Ei = hist_unif_int.get_N() * d_unif_int.pdf( p.first );

        v_vec.push_back( pow(p.second - Ei, 2) / Ei);
    }
}
