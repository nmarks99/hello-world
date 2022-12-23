#include <ncurses.h>
using namespace std;


int main(int argc, char **argv) {

    initscr();
    cbreak(); // DEFAULT allows exiting with ctrl+c
    noecho(); // input user types will not be printed

   
    int y, x, yBeg, xBeg, yMax, xMax;
    
    // WINDOW *win = newwin(10, 20, 10, 10);

    // getyx(stdscr, y, x);    // gives current y,x of cursor

    // getbegyx(stdscr, yBeg, xBeg); // gives top left corner of given window
                                  
    getmaxyx(stdscr, yMax, xMax); // gives height and width of given window
    
    // prints at center if the window
    mvprintw(yMax/2, xMax/2, "Hello!!!"); 
    // refresh();
    // wrefresh(win);
    getch(); 

    endwin();

    return 0;
}
