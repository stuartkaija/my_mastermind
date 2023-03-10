#ifndef MY_MASTERMIND_H
#define MY_MASTERMIND_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

bool my_isdigit(char character);
bool is_valid_rounds(int num);
char generate_number();
char* generate_code(char* code);
bool validate_user_input(char* param);
bool validate_user_input_string(char param[]);
int test_user_input(char* guess, char* code);
int my_strlen(const char *param_1);

#endif


