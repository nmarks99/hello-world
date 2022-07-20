#include<stdio.h>

void ones(char *arr) {
    size_t i = 0;
    int v = 1;
    for (i; i < 100;i++) {
        arr[i] = v;
    } 
}

void twos(char *arr) {
    size_t i = 0;
    int v = 2;
    for (i; i < 100;i++) {
        arr[i] = v;
    } 
}

int main() {
    char arr[100];
    size_t i;

    twos(arr);
    for (i = 0; i < 100; i++) {
        printf("%d",arr[i]);
        printf("\n");
    }

    ones(arr);    
    for (i = 0; i < 100; i++) {
        printf("%d",arr[i]);
        printf("\n");
    }

    return 0;
}