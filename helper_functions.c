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

bool is_valid_rounds(int num) {
    if (num > 0 && num < 10) {
        return true;
    } else {
        return false;
    }
}

// validate user input to be 4 numbers *** make change to if statement 
// int my_strlen(const char *param_1) {
//     int count = 0;

//     while (*param_1 != '\0') {
//         count++;
//         param_1++;
//         if (count > 100) {
//             break;
//         }
//     }

//     return count;
// }

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
    if (strlen(param) != 4) {
        // printf("Wrong input! Please enter a valid code\n");
        return false;
    }

    // TODO use my_isdigit function here? or get rid of that function
    for (int i = 0; i < 4; i++) {
        if (param[i] < 48 || param[i] > 56) {
            // printf("Wrong input! Please enter a valid code\n");
            return false;
        }
    }
    return true;
}

bool validate_user_input_string(char param[]) {
    if (strlen(param) != 5) {
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

int test_user_input(char* guess, char* code) {
    int well_placed = 0;
    int misplaced = 0;
    int i, j;

    //  guess is 3456, code is 1212
    for (i = 0; i < 4; i++) {

        for (j = 0; j < 4; j++) {
            if (i == j && guess[i] == code[j]) {
                well_placed++;
                break;
            }
            
            if (i != j && guess[i] == code[i]) {
                well_placed++;
                break;
            }

            if (i != j && guess[i] == code[j]) {
                // printf("is this doing anything?\n");
                misplaced++;
                break;
            }
        }
        
        if (well_placed == 4) {
            // printf("Congratz! You did it!\n");
            return 0;
        }
    }

    printf("well_placed: %d\nmisplaced: %d\n---\n", well_placed, misplaced);

    return 1;
}