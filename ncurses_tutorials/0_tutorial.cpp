#include <ncurses.h>
using namespace std;

int main(int argc, char **argv) {

    initscr(); // Initializes screen
    
    printw("hello world"); // prints a char * to a window

    refresh(); // Refreshes the screen
    
    int ch = getch(); // Waits for user input, returns int value of char 
    printw("%d", ch);
    getch();
    
    endwin(); // Destoys ncurses
    return 0;
}
