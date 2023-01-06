#ifndef MY_MASTERMIND_H
#define MY_MASTERMIND_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define CODE_LEN 4

bool my_isdigit(char character);
int my_strlen(const char *param_1);
char generate_number();
char* generate_code(char* code);

#endif