#include "linear_function.h"

namespace IsakMath {
    std::ostream& operator<<(std::ostream& os, const IsakMath::linear_function& fx) {
        os << "f(x) = " << fx.k << " * x + " << fx.d;
        return os;
    }
}
