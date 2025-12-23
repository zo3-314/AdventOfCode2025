/* Advent of Code 2025 solution by zo3
 * Day 3: Lobby Pt. 1
 * https://adventofcode.com/2025/day/3
 * Solves in 0.005 seconds (real time measured with the linux time command) on a slow chromebook
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/* Maximum length a line in the input file may be (100/101) */
#define LINE_LENGTH 101

int main() {
    FILE *inputFile = fopen("input3.txt", "r");
    char lineBuffer[LINE_LENGTH];
    long answer = 0;

    if (inputFile == NULL) {
        printf("ERROR: Failed to open input file: input3.txt (does it exist?)\n");
        return -1;
    }

    while (fgets(lineBuffer, LINE_LENGTH, inputFile) != NULL) {
        int num1 = 0;
        int num2 = 0;

        for (int i = 0; i < strlen(lineBuffer) && isdigit(lineBuffer[i]); i++) {
            int curNum = lineBuffer[i] - 48;

            if (i == 0) { num1 = curNum; num2 = 0; continue; }

            if (curNum > num1 && i != strlen(lineBuffer) - 1) {
                num1 = curNum;
                num2 = 0;
            } else if (curNum > num2) {
                num2 = curNum;
            }

            if (i == strlen(lineBuffer) - 1) {
                char numChar[2];
                snprintf(numChar, 3, "%d%d", num1, num2);
                answer += atoi(numChar);
            }
        }
    }

    fclose(inputFile);

    printf("%ld\n", answer);

    return 0;
}
