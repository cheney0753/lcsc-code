//
// Created by zhong on 21-3-18.
//

#pragma once
#include <cstdint>
#include <functional>
#include "rng/dist.hpp"
#include "rng/rng.hpp"
#include <vector>
#include <functional>
#include <stdexcept>
// in the header file, only include the headers used in the declaration
namespace lcsc{

//  the random sequence generator
    template <typename T>
    class rand_seq{
    public:
        virtual void next() = 0;
    };
//
    class rng_seq: public rand_seq<double>{
    public:
        rng_seq( distribution<double> & dist, const std::vector<double> & a_s, const std::vector<double> & b_s):
                dist_(dist), a_s_(a_s), b_s_(b_s), rand_x(a_s){};

        void next() override ;
        std::vector<double> rand_x;

    private:
        distribution<double> & dist_;
        std::vector<double> a_s_;
        std::vector<double> b_s_;
    }; // to generate a sequence of random numbers (for real numbers)

    class mdmc_intg{
    public:
        mdmc_intg( std::function< double ( std::vector<double> & )> f): f_(f) {}; // cannot use function as a reference
        double integrate_hm(rng_engine & r, const std::vector<double> & a_s, const std::vector<double> & b_s, const std::uint64_t & N =100000);
        double integrate_ss(rng_engine & r, const std::vector<double> & a_s, const std::vector<double> & b_s, const std::uint64_t & N = 100000);

    private:
        std::function< double ( std::vector<double> & ) >  f_;
    }; // multi-dimensional Monte Carlo simulation for integration


//    class halton_seq: public rand_seq<double>{
//    public:
//        halton_seq( int d){
//            d_ = d;
//            prime_seq_ =
//        };
//    private:
//        double pi_func(double p, std::vector<double> a_seq);
//        int d_;
//        std::vector<double> prime_seq_;
//    };
}