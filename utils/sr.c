#include <stdio.h>
#include <math.h>

float error_f(float a, float b) {
    return fabsf(a-b);
}

float fsqrt(float n, int delta) {
    unsigned int i = *(int*)&n;
    i = (i + delta) >> 1;
    float y = *(float*)&i;
    y = y*1.5f - n/(2*y); 
    return y;
}

int main() {
    float x = 763.26;
    float res = sqrt(x);

    float min_error = 1.0f;
    float error_act;
    int delta_min = 0x3F7B381D;
    for(int delta = 0x3F7B381D; delta>=0; delta--) {
        error_act = error_f(res,fsqrt(x,delta));
        if(error_act<min_error) {
            //printf("%f error min act\n",error_act);
           min_error = error_act;
           delta_min = delta;
        }            
        //printf("%f error min act\n",error_act);
    }

    printf("res: %f res_f:%f\n",res, fsqrt(x,delta_min));
    printf("min error=%f delta=%d\n",min_error,delta_min);
    return 0;
}