#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int *data;
    size_t length;
    size_t capacity;
} VectorInt;

#define DEFAULT_CAPACITY 10

VectorInt VectorInt_new(size_t capacity);
size_t VectorInt_length(const VectorInt *vec);
size_t VectorInt_capacity(const VectorInt *vec);
void VectorInt_display(const VectorInt *vec);
void VectorInt_free(VectorInt *vec);
VectorInt VectorInt_push(const VectorInt *vec, int value);
VectorInt VectorInt_map(const VectorInt *vec, int (*f)(int));
int VectorInt_reduce(const VectorInt *vec, int (*f)(int,int));
// void VectorInt_initialize(VectorInt *vec, size_t capacity);
// void VectorInt_fill(VectorInt *vec, int value);
