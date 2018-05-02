#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "rng.hpp"
#include "utils/utils.hpp"
#include <cstdint>
#include "dist.hpp"

namespace lcsc {


class uniform_int_distribution: public distribution<uint64_t>  {
  public:
    uniform_int_distribution(rng_engine& engine, uint64_t min = 0,
                             uint64_t max = 1000):
            engine_(engine), min_(min), max_(max){};

    uint64_t operator()() override;
    double pdf(uint64_t x) override;

  private:
    rng_engine& engine_;
    uint64_t min_;
    uint64_t max_;
};

class poisson_distribution:public distribution<uint64_t > {
    public:
        poisson_distribution(rng_engine& engine, double mean = 0, uint64_t min = 0,
                             uint64_t max = 100):
                engine_(engine), mean_(mean), min_(min), max_(max),
                M_( fmax( pdf(floor(mean_)), pdf( ceil(mean_)) ) ){};

        uint64_t operator()() override;
        double pdf(uint64_t k) override;

    private:
        rng_engine& engine_;
        double mean_;
        uint64_t max_;
        uint64_t min_;
        double M_;

};

    class bernoulli_distribution {};
    class discrete_distribution {};



class uniform_real_distribution : public distribution<double >  {
  public:
    uniform_real_distribution(rng_engine& engine, double min = 0.0f,
                              double max = 1.0f):
            engine_(engine), min_(min), max_(max) {};

    double operator()() override;
    double pdf(double x) override;

  private:
    rng_engine& engine_;
    uint64_t min_;
    uint64_t max_;
};

class normal_distribution : public distribution<double >  {
  public:
    normal_distribution(rng_engine& engine, double mean = 0.0f, double stddev = 1.0f,
                        double min = 0.0f, double max = 1.0f):
            engine_(engine), mean_(mean), stddev_(stddev),
            min_(min), max_(max),
            M_(1 / sqrt( 2 * M_PI ) / stddev_) {};

    double operator()() override;
    double pdf(double x) override;

  private:
    rng_engine& engine_;
    double mean_;
    double stddev_;
    double min_;
    double max_;
    double M_ ;
};


} // namespace lcsc

uint64_t factorial( uint64_t n );