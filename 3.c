#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    unsigned long long num = 600851475143ULL;
    unsigned long long i = 3;

    //primes
    unsigned long long *primes = NULL;

    //the prime factors of num
    unsigned long long *prime_factors = NULL;
    size_t n_prime_factors = 0;

    //product of the prime factors
    unsigned long long product_prime_factor = 1;
    size_t n_primes;

    //target
    unsigned long long max_prime_factor = 0;

    //counters
    int j, k;

    //prefill primes with two
    primes = (unsigned long long *)realloc(
            primes, sizeof(unsigned long long));
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
            primes = (unsigned long long *)realloc(
                primes, sizeof(unsigned long long) * (n_primes + 1));
            *(primes + n_primes) = i;
            n_primes++;
            if(num % i == 0){
                prime_factors = (unsigned long long *)realloc(
                    prime_factors, sizeof(unsigned long long)
                    * (n_prime_factors + 1));
                *(prime_factors + n_prime_factors) = i;
                n_prime_factors++;
                product_prime_factor = 1;
                for(k = 0; k < n_prime_factors; k++){
                    product_prime_factor *= *(prime_factors + k);
                }
                if(product_prime_factor == num){
                    max_prime_factor = i;
                    break;
                }
            }
        }
    }

    free(primes);
    free(prime_factors);

    printf("%lld\n", max_prime_factor);
    
    return 0;
}
