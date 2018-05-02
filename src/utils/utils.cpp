#include "utils/utils.hpp"
#include <iostream>
#include <cmath>
#include "rng/mt19937.hpp"
#include "rng/distributions.hpp"
namespace utils{


// find the max and min of one-dimensional function.
    std::map<std::string, double> findMinMax( std::function< double (double) > & f, const double & a, const double & b, const int & N){

        double max_f= 0.0,  min_f = 0.0;

        for(int i = 0; i < N; i++){

            if( f( i/(b-a) ) > max_f){
                max_f = f( i/(b-a));
            }

            if(f( i/(b-a) ) < min_f) {
                min_f = f(i/(b-a));
            }
        }

//        std::cout<< "min_f is " << min_f << std::endl;
//        std::cout<< "max_f is " << max_f << std::endl;

        std::map< std::string, double > max_min;
        max_min["max"] = max_f;
        max_min["min"] = min_f;

        return max_min;
    }

    // find the minimum and maximum values of a multi-dimensional function. return a map

    std::map<std::string, double> findMinMaxVec( std::function< double (std::vector<double> &) > f,
                                                 const std::vector<double> & a_s,const std::vector<double> & b_s, const uint64_t & N ){

        double max_f= 0.0,  min_f = 0.0;

        auto r = lcsc::mt19937_rng(123321);
        auto dist = lcsc::uniform_real_distribution(r, 0.0, 1.0);


        if (a_s.size() != b_s.size() ) throw std::invalid_argument("The size of a_s and b_s should be the same.");

        std::vector<double> rand_x = a_s;

        for(int i = 0; i < N; i++){
            // generate the random vector within the range of [a_s, b_s]
            for(int d =0; d< a_s.size(); d++){
                auto dd = dist();
                rand_x[d] = dd* (b_s[d]-a_s[d])+a_s[d];
            }

            if( f( rand_x ) > max_f){
                max_f = f( rand_x);
            }

            if(f( rand_x ) < min_f) {
                min_f = f(rand_x);
                }
        }

//
//        cout<< "min_f is " << min_f << endl;
//        cout<< "max_f is " << max_f << endl;

        std::map< std::string, double > max_min;
        max_min["max"] = max_f;
        max_min["min"] = min_f;

        return max_min;
    }

//    std::vector<int> generatePrimes(uint64_t d){
//
//        std::vector<int> primes;
//        uint64_t i= 0;
//        while (i < d){
//            // find a prime number
//            if (isPrime(i)){
//                primes.push_back(i);}
//            i++;
//        }
//
//        return primes;
//    }

} // namespace utils