#pragma warning(disable:4996)

#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

/*
    Source by AlphaCodingSkills
    Modified For Learn by RK
    I.D.E : VS2019
*/

void WriteFormatted(FILE* stream, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stream, format, args);
    va_end(args);
}

int main() {
    //open the file in write and read mode
    FILE* pFile = fopen("test.txt", "w+");

    WriteFormatted(pFile, "Calling with %d variable argument.\n", 1);
    WriteFormatted(pFile, "Calling with %d variable %s.\n", 2, "arguments");
    WriteFormatted(pFile, "Calling with %d %s %s.\n", 3, "variable", "arguments");

    //set the position to the start
    rewind(pFile);

    //display the content of the file
    int c = getc(pFile);

    while (c != EOF) {
        putchar(c);
        c = getc(pFile);
    }

    //close the file
    fclose(pFile);

    _getch();
    return 0;
}