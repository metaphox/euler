#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define NTH 10001

int main(void){
    long long *primes = (long long *)malloc(sizeof(long long) * NTH);
    long long j;
    int k = 0;
    bool is_prime;

    int i = 1;
    *primes = 2;

    for(j = primes[i-1];;j++){
        is_prime = true;
        for(k = 0; k <= i && (primes[k] * primes[k]) <= j ; k++){
            if(j % primes[k] == 0){
                is_prime = false;
            }
        }
        if(is_prime){
            *(primes+i) = j;
            if(i >= NTH+1){
                printf("%lld\n", j);
                free(primes);
                return 0;
            }
            i++;
        }
    }
    return 0;
}

