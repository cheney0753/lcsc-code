#pragma once

#include "rng.hpp"
#include <cstdint>

namespace lcsc {

class lcrng : public rng_engine {
  public:
    uint64_t next() override;
};

} // namespace lcsc
