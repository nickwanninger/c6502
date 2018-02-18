#ifndef __6502_IO__
#define __6502_IO__

#include <ncurses.h>

WINDOW *win;




void screeninit();
void screenoff();
void centerwin();

#include "screen.c"

#endif