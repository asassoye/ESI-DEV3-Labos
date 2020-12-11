/**
 * @file main.c
 * @author Andrew SASSOYE
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include "../resources/mathesi.h"
#include "str.h"

#define OPTSTR "v:h"

int main(int argc, char *argv[]) {
    int opt;
    bool extended = true;

    while ((opt = getopt(argc, argv, OPTSTR)) != EOF)
        switch (opt) {
            case 'v':
                extended = false;
                break;

            case 'h':
            default:
                puts("How to use: [-v (exponent)] number");
                return EXIT_SUCCESS;
        }

    int number = atoi(argv[argc - 1]);

    printPrimeFactor(number, extended);

    return EXIT_SUCCESS;
}

int main2() {
    char string[] = "Andrew";

    printf("\"%s\" is %lu characters long\n", string, strlen(string));

    char string2[] = "Hello World!";
    char string3[] = "Hello World!";

    printf("%d\n", strcmp(string2, string3));

    char string4[strlen(string) + 1];

    printf("Copied text: %s\n", strcpy(string4, string));

    printf("Partiel text: %s\n", strncpy(string4, string, 3));

    char str[50] = "Hello ";
    char str2[50] = "World!";
    strcat(str, str2);

    puts(str);

    char input[] = "A bird came down the walk";
    printf("Parsing the input string '%s'\n", input);
    char *token = strtok(input, " ");
    while (token) {
        puts(token);
        token = strtok(NULL, " ");
    }

    printf("Contents of the input string now: '");
    for (size_t n = 0; n < sizeof input; ++n)
        input[n] ? putchar(input[n]) : fputs("\\0", stdout);
    puts("'");

    return 0;
}
