#include <iostream>

#include "lcsc.hpp"
#include <map>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>


int main() {
    auto r = lcsc::lcrng();
//    for (int i = 0; i < 100; ++i) {
//        std::cout << r.next() << "\n";
//    }
//
//    std::cout << r.max() << " max \n";
//    for (int i = 0; i < 100; ++i) {
//        std::cout << r.next_schrage() << "\n";
//    }

    auto d_unif_int = lcsc::uniform_int_distribution( r, 0, 100);

//    auto d = lcsc::uniform_real_distribution( r);

    auto d_normal = lcsc::normal_distribution(r,  1.0f, 2.0f, -6.0f, 6.0f);

    auto hist_normal = lcsc::hist(d_normal, 100000, 0.1f);
    hist_normal.plot(50);


    auto hist_unif_int = lcsc::hist(d_unif_int, 100000, 1.0f);
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
