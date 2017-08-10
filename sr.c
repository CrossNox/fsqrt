#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <float.h>
#include "fsqrt.h"

#ifndef M_PI
#define M_PI acos(-1.0)
#endif
#define ITERATIONS 10000

void time_tests(int iterations) {    
    FILE* f = fopen("time_tests.csv","w");
    fprintf(f,"index,f,sqrtf,fsqrt\n");

    clock_t t1, t2, diff_fsqrt=0, diff_sqrtf=0;
    float x;

    for(size_t i= 0; i < iterations ; ++i) {
        x = 100.0f*((float)rand())/((float)RAND_MAX);    

        t1 = clock();
        sqrtf(x);
        t2 = clock();
        diff_sqrtf = t2-t1;

        t1 = clock();
        fsqrt(x,2);
        t2 = clock();
        diff_fsqrt = t2-t1;

        fprintf(f,"%lu,%.12f,%ld,%ld\n",i,x,diff_sqrtf,diff_fsqrt);
    }
    fclose(f);
}

void difference_tests(float max) {    
    FILE* f = fopen("difference_tests.csv","w");
    fprintf(f,"index,f,diff2,diff3,diff4,diff5\n");

    float res_fsqrt, res_sqrtf, x = 0.25f;

    for(int i=0; x < max ; ++i,x += 0.01f) {
        res_sqrtf = sqrtf(x);
        fprintf(f,"%i,%.12f",i,x);
        for(int j=2;j<=5;++j){
            res_fsqrt = fsqrt(x,j);
            fprintf(f,",%.12f",res_fsqrt-res_sqrtf);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

void calculate_pi(int iterations) {
    FILE* f = fopen("pi.csv","w");
    fprintf(f,"iterations,pi_aprox,difference\n");

    for(int i=1;i<iterations;++i) {
        size_t hits = 0;    
        for(size_t darts = 0; darts < i ; darts++) {
            float dart_x = -1.0f+(float)(((double)rand()/(double)(RAND_MAX))*2);
            float dart_y = -1.0f+(float)(((double)rand()/(double)(RAND_MAX))*2);
            hits+=!!(fsqrt(dart_y*dart_y+dart_x*dart_x,2)<=1.0f);
        }
        float pi_aprox = ((float)hits)/((float)(i));
        pi_aprox *= 4.0f; 
        fprintf(f,"%i,%.12f,%f\n",i,pi_aprox,M_PI-pi_aprox);
    }
    fclose(f);
}

int main(int argc, char* argv[]) {
    srand((unsigned)clock());
    time_tests(ITERATIONS);
    difference_tests(32.0f);
    calculate_pi(ITERATIONS);    
    return 0;
}
