#include <ncurses.h>
using namespace std;

int main(int argc, char **argv) {

    initscr();
   
    int height = 10;
    int width = 20;
    int start_row = 10;
    int start_col = 10;
    
    // create pointer to window
    WINDOW * win = newwin(height, width, start_row, start_col);
    refresh();    


    // Creates a simple box around a window
    box(win, 0, 0);
    //
    mvwprintw(win, 1, 1, "This is a window");
    wrefresh(win);
    
    int c = getch();

    endwin();

    return 0;
}
