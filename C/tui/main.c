#include "tui.h"
#include <time.h>


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int main(void) {
/*  */
    /* printf("%shello world%s\n",ANSI_MAGENTA, ANSI_RESET); */
    /* printf("%shello world%s\n",ANSI_BOLD_MAGENTA, ANSI_RESET); */
    /*  */
    /* int rows[10]; */
    /* int cols[10]; */
    /* tui_win_size(rows,cols); */
 /*  */
    /* printf("%sRows = %d\nColumns = %d\n %s",ANSI_BOLD_BLUE,*cols,*rows,ANSI_RESET); */

    char dots[100] = ".";
    int i = 0;
    while(1){
        i += 1;
        printf("%s",ANSI_RESET);
        printf("Loading");
        printf("%s", dots);
        delay(1);
        dots[i] = dots[i-1];
    }
}

