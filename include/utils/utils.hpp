#pragma once

#include <cstdint>

#include <map>
#include <string>
#include <functional>
#include <vector>


namespace utils {

    std::map<std::string, double> findMinMax( std::function< double (double) > & f, const double & a, const double & b, const int & N = 10000);
    std::map<std::string, double> findMinMaxVec( std::function< double (std::vector<double> &) > f, const std::vector<double> & a_s,
                                                 const std::vector<double> & b_s, const uint64_t & N = 10000);
    std::vector<int> generatePrimes(uint64_t d);
//    bool isPrime(uint64_t num):
} //namespace utils

//
//    template <typename T>

//    void test_distributions( lcsc::uniform_real_distribution & dist, uint64_t sampling_number){
//
//        cout<< "Testing the distribution..."<< endl;
//
//        auto test_case = lcsc::test_dist<T>(dist);
//
//        cout<< 'Tested mean value is: ' << test_case.test_mean(sampling_number) << endl;
//
//        cout<< 'Tested standard deviation value is: ' << test_case.test_stdv(sampling_number) << endl;
//
//        return 0;
//    }