#include <ncurses.h>
#include "io.h"

short COLOR_FG = 255;
short COLOR_BG = 254;


void screenconfigure() {
	cbreak();
	noecho();
}

void screeninit() {

	initscr();
	screenconfigure();

	int height = 25;
	int width = 80;
	int y = 1; //(LINES - height) / 2;
	int x = 2; //(COLS - width) / 2;
	
	win = newwin(height, width, y, x);
	

	start_color();

	init_color(COLOR_FG, 0, 1000, 0);
	init_color(COLOR_BG, 0, 0, 0);
	init_pair(1, COLOR_FG, COLOR_BG);

	wbkgd(win, COLOR_PAIR(1));
	
	wrefresh(win);


	refresh();

}


void screenoff() {
	endwin();
}