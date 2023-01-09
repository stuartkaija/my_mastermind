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
char* generate_code(char* param) {
    int i = 0;
    srand(time(NULL));
    while (i < 4) {
        param[i] = generate_number();
        i++;
    }
    return param;
}

// validate user input
// accepts user input, checks that it has a length of four and is composed of digits between/including 0 and 8

bool validate_user_input(char* param) {
    if (my_strlen(param) != 4) {
        // printf("Wrong input! Please enter a valid code\n");
        return false;
    }

    for (int i = 0; i < 4; i++) {
        if (param[i] < 48 || param[i] > 56) {
            // printf("Wrong input! Please enter a valid code\n");
            return false;
        }
    }
    return true;
}

// function to compare user_guess to secret_code
    // accepts user_guess and secret_code
    // needs to check for and return number of correctly placed pieces and misplaced pieces

int test_user_input(char* guess, char* code) {
    int well_placed = 0;
    int misplaced = 0;

    

    return 0;
}