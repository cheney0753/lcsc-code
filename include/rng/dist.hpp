#pragma once

#include <cstdint>

namespace lcsc{

    // define a class for either uint or double
    template <typename T>
    class distribution {
    public:
        virtual double pdf(T x) = 0;
        virtual T operator()() = 0;
    };

}