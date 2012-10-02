#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    unsigned long i = 3;

    //primes
    unsigned long *primes = NULL;
    size_t n_primes;

    unsigned long target = 2;

    //counters
    int j, k;

    //prefill primes with two
    primes = malloc(sizeof(unsigned long));
    *primes = 2;
    n_primes = 1;

    for(i = 3;i < 2000000;i += 2){
        bool is_prime = true;
        for(j = 0; j < n_primes; j++){
            if((*(primes + j)) * (*(primes + j)) > i){
                break;
            }
            if(i % *(primes + j) == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes = realloc( primes, sizeof(unsigned long) *
                (n_primes + 1));
            *(primes + n_primes) = i;
            n_primes++;
            target += i;
        }
    }

    free(primes);
    printf("%ld\n", target);
    
    return 0;
}
