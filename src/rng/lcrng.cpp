#include "rng/lcrng.hpp"
namespace lcsc {

uint64_t lcrng::next() {


    x_ = (a_ * x_ + c_) % m_;
    return x_;
}

uint64_t  lcrng::next_schrage() {
    uint64_t b_ = a_ * (x_ % q_) - r_ * (x_ / q_);

    if(b_<0){
        x_ =  b_ + m_;
    }
    else{
        x_ =  b_;
    }

    return x_;
}
}
// namespace lcsc
