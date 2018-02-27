#include <iostream>

#include "lcsc.hpp"
#include <map>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
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

//    auto d = lcsc::uniform_int_distribution( r);
    auto d = lcsc::uniform_real_distribution( r);

    for (int i = 0; i < 100; ++i) {
        std::cout << d() << "\n";
    }


    // plot histogram
    std::map <int, int> hist{};
    for (int i = 0; i < 1000000; ++i) {
        ++ hist[std::floor(40.0f *d())];
    }

    for(auto p : hist) {
        std::cout << std::setw(2)
                  << p.first << ' ' << std::string(p.second/500, '*') << '\n';
    }

    auto d_normal = lcsc::normal_distribution(r,  1.0f, 2.0f, -6.0f, 6.0f);

    double scl = 10.0f;

    std::map <int, int> hist_normal{};
    for (int i = 0; i < 1000000; ++i) {
        ++ hist_normal[std::floor( scl * d_normal())];
    }

    for(auto p : hist_normal) {
        std::cout << std::setw(2)
                  << p.first / scl << ' ' << std::string(p.second/500, '*') << '\n';
    }

}
