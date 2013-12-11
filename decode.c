#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "cypher/subbox.h"

#define N_MAX 0xffff
#define COUNT 0xff

#define CODE_SIZE 16
#define FORMAT "%02X"
#define WIDTH 3

#define PAUSE 100000

void center_text(char str[]) {
    int row, col;
    int y, x;
    getmaxyx(stdscr, row, col);

    size_t len = strlen(str);

    y = row / 2;
    x = (col - len) / 2;

    mvprintw(y, x, str);
}

void center_array(unsigned char code[], int len) {
    int row, col;
    int y, x;
    getmaxyx(stdscr, row, col);
    
    int i;

    y = row / 2;
    x = (col - (WIDTH * len)) / 2;
    for (i = 0; i < len; i++) {
        mvprintw(y, x, FORMAT, code[i]);
	    x = x + WIDTH;
    }
}

int main (void) {
    
    int i, j;
    unsigned char code[CODE_SIZE];
    unsigned char guess[CODE_SIZE];	
    unsigned char mask[CODE_SIZE];

    initscr();
    
    curs_set(0);

    for (i = 0; i < CODE_SIZE; i++) {
       code[i] = (unsigned char) random();
       mask[i] = (unsigned char) random();
       guess[i] = subbytes((mask[i] ^ i));
    }
    
    mvprintw(1,1, "Test This");

    for (i = 0; i < COUNT; i++) {
        for (j = 0; j < CODE_SIZE; j++ ) {
            if (guess[j] != code[j]) {
                guess[j] = subbytes(mask[j] ^ i);
            }
        }
        center_array(guess, CODE_SIZE);
        usleep( PAUSE );
        refresh();
    }
    
    mvprintw(4, 6, "Welcome to the pentagon!");

    curs_set(1);
    getch();
    
    endwin();
    
    printf("done...\n");

    return 0;
}
