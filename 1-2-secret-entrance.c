/* Advent of Code 2025 solution by zo3
 * Day 1: Secret Entrance Pt. 2
 * https://adventofcode.com/2025/day/1
 * Solves in 0.021 seconds (real time measured with the linux time command) on a slow chromebook
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/* Maximum length a line in the input file may be */
#define LINE_LENGTH 6
#define DIAL_STARTING_POSITION 50

int main() {
    /* ---------- FILE READING ----------- */
    FILE *inputFile = fopen("input1.txt", "r");
    char lineBuffer[LINE_LENGTH];
    char inputText[20000] = {0}; /* 20000 approximated from file, may be reduced for memory optimization */

    if (inputFile == NULL) {
        printf("ERROR: Failed to open input file: input1.txt (does it exist?)\n");
        return -1;
    }

    while (fgets(lineBuffer, LINE_LENGTH, inputFile) != NULL) {
        strcat(inputText, lineBuffer);
    }

    strcat(inputText, "\n");
    fclose(inputFile);

    /* ---------- DIAL LOGIC ---------- */
    int dialPosition = DIAL_STARTING_POSITION;
    int zeroCount = 0;
    int numBuffer;
    int lenBuffer;
    bool direction = true; /* false: left true: right*/
    char numChar[LINE_LENGTH - 2] = {0};

    for (int i = 0; inputText[i] != '\0'; i++) {
        if (inputText[i] == 'L') {
            direction = false;
        } else if (inputText[i] == 'R') { /* Could probably remove one of these for optimization */
            direction = true;
        } else if (inputText[i] == '\n' && numChar[0] != '\0') {
            numBuffer = atoi(numChar);

            for (int i = 0; i < numBuffer; i++) {
                if (direction == true) {
                    dialPosition++;
                } else {
                    dialPosition--;
                }

                /* Use modulo so that we can handle large numbers without a for loop */
                dialPosition = ((dialPosition % 100) + 100) % 100;

                if (dialPosition == 0) {
                    zeroCount++;
                }
            }

            numChar[0] = '\0';
        } else if (isdigit((unsigned char)inputText[i])) {
            lenBuffer = strlen(numChar);

            if (lenBuffer + 1 < sizeof(numChar)) {
                numChar[lenBuffer] = inputText[i];
                numChar[lenBuffer + 1] = '\0';
            }
        }
    }

    printf("%i\n", zeroCount);
}
