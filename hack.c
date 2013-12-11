#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
//TODO use usleep
//TODO use getopt
//TODO use termios?
//TODO use ncurses?

#define C4 261.626
#define DONE 1000

#define KILA 1000
#define MILA 1000000
#define NANO 1000000000

#define PAUSE 1000

void delay(void) {

    double freq = 0;
    unsigned int pause = PAUSE;
    unsigned int now = 0;
    unsigned int start = 0;
    double elapsed;

    while(freq < DONE) {
        now = now + pause;
        elapsed = ((double) (now - start)) / PAUSE;
        freq = pow(2.0, (elapsed / 6.0));
        pause = ((unsigned int) (PAUSE / freq));
        usleep(pause);
        printf("now: %d, elapsed: %f, freq: %f, pause: %d\a\n", 
                now, elapsed, freq, pause);
    }
    printf("Done\n");
}

int main() {
    delay();
    return 0;
}
