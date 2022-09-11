#include <stdio.h>
#include <limits.h>
#include<float.h>
int main()
{
    int IntValue = INT_MAX;
    unsigned short int ShortValue = USHRT_MAX;
    signed long int LongValue = LONG_MAX;
    float  FloatValue = FLT_MAX;
    double DoubleValue =  DBL_MAX;
    printf("Size integer: %ld     Value : %d   \n", sizeof(IntValue), IntValue);
    printf("Size integer: %ld     Value : %hu   \n", sizeof(ShortValue), ShortValue);
    printf("Size integer: %ld     Value : %ld   \n", sizeof(LongValue), LongValue);
    printf("Size integer: %ld     Value : %f   \n", sizeof(FloatValue), FloatValue);
    printf("Size integer: %ld     Value : %lf   \n", sizeof(DoubleValue), DoubleValue);
    return 0;
}
