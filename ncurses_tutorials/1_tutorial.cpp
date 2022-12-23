#include <ncurses.h>
using namespace std;

int main(int argc, char **argv) {

    initscr(); // Initializes screen
   
    int rows = 10;
    int cols = 10;
    move(rows, cols); // moves cursor
    printw("hello world"); // prints a char * to a window

    refresh(); // Refreshes the screen
   
    int ch = getch(); // Waits for user input, returns int value of char 
    mvprintw(1, 1, "%d", ch); // combines move and printw
    getch();
    
    clear(); // clears the screen
    getch();


    endwin(); // Destoys ncurses
    return 0;
}
