#!/usr/bin/env python
import math

NUM = 600851475143

#prime number generator
def primes():
    yield 2
    primes = [2, 3]
    while 1:
        n = primes[-1]
        yield n
        while 1:
            n += 2 
            is_prime = True
            for p in primes:
                if p < math.sqrt(n) and n % p == 0:
                    is_prime = False
                    break
            if is_prime:
                primes.append(n)
                break

def find_max_prime_factor(n):
    prime_factors = [1]
    for x in primes(): 
        if n % x == 0:
            if reduce(lambda a, b: a * b, prime_factors, x) == NUM:
                return x
            prime_factors.append(x)

if __name__ == '__main__':
    print find_max_prime_factor(NUM)
#    gen = primes()
#    print [gen.next() for x in range(100)]
