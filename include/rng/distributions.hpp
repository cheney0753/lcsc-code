#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "rng.hpp"
#include <cstdint>

namespace lcsc {

class uniform_int_distribution {
  public:
    uniform_int_distribution(rng_engine& engine, uint64_t min = 0,
                             uint64_t max = 1000):
            engine_(engine), min_(min), max_(max){};

    uint64_t operator ()();

  private:
    rng_engine& engine_;
    uint64_t min_;
    uint64_t max_;
};

class uniform_real_distribution {
  public:
    uniform_real_distribution(rng_engine& engine, double min = 0.0f,
                              double max = 1.0f):
            engine_(engine), min_(min), max_(max) {};
    double operator()();

  private:
    rng_engine& engine_;
    uint64_t min_;
    uint64_t max_;
};

class normal_distribution {
  public:
    normal_distribution(rng_engine& engine, double mean = 0.0f, double stddev = 1.0f,
                        double min = 0.0f, double max = 1.0f):
            engine_(engine), mean_(mean), stddev_(stddev), min_(min), max_(max) {};

    double operator()();

  private:
    double pdf(double x);
    rng_engine& engine_;
    double mean_;
    double stddev_;
    double min_;
    double max_;
    double M_ =  1 / sqrt( 2 * M_PI ) / stddev_;
};

class poisson_distribution {
public:
    poisson_distribution(rng_engine& engine, double mean = 0, uint64_t min = 0,
                         uint64_t max = 100):
            engine_(engine), mean_(mean), min_(min), max_(max) {};
    uint64_t operator()();

private:
    double pdf( double x);
    rng_engine& engine_;
    double mean_;
    uint64_t max_;
    uint64_t min_;
    double M_ = fmax( pdf(floor(mean_)), pdf(ceil(mean_)) );

};
class bernoulli_distribution {};
class discrete_distribution {};

} // namespace lcsc
