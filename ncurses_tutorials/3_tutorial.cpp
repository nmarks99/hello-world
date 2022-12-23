#include <ncurses.h>
using namespace std;

int main(int argc, char **argv) {

    initscr();
    cbreak(); // DEFAULT allows exiting with ctrl+c
    // raw(); // Takes raw input, ctrl-c won't exit
    noecho(); // input user types will not be printed

    // create pointer to window
    int height = 10;
    int width = 20;
    int start_row = 10;
    int start_col = 10;
    WINDOW * win = newwin(height, width, start_row, start_col);
    refresh();    

    // Creates a simple box around a window
    // You can define which character to use for border
    // int top_border = (int)'-';
    // int top_border = (int)'-';
    int top_border = 0;
    int bot_border = 0;
    box(win, top_border, bot_border); 
    
    // greater customization available with wborder
    // wborder(win, left, right, top, bottom, tlc, trc, blc, brc);

    mvwprintw(win, 1, 1, "This is a window");
    wrefresh(win);
    
    int c = getch();

    endwin();

    return 0;
}
