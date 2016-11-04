#include <stdio.h>
#include <math.h>

float error_f(float a, float b) {
    return abs(a-b);
}

float fsqrt123(float n) {
    unsigned int i = *(int*)&n;
    i = (i + 0x3f800000) >> 1;
    float y = *(float*)&i;
    y = y*1.5f - n/(2*y); 
    return y;
}

int main() {
    float x = 763.25;
    float res = sqrt(x);
    float res2 = fsqrt123(x);
    printf("res: %f res2: %f\n",res,res2);
    return 0;
}