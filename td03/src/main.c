/**
 * @file main.c
 * @author Andrew SASSOYE
 */

#include <stdio.h>
#include "str.h"

int main() {
    char string[] = "Andrew";

    printf("\"%s\" is %lu characters long\n", string, strlen(string));

    char string2[] = "Hello World!";
    char string3[] = "Hello World!";

    printf("%d\n", strcmp(string2, string3));

    char string4[strlen(string) + 1];

    printf("Copied text: %s\n", strcpy(string4, string));

    printf("Partiel text: %s\n", strncpy(string4, string, 3));
}
