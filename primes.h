/// @file primes.h
/// @brief Several prime functions
#pragma once

#include <ostream>
#include <vector>

namespace IsakMath {
  namespace Primes {
    /// @brief Checks wether the given number is prime.
    /// @param number number to check
    /// @return true or false
    bool is_prime(long number);

    /// @brief Gets the next prime after the given number
    /// @return next prime number
    long next_prime(long number);

    /// @brief Prime factorization of a number
    /// @param number Number to factorize
    /// @return vector containing pairs of base and exponent
    auto prime_factorization(long number) -> std::vector<std::pair<long,long>>;

    /// @brief Get primes below a given boundary using the sieve method
    /// @param boundary the upper exclusive limit
    /// @return vector of primes
    auto prime_sieve(int boundary) -> std::vector<long>;
  }
}
