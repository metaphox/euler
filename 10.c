#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 2000000

int main(void){
    unsigned long i = 3;

    //primes
    unsigned long *primes = NULL;

    //the prime factors of num
    unsigned long *prime_factors = NULL;
    size_t n_prime_factors = 0;

    //product of the prime factors
    unsigned long product_prime_factor = 1;
    size_t n_primes;

    //target
    unsigned long max_prime_factor = 0;

    //counters
    int j, k;

    //prefill primes with two
    primes = (unsigned long *)malloc(sizeof(unsigned long));
    *primes = 2;
    n_primes = 1;

    //loop to find a prime, then check if it is a prime factor of num, if
    // yes, then check if num could be reached by multiplicating all its
    // factors.
    for(i = 3;;i += 2){
        bool is_prime = true;
        for(j = 0; j < n_primes; j++){
            if(*(primes + j) > sqrt(i)){
                break;
            }
            if(i % *(primes + j) == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes = (unsigned long *)realloc(
                primes, sizeof(unsigned long) * (n_primes + 1));
            *(primes + n_primes) = i;
            n_primes++;
        }
    }

    free(primes);

    printf("%lld\n", max_prime_factor);
    
    return 0;
}
