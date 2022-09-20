#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Point{
    float x, y;
};

float distance(struct Point A, struct Point B){
    float boof = (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
    return (double)sqrt((double)boof);
}

float area(struct Point A, struct Point B, struct Point C){
    return abs(A.x*B.y-B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y) / 2;
}

int main() {
    struct Point A = {2.5, 6}, B = {1, 2.2}, C = {10, 6};
    float Dist = distance(A, B), Area = area(A, B, C);
    printf("The distance: %f\nThe area: %f", Dist, Area);
    return 0;
}
