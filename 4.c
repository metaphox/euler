#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool is_palindromic(int num){
    char buf[65];
    int i, len;
    sprintf(buf, "%d", num);
    len = strlen(buf);
    for(i = 0; i < (len / 2); i++){
        if(buf[i] != buf[len-1-i]){
            return false;
        }
    }
    return true;
}

int main(void){
    int i, j;
    int tgt = 0, temp = 0;
    for(i = 999; i > 100; i--){
        for(j = 999; j > 100; j--){
            temp = i * j; 
            if(is_palindromic(temp) && temp > tgt){
                tgt = temp;
            }
        }
    }
    printf("%d\n", tgt);
    return 0;
}

