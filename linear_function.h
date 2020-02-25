/// @file linear_function.h
#pragma once

#include <iostream>

namespace IsakMath {
    /// Represents a linear function of the form \f$kx + d\f$
    class linear_function {
    public:
        double k, d;
        linear_function(double k, double d) : k(k), d(d) {}
        double inline operator()(double x) { return k*x + d; }
        friend std::ostream& operator<<(std::ostream& os, const linear_function& fx);
    };
}
