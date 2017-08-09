#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

float fsqrt(float n) {
    unsigned i = *(unsigned*)&n;
    i = (i + 0x3f800000) >> 1;
    float y = *(float*)&i;
    y = y*0.5f + n/(2*y);
    y = y*0.5f + n/(2*y);  
    return y;
}

int main() {
    srand((unsigned)clock());
    clock_t t1, t2, diff1=0, diff2=0;
    float res1, res2, x;
    #define ITERATIONS 100000
    for(size_t i= 0; i < ITERATIONS ; i++) {
        x = ((float)rand())/10000;        
        t1 = clock();
        res2 = (float)sqrt(x);
        t2 = clock();
        diff2 += t2-t1;
        t1 = clock();
        res1 = fsqrt(x);
        t2 = clock();
        diff1 += t2-t1;
        printf("x:%.6f\tsqrt:%.6f\tfsqrt:%.6f\n",x,res2,res1);
    }
    printf("%ld sqrt \t%ld fsqrt\n",diff2,diff1);

    //Let's use it to calculate pi
    size_t hits = 0;    
    for(size_t darts = 0; darts < SHITLOAD ; darts++) {
        float dart_x = -1.0f+(float)(((double)rand()/(double)(RAND_MAX))*2);
        float dart_y = -1.0f+(float)(((double)rand()/(double)(RAND_MAX))*2);
        if(fsqrt(dart_y*dart_y+dart_x*dart_x)<=1.0f)
            hits++;
    }
    printf("%zu hits\n",hits);
    float pi_aprox = (float)hits/SHITLOAD;
    pi_aprox *= 4.0f; 
    printf("%f aprox pi\n",pi_aprox);
    return 0;
}
