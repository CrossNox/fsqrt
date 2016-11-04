#include <stdio.h>
#include <math.h>

float fsqrt(float n) {
    unsigned i = *(unsigned*)&n;
    i = (i + 0x3F7B381D) >> 1;
    float y = *(float*)&i;
    y = y*1.5f - n/(2*y); 
    return y;
}

int main() {
    float x = 763.26;
    printf("res: %f res_f:%f\n",sqrt(x), fsqrt(x));
    return 0;
}