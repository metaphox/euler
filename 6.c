#include <stdio.h>
#define N 100

int sq(int *n){
    *n = (*n)*(*n);
    return *n;
}

int main(void){
    int nums[N];
    int i = 0; 
    int sum_sq = 0;
    int sq_sum = 0;
    int temp = 0;

    while(i < N){
        nums[i++] = i + 1;
    }
    for(i = 0; i < N; i++){
        sum_sq += sq(nums+i);
    }

    temp = ((1 + N) * (N / 2 ));
    sq_sum = temp * temp;

    printf("%d\n", sq_sum - sum_sq);
    return 0;
}

