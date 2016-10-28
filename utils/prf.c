#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

union fu {
    float f;
    int32_t i;
};

int32_t bit_v(int32_t num, int32_t index) {
    return !!(num & 1<<index);
}

void print_bin(union fu num) {
    printf("| ");
    for (int i = 31; i>=0; i--) {
        if(i==30 || i==22)
            printf("| ");
        printf("%"PRId32" ",bit_v(num.i,i));
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if(argc!=2 && argc!=3) {
        fprintf(stderr,"error en la cantidad de parametros\n");
        abort();
    }

    union fu den1, den2, den_add;
    den1.f = atof(argv[1]);
    print_bin(den1);
    if(argc==3) {
        den2.f = atof(argv[2]);
        print_bin(den2);
        den_add.f = den1.f + den2.f;
        print_bin(den_add);
    }
    return 0;
}