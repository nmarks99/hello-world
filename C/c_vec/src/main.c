#include <stdio.h>
#include "stdlib.h"
#include "../include/vector.h"


int add_one(int a) {
    return a + 1;
}

int add(int a, int b) {
    return a + b;
}


int main(int argc, char *argv[]) {
    VectorInt v = VectorInt_new(10);
    for (int i = 1; i <= 5; i++){
        v = VectorInt_push(&v, i);
    }

    int sum = VectorInt_reduce(&v, add);
    printf("Sum of "); VectorInt_display(&v); printf(" = %d\n", sum);

    VectorInt_free(&v);
    return 0;

}
