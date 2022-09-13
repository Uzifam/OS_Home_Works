#include <stdio.h>

void first(int n){ // right triangle
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j)printf("*");
        printf("\n");
    }
}

void second(int n){
    for(int i = 0; i < (n + 1) /2; ++i){
        for(int j = 0; j <= i; ++j)printf("*");
        printf("\n");
    }
    for(int i = 0; i < n / 2; ++i){
        for(int j = n / 2 - i; j > 0; --j)printf("*");
        printf("\n");
    }
}

void third(int n){
        for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)printf("*");
        printf("\n");
    }
}

int main()
{
    third(6);
    return 0;
}

