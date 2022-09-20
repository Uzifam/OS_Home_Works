#include <stdio.h>
#include <malloc.h>

int foo(int boof){
    return 2022 - boof;
}

int main() {
    const int x = 10;
    int *q = &x;
    int * const p = (const int *) malloc(5);
    for(int i = 0; i < 5; ++i)
        *(p + i) = *q;
    for(int i = 0; i < 5; ++i)printf("%d ", (p + i));
    printf("\nEnter ages of 5 students: \n");
    for(int i = 0; i < 5; ++i){
        scanf("%d", (p + i));
    }
    for(int i = 0; i < 5; ++i)*(p + i) = foo(*(p + i));
    free(p);
    return 0;
}

