#pragma once

#include "rng.hpp"
#include <random>

namespace lcsc{

    class mt19937_rng: public rng_engine{
    public:
        mt19937_rng(uint64_t seed): stdmt(seed), x_(seed){};
        uint64_t next() override;
        uint64_t max() override {
            return stdmt.max();
        }
        uint64_t  min() override {
            return stdmt.min();
        }

    private:
        std::mt19937 stdmt; // declare the stdmt object and initialize it in the constructor.
        uint64_t x_;
//        define an engine here ?
    };
}