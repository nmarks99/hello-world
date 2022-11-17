#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
    FILE *fp = fopen("asdf.txt","w");
    fputs("Hello",fp);
    fclose(fp);
    return 0;
}