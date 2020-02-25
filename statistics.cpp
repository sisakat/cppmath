#include <cmath>
#include "statistics.h"

double IsakMath::Statistics::variance(const std::vector<double> &a) {
    double s = 0.0;
    double m = mean(a);
    for (const auto &v : a) {
        s += (v - m) * (v - m);
    }
    return 1.0/a.size() * s;
}

double IsakMath::Statistics::covariance(const std::vector<double> &a, const std::vector<double> &b) {
    if (a.size() != b.size()) return 0;
    double s = 0.0;
    double m_a = mean(a);
    double m_b = mean(b);
    for (int i = 0; i < a.size(); i++) {
        s += (a[i] - m_a) * (b[i] - m_b);
    }
    return 1.0/a.size() * s;
}

double IsakMath::Statistics::mean(const std::vector<double> &a) {
    return sum(a)*1.0 / a.size();
}

double IsakMath::Statistics::sum(const std::vector<double> &a) {
    double sum = 0.0;
    for (const auto &v : a) {
        sum += v;
    }

    return sum;
}

double IsakMath::Statistics::correlation_coefficient(const std::vector<double> &a, const std::vector<double> &b) {
    return covariance(a, b) / std::sqrt(variance(a) * variance(b));
}

IsakMath::linear_function IsakMath::Statistics::linear_regression(const std::vector<double> &a, const std::vector<double> &b) {
    double b1 = covariance(a, b) / variance(a);
    double b0 = mean(b) - b1 * mean(a);
    return linear_function(b1, b0);
}
