#include <stdio.h>

#define LIMIT 4000000

int main(void){
    int i;
    long fibnum = 0, sum = 0;
    long n[] = {1, 1};

    for(i = 2; fibnum < LIMIT; i++){
        fibnum = n[1] + n[0];
        n[0] = n[1];
        n[1] = fibnum;

        if(fibnum % 2){
            continue;
        }
        sum += fibnum;
    }
    printf("sum = %ld\n", sum);
    return 0;
}

