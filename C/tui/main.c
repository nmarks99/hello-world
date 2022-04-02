#include "tui.h"

int main(void) {

    printf("%shello world%s\n",ANSI_MAGENTA, ANSI_RESET);
    printf("%shello world%s\n",ANSI_BOLD_MAGENTA, ANSI_RESET);
    
    int rows[10];
    int cols[10];
    tui_win_size(rows,cols);
 
    printf("%sRows = %d\nColumns = %d\n %s",ANSI_BOLD_BLUE,*cols,*rows,ANSI_RESET);


    test();
}

