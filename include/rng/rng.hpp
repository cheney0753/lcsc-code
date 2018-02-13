#pragma once

#include <cstdint>

namespace lcsc {

class rng_engine {
  public:
    virtual uint64_t next() = 0;
};

} // namespace lcsc
