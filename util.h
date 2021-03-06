/// @file util.h
#pragma once

#include <vector>
#include <memory>

namespace IsakMath {
    namespace Util {
        /// Converts a vector of type X to a vectory of type Y using a regular cast
        template <typename S, typename D>
        std::vector<D> convert_vector(std::vector<S> &v) {
            std::vector<D> ret;
            for (const auto &element : v) {
                ret.push_back((D)element);
            }
            return ret;
        }

        /// Reverses a given vector
        template <typename T>
        std::vector<T> reverse(std::vector<T> &&a) {
            for (int i = 0; i < a.size()/2; i++) {
                T tmp = a[i];
                a[i] = a[a.size()-1-i];
                a[a.size()-1-i] = tmp;
            }
            return a;
        }
    }
}
