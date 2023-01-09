#include "my_mastermind.h"

// ./my_mastermind -c "0123" -t 6

int main(int ac, char **av) {
    // * blah blah
    // ! alert
    // ? what up
    // TODO

    char* code = malloc(4 * sizeof(char));
    char* secret_code = malloc(4 * sizeof(char));

    // * LOOP THROUGH CLI INPUT
    // * ./my_mastermind -c 1234 -t 5

    if (ac == 1) {
        printf("only 1 argument passed i.e. ./my_mastermind\n");
        secret_code = generate_code(code);
    } else if (ac == 3) {
        // av[1] == "-c" || av[1] == "-t"
        // validate av[2]
    } else if (ac == 5) {
        // av[1] == "-c" && av[3] == "-t"
        // validate av[2] and av[4]
    } else {
        printf("incorrect number of inputs");
        EXIT_FAILURE;
    }

    for (int i = 0; i < ac; i++) {
        if (ac == 1) {
            printf("only 1 argument passed i.e. ./my_mastermind\n");
            secret_code = generate_code(code);
            // for (int j = 0; j < strlen(code); j++) {
            //     printf("%c \n", code[j]);
            // }
            break;
        }

        if (strcmp(av[i], "-c") == 0) {
            // check if following is valid input
            if (validate_user_input(av[i + 1]) == true) {
                printf("%s is valid input! \n", av[i + 1]);
                // set code to user inputted code
                int j = 0;
                while (j < 4) {
                    code[j] = av[2][j];
                    j++;
                }
            }
            break;
        } else {
            printf("%s is invalid! code will be generated randomly \n", av[i + 1]);
            secret_code = generate_code(code);
        }
    }

    printf("user input code: ASCII values\n");
    for (int i = 0; i < strlen(code); i++) {
        printf("%c:%d ", code[i], code[i]);
    }
    printf("\n");

    // this prints the secret code to the console
    printf("secret code: ASCII values\n");
    for (int i = 0; i < strlen(secret_code); i++) {
        printf("%c:%d ", secret_code[i], secret_code[i]);
    }
    printf("\n");

    printf("Will you find the secret code?\nPlease enter a valid guess.\n");

    // accept user input
    char c;
    char* user_guess = malloc(4 * sizeof(char));

    for (int i = 0; i < 4; i++) {
        read(0, &c, 1);
        user_guess[i] = c;
    }

    // this prints the user input to the console
    printf("Numbers entered: ASCII codes are:\n");
    for (int i = 0; i < 4; i++) {
        printf("%c:%d ", user_guess[i], user_guess[i]);
        // validate_user_input(user_guess, i);
    }
    printf("\n");

    // validation??? unsure how to implement

    return 0;
}



// ---------------------------------------------------------------------------------------------------------------------------------------
// PROMPT>./my_mastermind -c "0123"
// Will you find the secret code?
// Please enter a valid guess
// ---
// Round 0
// >1456
// Well placed pieces: 0
// Misplaced pieces: 1
// ---
// Round 1
// >tata
// Wrong input!
// >4132
// Well placed pieces: 1
// Misplaced pieces: 2
// ---
// Round 2
// >0123
// Congratz! You did it!