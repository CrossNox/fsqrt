#include <stdio.h>
#include <math.h>

#define DELTA 0x3f800000

float fsqrt(float n) {
    long i = *(long*)&n;
    //printf("recibo %f\n",n);
    i = (i + DELTA)/2;
    //printf("tengo so far 0x%08x\n",*(int*)&i);
    float y = *(float*)&i;
    //y = y + (y*y-n)/(2*y);
    return y;
}

int main() {
    float x = 763.25;
    printf("0x%08x\n",*(int*)&x);
    float res = sqrt(x);
    printf("0x%08x\n",*(int*)&res);
    float res2 = fsqrt(x);
    printf("0x%08x\n",*(int*)&res2);
    printf("res: %f res2: %f\n",res,res2);

    return 0;
}