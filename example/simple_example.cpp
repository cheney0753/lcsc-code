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

    auto d = lcsc::uniform_int_distribution( r, 0, 100);

//    auto d = lcsc::uniform_real_distribution( r);

    for (int i = 0; i < 100; ++i) {
        std::cout << d() << "\n";
    }

    double scl = 10.0f;


    // plot histogram
    std::map <int, int> hist{};
    for (int i = 0; i < 1000000; ++i) {
        ++ hist[std::floor(scl *d())];
    }

    for(auto p : hist) {
        std::cout << std::setw(2)
                  << p.first/scl << ' ' << std::string(p.second/500, '*') << '\n';
    }

    auto d_normal = lcsc::normal_distribution(r,  1.0f, 2.0f, -6.0f, 6.0f);


    std::map <int, int> hist_normal{};
    for (int i = 0; i < 1000000; ++i) {
        ++ hist_normal[std::floor( scl * d_normal())];
    }

    for(auto p : hist_normal) {
        std::cout << std::setw(2)
                  << p.first / scl << ' ' << std::string(p.second/500, '*') << '\n';
    }


    auto d_poisson = lcsc::poisson_distribution(r, 1, 0, 20);


    std::map <int, int> hist_poisson{};
    for (int i = 0; i < 100000; ++i) {
        ++ hist_poisson[std::floor( scl * d_poisson())];
    }

    for(auto p : hist_poisson) {
        std::cout << std::setw(2)
                  << p.first / scl << ' ' << std::string(p.second/500, '*') << '\n';
    }

}
