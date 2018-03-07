//
// Created by zhong on 3/7/18.
//

#include "rng/xorshift.hpp"

namespace lcsc{

    uint64_t xorshift::next() {


        x_ ^= x_ << 13;
        x_ ^= x_ >> 17;
        x_^= x_ << 5;

        return x_;
    }

}