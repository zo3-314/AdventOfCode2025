#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/* Maximum length a line in the input file may be */
#define LINE_LENGTH 6

int main() {
    /* ---------- FILE READING ----------- */
    FILE *inputFile;
    char lineBuffer[LINE_LENGTH];
    char inputText[20000] = {0}; /* 20000 approximated from file, may be reduced for memory optimization */

    inputFile = fopen("input1.txt", "r");

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
    int dialPosition = 50;
    int zeroCount = 0;
    int numBuffer = 0;
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