#pragma once

#include "rng.hpp"
#include <cstdint>

namespace lcsc {

class lcrng : public rng_engine {
  public:
    uint64_t next() override;
    uint64_t max() override {
        return m_;
    }
    uint64_t  min() override {
        return c_;
    }
    uint64_t next_schrage();
  private:
    // Default: Park-Miller
    uint64_t a_ = 16807;
    uint64_t c_ = 0;
    uint64_t x_ = 123;
    uint64_t m_ = (1<<31)-1;
    uint64_t q_ = m_ / a_;
    uint64_t r_ = m_ % a_;

};

} // namespace lcsc
