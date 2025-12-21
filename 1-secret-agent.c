#include <stdio.h>

int main() {
    FILE *inputFile;

    inputFile = fopen("input1.txt", "r");

    char inputText[15000];

    fgets(inputText, 15000, inputFile);

    fclose(inputFile);

    printf("%s", inputText);
}