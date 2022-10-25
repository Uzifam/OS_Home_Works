#include <stdio.h>
#include <malloc.h>

int main(){
    int N;
    printf("Enter size of N: ");
    scanf("%d", &N);
    int *ptr = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; ++i)ptr[i] = i;
    printf("Array:\n");
    for(int i = 0; i < N; ++i)printf("%d ",ptr[i]);

    free(ptr);
    return 0;
}
