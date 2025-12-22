/* Advent of Code 2025 solution by zo3
 * Day 1: Secret Agent
 * https://adventofcode.com/2025/day/1
 * Solves in 0.008 seconds (real time measured with the linux time command) on a slow chromebook
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
            // printf("Number: %i\n", numBuffer);

            if (direction == true) {
                dialPosition += numBuffer;
            } else {
                dialPosition -= numBuffer;
            }

            /* Use modulo so that we can handle large numbers without a for loop */
            dialPosition = ((dialPosition % 100) + 100) % 100;

            if (dialPosition == 0) {
                zeroCount++;
            }

            // printf("Dial Position: %i\n", dialPosition);

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