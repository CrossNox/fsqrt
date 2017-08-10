#include "fsqrt.h"
#include <stdio.h>

float fsqrt(float n,int iter) {
    unsigned i = *(unsigned*)&n;
    i = (i + 0x3f800000) >> 1;
    float y = *(float*)&i;
    for(;iter--;) {
    	y = y*0.5f + n/(2*y); 
    }
    return y;
}