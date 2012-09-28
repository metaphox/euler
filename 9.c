#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define K 1000

bool is_pythagorean(int a, int b, int c){
    return (c * c) == (a * a + b * b);
}

int main(void){
    long a, b, c;
    int i, j, k;

    long sq_nums[K];

    for(i = 1; i <= K; i++){
        sq_nums[i-1] = i * i;
    }

    for(i = 1; i <= K; i++){
        a = sq_nums[i-1];
        for(j = i + 1; j <= K; j++){
            b = sq_nums[j-1];
            for(k = j + 1; k <= K; k++){
                c = sq_nums[k-1];
                if(a + b == c && i + j + k == K){
                    printf("%ld\n", i * j * k);
                    return 0;
                }
            }
        }
    }
    return 0;
}

