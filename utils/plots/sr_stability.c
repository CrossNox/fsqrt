#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define NUM_STEPS 100000000

float fsqrt(float n) {
    unsigned i = *(unsigned*)&n;
    i = (i + 0x3f800000) >> 1;
    float y = *(float*)&i;
    y = y*0.5f + n/(2*y);
    y = y*0.5f + n/(2*y);  
    return y;
}
void next(size_t *n) {
    if(*n<100)*n=*n+1;
    else if(*n<10000)*n=*n+10;
    else if(*n<1000000) *n=*n+100;
    else *n=*n+1000;
}

int main() {
    float res1, res2, x;
    printf("x\tsqrt\tfsqrt\n");
    for(size_t i= 0; i < NUM_STEPS ; next(&i)) {
        x = (float) i;        
        res2 = (float)sqrt(x);
        res1 = fsqrt(x);
        printf("%.6f\t%.6f\t%.6f\n",x,res2,res1);
    }
    return 0;
}
