#include <iostream>

#include "IsakMath/point.h"
#include "IsakMath/vector.h"
#include "IsakMath/primes.h"
#include "IsakMath/statistics.h"
#include "IsakMath/linear_function.h"

#define PRINT(x) std::cout << (#x) << " = " << (x) << std::endl

using namespace IsakMath;

void example_primes() {
  PRINT(Primes::is_prime(3));
  PRINT(Primes::next_prime(3));
}

void example_vector() {
  vector v1 = { 0, 3 };
  vector v2 = { 3, 0 };
  vector v3 = { 3, 6 };
  PRINT(v1);
  PRINT(v2);
  PRINT(v3);
  PRINT(v1 * v2);
  PRINT(v2 * v3);
  PRINT(v1 * 2);
  PRINT(v3 / 2);
  PRINT(v3.length());
  PRINT(v1.mirror({ 0, 1 }));
  PRINT(v1.rotate2d(M_PI/2));
}

void example_statistics() {
  std::vector<double> a = { 1, 2, 3, 4, 5, 6 };
  std::vector<double> b = { 2, 4, 6, 8, 10, 12 };
  PRINT(Statistics::mean(a));
  PRINT(Statistics::sum(a));
  PRINT(Statistics::variance(a));
  PRINT(Statistics::linear_regression(a, b));
}

int main() {
  example_primes();
  example_vector();
  example_statistics();
  return 0;
}
