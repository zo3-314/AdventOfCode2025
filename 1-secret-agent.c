#include <stdio.h>
#include <string.h>

/* Maximum length a line in the input file may be - Set this to 4 once the program is working for optimization */
#define LINE_LENGTH 10

int main() {
    /* ---------- FILE READING ----------- */
    FILE *inputFile;
    char lineBuffer[LINE_LENGTH];
    char inputText[20000]; /* 20000 approximated from file, may be reduced for optimization */

    inputFile = fopen("input1.txt", "r");

    if (inputFile == NULL) {
        printf("ERROR: Failed to open input file: input1.txt (does it exist?)\n");
        return -1;
    }

    while (fgets(lineBuffer, LINE_LENGTH, inputFile) != NULL) {
        strcat(inputText, lineBuffer);
    }

    fclose(inputFile);

    strcat(inputText, "\n");

    printf("%s", inputText);
}