/* Advent of Code 2025 solution by zo3
 * Day 2: Gift Shop Pt. 1
 * https://adventofcode.com/2025/day/2
 * Solves in x seconds (real time measured with the linux time command) on a slow chromebook
*/

/* Idea:
 * Check for repeating by splitting the number in half and comparing the two halves. (e.g. 1010 -> 10 & 10 = invalid)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/* Defines the length in characters of the input file array */
#define FILE_SIZE 500
#define MAX_NUM_LENGTH 50 /* 10 */

int main() {
    FILE *inputFile = fopen("input2.txt", "r");
    char inputText[FILE_SIZE] = {0};

    if (inputFile == NULL) {
        printf("ERROR: Failed to open input file: input2.txt (does it exist?)\n");
        return -1;
    }

    if (fgets(inputText, FILE_SIZE, inputFile) == NULL) {
        printf("ERROR: Failed to read from file: input2.txt (is it empty?)\n");
        return -1;
    }

    fgets(inputText, FILE_SIZE, inputFile);
    fclose(inputFile);

    int lenBuffer;
    long numBuffer = 0;
    long num1;
    long num2;
    long answer = 0;
    char numChar[MAX_NUM_LENGTH] = {0};

    for (int i = 0; i <= strlen(inputText); i++) {
        if (isdigit((unsigned char)inputText[i])) {
            lenBuffer = strlen(numChar);

            if (lenBuffer + 1 < sizeof(numChar)) {
                numChar[lenBuffer] = inputText[i];
                numChar[lenBuffer + 1] = '\0';
            }
        } else if (inputText[i] == '-') {
            num1 = atol(numChar);
            numChar[0] = '\0';

        } else if (inputText[i] == ',' || inputText[i] == '\0') {
            num2 = atol(numChar);
            numChar[0] = '\0';

            for (long i = num1; i <= num2; i++) {
                snprintf(numChar, MAX_NUM_LENGTH, "%ld", i);
                lenBuffer = strlen(numChar);

                if (lenBuffer % 2 == 0) {
                    for (int j = 0; j < lenBuffer / 2; j++) {
                        if (numChar[j] != numChar[j + (lenBuffer / 2)]) { /* TODO: Handle odd numbers */
                            break;
                        }

                        if (j == (lenBuffer / 2) - 1) {
                            answer += i;
                        }
                    }
                } else {
                    for (int j = 0; j < lenBuffer; j++) {
                        if (j == 0) { numBuffer = numChar[j]; }

                        if (numChar[j] != numBuffer) { break; }

                        if (j == lenBuffer - 1) { answer += i; }
                    }
                }

                numChar[0] = '\0'; /* May be able to move this out of this for loop */
            }
        }
    }

    printf("%ld\n", answer);
}
