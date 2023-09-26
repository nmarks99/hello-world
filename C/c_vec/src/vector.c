#include "../include/vector.h"


VectorInt VectorInt_new(size_t capacity) {
    VectorInt v;
    v.data = (int *)malloc(capacity * sizeof(int));
    v.length = 0;
    v.capacity = capacity;
    return v;
}

size_t VectorInt_length(const VectorInt *vec) {
    return vec->length;
}

size_t VectorInt_capacity(const VectorInt *vec) {
    return vec->capacity;
}

void VectorInt_display(const VectorInt *vec) {
    printf("[");
    for (size_t i = 0; i < vec->length; i++) {
        printf("%d", vec->data[i]);
        if (i < vec->length-1) {
            printf(",");
        }
    }
    printf("]");
}

VectorInt VectorInt_push(const VectorInt *vec, int value) {

    // copy the input vector
    VectorInt v_new = *vec;
    
    // double capacity and reallocate memory if needed
    if (v_new.length == v_new.capacity) {
        v_new.capacity *= 2;
        v_new.data = (int *)realloc(v_new.data, v_new.capacity * sizeof(int));
    }

    // append input value to the end of the vector and return it
    v_new.data[v_new.length] = value;
    v_new.length += 1;
    return v_new;
}

VectorInt VectorInt_map(const VectorInt *vec, int (*f)(int) ) {
    VectorInt v_new = *vec;
    for (size_t i = 0; i < v_new.length; i++) {
        v_new.data[i] = (*f)(v_new.data[i]);
    }
    return v_new;
}

int VectorInt_reduce(const VectorInt *vec, int (*f)(int, int)) {
    int result = vec->data[0];
    for (size_t i = 1; i < vec->length; i++) {
        result = (*f)(result, vec->data[i]);
    }
    return result;
}

void VectorInt_free(VectorInt *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->length = 0;
    vec->capacity = 0;
}

//
// void VectorInt_fill(VectorInt *vec, int value) {
//     for (size_t i = 0; i < vec->capacity; i++) {
//         vec->data[i] = value;
//     }
//     vec->size = vec->capacity;
// }
//
//
//

