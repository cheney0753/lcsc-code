#pragma once

#include "rng.hpp"
#include <random>

namespace lcsc{

    class mt19937_rng: public rng_engine{
    public:
        mt19937_rng(uint64_t seed): x_(seed){};
        uint64_t next() override;
        uint64_t max() override {
            return std::numeric_limits<uint32_t>::max();
        }
        uint64_t  min() override {
            return std::numeric_limits<uint32_t>::min();
        }

    private:
        uint64_t x_;
//        define an engine here ?
    };
}