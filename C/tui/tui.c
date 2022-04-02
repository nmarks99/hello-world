#include "tui.h"

// Get the current size of the terminal window
void tui_win_size(int *cols, int *rows){

	struct winsize size;
	ioctl(1, TIOCGWINSZ, &size);
	*cols = size.ws_col;
	*rows = size.ws_row;

}

int test() {
	return 1;
}

