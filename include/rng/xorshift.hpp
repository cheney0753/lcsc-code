#pragma once

#include "rng.hpp"
#include <cstdint>
#include <limits>
namespace lcsc{

    class xorshift:public rng_engine {
    public:
        xorshift(uint64_t seed): x_(seed) {};
        uint64_t next() override;
        uint64_t max() override {
            return std::numeric_limits<uint32_t>::max();
        } //
        uint64_t  min() override {
            return std::numeric_limits<uint32_t>::min();
        }


    private:
        uint32_t x_;
    }; // an uint32_t xorshift rng engine
}