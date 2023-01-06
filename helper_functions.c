#include "my_mastermind.h"

// validate that user input is a digit
bool my_isdigit(char character) {
    int targetInt = (int)character;
    if (targetInt >= 48 && targetInt <= 57) {
        return true;
    } else {
        return false;
    }
}

// validate user input to be 4 numbers *** make change to if statement 
int my_strlen(const char *param_1) {
    int count = 0;

    while (*param_1 != '\0') {
        count++;
        param_1++;
        if (count > 100) {
            break;
        }
    }

    return count;
}

// generate random number
char generate_number() {
    char num = rand() % (56 - 48 + 1 ) + 48;
    return num;
}

// generate secret code
char* generate_code(char* code) {
    int i = 0;
    srand(time(NULL));
    printf("FROM GENERATE_CODE:\n");
    while (i < 4) {
        code[i] = generate_number();
        printf("code[%d]: %d \n", i, code[i]);
        i++;
    }
    return code;
}