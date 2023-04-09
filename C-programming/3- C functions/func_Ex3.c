/*
 * func_Ex3.c
 *
 *  Created on: Mar 23, 2023
 *      Author: KARIM
 *  Reverse a sentence by recursion
 */

#include <stdio.h>
void reverseSentence();

int main() {
    printf("Enter a sentence: \n");
    reverseSentence();
    return 0;
}

void reverseSentence() {
    char c;
    scanf("%c", &c);
    if (c != '\n') {
        reverseSentence();
        printf("%c", c);
    }
}
