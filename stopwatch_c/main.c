#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void delay(float t);

int main(void){
    char buff[100];
    printf("Type something: ");
    scanf("%s",&buff);
    printf("You typed %s\r\n",buff);
}

void delay(float t){
    clock_t start;
    start = clock();
    while( ((clock()-start)/CLOCKS_PER_SEC) < t ){
        // Delay
    }
}