#include <stdio.h>
#include <math.h>

#define MAGIC 0x3f800000

float fsqrt(float n) {
    unsigned i = *(unsigned*)&n;
    i = (i + MAGIC) >> 1;
    float y = *(float*)&i;
    y = y*1.5f - n/(2*y);
    return y;
}

float fsqrt2(float n) {
    unsigned i = *(unsigned*)&n;
    i = (i + MAGIC) >> 1;
    float y = *(float*)&i;
    y = y*1.5f - n/(2*y);
    y = y*1.5f - n/(2*y);
    return y;
}

float vfsqrt(float n, long add) {
    unsigned i = *(unsigned*)&n;
    i = (i + MAGIC + add) >> 1;
    float y = *(float*)&i;
    y = y*1.5f - n/(2*y);
    return y;
}

int main() {/*
    float x = 1.0f;    
    for(size_t i=0;i<500;x+=1.0f,i++) {
        float sr = sqrt(x);
        float error = 50.0f;
        long best = 0;
        for(long j = -1048575; j<1048576;j++) {
            float sra = vfsqrt(x,j);
            float err = fabs(sr-sra);            
            error = err<error?err:error;
            best = err<error?j:best;
        }
        printf("%ld , %f\n",best,error);
    }
    */
    float y = 1;
    
    puts("AGAIN");
    for(size_t i=0;i<1000000;i++,y+=1.0f) {
        float sr = sqrt(y);
        float sra;
        float error = 1000;
        long best = 0;
        for(long j = -4048575; j<4048576;j++) {
        //printf("trying %ld\n",j);
        sra = vfsqrt(y,j);        
        float err = fabs(sr-sra);
        
        if(err < error) {
            //printf("%f %f %f\n",sr,sra,err);
            error = err;
            best=j;
        }         
        
        }
        printf("%f\t%ld\t%f\t%f\t%f\n",y,best,sr,vfsqrt(y,best),error);
    }
    
    
    return 0;
}