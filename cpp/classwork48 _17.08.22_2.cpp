// STEP _CPP _classwork48 _17.08.22_2
/*
ООП

Files


*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>


int main(int argc, char* argv[])
{

    char str[7] = "000000";
    char filehtml[256]="<html><head><title> New file!!!</title></head> <body bgcolor = '#";
    char htmlEnd[100] = "'></body></html>";

        // '></body></html>
    FILE* f = fopen("cw48html.html", "w");

    if (argc == 2) {
        strcpy(str, argv[1]);

    }
    strcat(strcat(filehtml, str), htmlEnd);

    fputs(filehtml, f);
    fclose(f);
    std::cout << "OK" << std::endl;

    return 0;
}
