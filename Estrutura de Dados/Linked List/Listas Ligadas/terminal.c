//
// Created by Edinho on 27/04/2024.
//
#include <stdio.h>
#include "terminal.h"
#include <string.h>
#include <malloc.h>
int maxsize;
int size = 60;
char *title;

void terminal(char *t, char **options, int qOptions) {
    title = t;
    maxsize = size + strlen(t);
    printTitle(title);


    for (int i = 0; i < qOptions; ++i) {
        printOption(options[i]);
    }
    for (int i = 0; i < maxsize; ++i) {
        printf("-");
    }
    printf("\n");
}

static void printTitle(char *t) {
    for (int i = 0; i < maxsize; ++i) {
        printf("-");
    }
    printf("\n");

    int halfSize = 30;

    for (int i = 0; i < size+ strlen(t); ++i) {
        switch ( i ) {
            case 0:
                printf("-");
                break;
            case 30:
                printf("%s", t);
                break;
            case 60:
                printf("-");
            default:
                printf(" ");

        }
    }
    printf("\n");
    for (int i = 0; i < strlen(t) + size; ++i) {
        printf("-");
    }
    printf("\n");
}

static void printOption(char *o) {
    printf("-");

    for (int i = 0; i < 4; ++i) {
        printf(" ");
    }

    printf("%s", o);

    int digitedChars;
    digitedChars = 6 + strlen(o);
    for (int i = 0; i < maxsize - digitedChars; ++i) {
        printf(" ");
    }
    printf("-");
    printf("\n");

}