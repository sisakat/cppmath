/// @file statistics.h
/// @brief Several statistical functions
#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "linear_function.h"

namespace IsakMath {
  namespace Statistics {
    /// @brief Calculates the Bravais-Pearson correlation coefficient
    /// @param a values of the first set
    /// @param b values of the second set
    /// @return correlation coefficient as double
    double correlation_coefficient(const std::vector<double> &a, const std::vector<double> &b);

    /// @brief Calculates the variance of a given set
    double variance(const std::vector<double> &a);

    /// @brief Calculates the covariance of a given set
    double covariance(const std::vector<double> &a, const std::vector<double> &b);

    /// @brief Calculates the mean of a given set
    double mean(const std::vector<double> &a);

    /// @brief Calculates the sum of a given set
    double sum(const std::vector<double> &a);

    /// @brief Calculates a linear function out of two given sets
    /// @return a linear-function describing the new
    linear_function linear_regression(const std::vector<double> &a, const std::vector<double> &b);
  }
}
