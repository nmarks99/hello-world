#include <ncurses.h>
using namespace std;


int main(int argc, char **argv) {

    initscr();
    cbreak(); // DEFAULT allows exiting with ctrl+c
    // raw(); // Takes raw input, ctrl-c won't exit
    // noecho(); // input user types will not be printed

    if (!has_colors()){
        printw("Terminal does not support color");
        getch();
        return -1;
    }
    start_color();
    use_default_colors();
    

    if (!can_change_color()) {
        printw("Can't change color!");
        getch();
        return -1;
    }
    
    // Redefines a color
    // init_color(COLOR_BLUE, 534, 333, 111);
    
    init_pair(1, COLOR_BLUE, -1);
    
    attron(COLOR_PAIR(1));
    printw("Hello this is some text");
    attroff(COLOR_PAIR(1));
    
    getch();    

    endwin();

    return 0;
}
