#include <stdio.h>
#include <math.h>
#include <time.h>

float fsqrt(float n) {
    unsigned i = *(unsigned*)&n;
    i = (i + 0x3f800000) >> 1;
    float y = *(float*)&i;
    y = y*0.5f + n/(2*y); 
    y = y*0.5f + n/(2*y); 
    return y;
}

int main() {
    clock_t t1, t2, diff1, diff2;
    float res1, res2;
    float x = 7738563.26;
    t1 = clock();
    res1 = fsqrt(x);
    t2 = clock();
    diff1 =t2-t1;
    t1 = clock();
    res2 = sqrt(x);
    t2 = clock();
    diff2 = t2 - t1;
    printf("fsqrt:\tresultado:%f\tciclos:%ld\n",res1,(long)diff1);
    printf("sqrt:\tresultado:%f\tciclos:%ld\n",res2,(long)diff2);
    return 0;
}
