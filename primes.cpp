#include "primes.h"

using std::ostream;
using std::pair;
using std::make_pair;

/* **************************************** */
/* PRIMES                                   */
/* **************************************** */
bool IsakMath::Primes::is_prime(long number) {
    if (number < 2)
        return false;
    if (number % 2 == 0)
        return number == 2;

    long k = 3;
    while (k*k <= number) {
        if (number % k == 0) {
            return false;
        }
        k += 2;
    }

    return true;
}

long IsakMath::Primes::next_prime(long number) {
    number += 1;
    while (!is_prime(number)) {
        number += 1;
    }

    return number;
}

std::vector<pair<long,long>> IsakMath::Primes::prime_factorization(long number) {
    std::vector<pair<long,long>> factors;
    long prime = 2;

    while (number != 1) {
        long exponent = 0;
        while (number % prime == 0) {
            number /= prime;
            exponent++;
        }

        if (exponent > 0) {
            factors.push_back(make_pair(prime, exponent));
        }

        prime++;
    }

    return factors;
}

std::vector<long> IsakMath::Primes::prime_sieve(int boundary) {
    bool numbers[boundary];
    numbers[0] = false;
    numbers[1] = false;

    long j = 2;
    while (j * 2 < boundary) {
        numbers[j * 2] = false;
        j += 1;
    }

    for (int i = 0; i < boundary; i++) {
        if (numbers[i] == 1) {
            j = 2;
            while (j*i < boundary) {
                numbers[j*i] = false;
                j++;
            }
        }
    }

    std::vector<long> primes;
    for (int i = 0; i < boundary; i++) {
        if (numbers[i]) {
            primes.push_back((long)i);
        }
    }

    return primes;
}
