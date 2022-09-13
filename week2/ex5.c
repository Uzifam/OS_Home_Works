#include <stdio.h>

long long tribonacci(long long Number){
    long long c = 0, b = 1, a = 1, d = 0, answer = 0;
    if(Number == 0)
        return 0;
        else if(Number >= 1 && Number <= 2)
                return 1;
                else{
                    for(int i = 2; i < Number; ++i){
                        d = a + b + c;
                        c = b;
                        b = a;
                        a = d;
                    }
                    return d;
                }
}

int main()
{
    printf("%lld,  %lld\n", tribonacci(4), tribonacci(36));
    return 0;
}

