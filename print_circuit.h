#ifndef PRINT_CIRCUIT_H
#define PRINT_CIRCUIT_H
#include <stdio.h>
#include <windows.h>

void print_chosen_circuit(char choice) {
    switch(choice) {
        case '1':
            printf("Circuit 1\n");
            printf("●─┬────────▆▆▆──────◠◠◠◠──┬─●\n"
               "  │         R         L     │\n"
               "  │                         │\n"
               "  │               C         │\n"
               "  └───────────────││────────┘\n");
            break;
        case '2':
            printf("Circuit 2\n");
            printf("   o----[R]--------|C|------o\n");
            printf("   |                        |\n");
            printf("   |                        |\n");
            printf("   |                        |\n");
            printf("   |                        |\n");
            printf("   o---------{L}------------o\n\n");
            break;
        case '3':
            printf("Circuit 3\n");
            printf("   o----[R2]--------|C|-------o\n");
            printf("   |                          |\n");
            printf("   |                          |\n");
            printf("  [R1]                        |\n");
            printf("   |                          |\n");
            printf("   |                          |\n");
            printf("   o---------{L}--------------o\n\n");
            break;
        case '4':
            printf("Circuit 4\n");
            printf("   o----[R2]------------------o\n");
            printf("   |                          |\n");
            printf("  [R1]                        |\n");
            printf("   |                          |\n");
            printf("   |                          |\n");
            printf("  |C|                         |\n");
            printf("   o---------{L}--------------o\n\n");
            break;
        default:
            printf("Error\n");
            break;
    }
}
void print_all_circuits()
{
    printf("Circuit 1\n");
    printf("   o----[R]-----------{L}---o\n");
    printf("   |                        |\n");
    printf("   |                        |\n");
    printf("   |                        |\n");
    printf("   |                        |\n");
    printf("   o---------|C|------------o\n\n");

    printf("Circuit 2\n");
    printf("   o----[R]--------|C|------o\n");
    printf("   |                        |\n");
    printf("   |                        |\n");
    printf("   |                        |\n");
    printf("   |                        |\n");
    printf("   o---------{L}------------o\n\n");

    printf("Circuit 3\n");
    printf("   o----[R2]--------|C|-------o\n");
    printf("   |                          |\n");
    printf("   |                          |\n");
    printf("  [R1]                        |\n");
    printf("   |                          |\n");
    printf("   |                          |\n");
    printf("   o---------{L}--------------o\n\n");

    printf("Circuit 4\n");
    printf("   o----[R2]------------------o\n");
    printf("   |                          |\n");
    printf("  [R1]                        |\n");
    printf("   |                          |\n");
    printf("   |                          |\n");
    printf("  |C|                         |\n");
    printf("   o---------{L}--------------o\n\n");
}
#endif
