#pragma once

#include "rng.hpp"
#include <cstdint>

namespace lcsc {

class uniform_int_distribution {
  public:
    uniform_int_distribution(rng_engine& engine, uint64_t min = 0,
                             uint64_t max = 1000): engine_(engine), min_(min), max_(max){};
    uint64_t operator ()();

  private:
    rng_engine& engine_;
    uint64_t min_;
    uint64_t max_;
};

class uniform_real_distribution {
  public:
    uniform_real_distribution(rng_engine& engine, double min = 0.0f,
                              double max = 1.0f): engine_(engine), min_(min), max_(max) {};
    double operator()();

  private:
    rng_engine& engine_;
    uint64_t min_;
    uint64_t max_;
};

class normal_distribution {
  public:
    normal_distribution(rng_engine& engine, double mean = 0.0f, double stddev = 1.0f):
            engine_(engine), mean_(mean), stddev_(stddev) {};
    double operator()();
  private:
    double pdf();
    rng_engine& engine_;
    double mean_;
    double stdv_;
};

class poisson_distribution {
public:
    poisson_distribution(rng_engine& engine, uint64_t mean = 0.0f):
            engine_(engine), mean_(mean) {};
    uint64_t operator()();

private:
    rng_engine& engine_;
    uint64_t mean_;
};
class bernoulli_distribution {};
class discrete_distribution {};

} // namespace lcsc
