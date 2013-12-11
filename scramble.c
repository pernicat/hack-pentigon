#include <stdlib.h>
#include <stdio.h>

#define BYTE 8
#define NIBBLE 4

short scramble(short old, char trade[], int size) {
    short new = 0;
    
    int i;
    for (i = 0; i < size; i++) {
        if (((1 << i) & old) == 0) {
            continue;
        }
        new = new | (1 << trade[i]);
    }

    return new;
}

int getShuffleSize(void) {
}

void getShuffle(char shuffle[], int size) {
    int swap, temp, i;

    for (i = 0; i < size; i++) {
        shuffle[i] = i;
    }
    for (i = 0; i < size; i++) {
        swap = random() % size;
        temp = shuffle[swap];
        shuffle[swap] = shuffle[i];
        shuffle[i] = temp;
    }
}


int main(void) {
    // Test shuffle
    int size = sizeof(char) * BYTE;
    
    short new, old = (char) random();
    
    char shuffle[size];
    getShuffle(shuffle, size);

    new = scramble(old, shuffle, size);

    printf("%X -> %X\n", old, new);
    
    int i;
    for (i = 0; i < size; i++) {
        printf("%x:%x - %x:%x\n", 
              ((old >> i) & 1),
                i, shuffle[i], 
              ((new >> i) & 1));
    }

    int foo;
    for (i = 0; i <= 0xff; i++) {
        foo = scramble(i, shuffle, size);
        printf("%02X - %02X\n", i, foo);
    }

    return 0;
}
