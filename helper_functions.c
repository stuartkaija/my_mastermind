#include <stdbool.h>


// validate that user input is a digit
bool my_isdigit(char character) {
    int targetInt = (int)character;
    if (targetInt >= 48 && targetInt <= 57) {
        return true;
    } else {
        return false;
    }
}

// validate user input to be 4 numbers
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

//