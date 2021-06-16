#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 5

int main(void){
    FILE *fd;
    char buff[255];

    fd = fopen("test.txt", "r");
    int i, n;
    char buffer[MAX_LINE_LENGTH];
    /* Read the first line */
    fgets(buffer, sizeof(buffer), fd);
    /* That should contain a single integer. */
    n = atoi(buffer);
    for (i = 0; i < n; i++){
        /* Read next line */
        fgets(buffer, sizeof(buffer), fd);
        /* Process line here.
       Note that fgets stores also the line terminator (CR-LF or LF). */
       printf("Hello %d\r\n",n);
    }

    return 0;
}