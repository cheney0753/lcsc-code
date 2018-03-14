//
// Created by zhong on 3/7/18.
//

#include "rng/mt19937.hpp"

namespace lcsc{

    uint64_t mt19937_rng::next() {
        x_ = stdmt();
        return x_;

    }

}