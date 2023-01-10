#include "my_mastermind.h"

// ./my_mastermind -c "0123" -t 6

int main(int ac, char **av) {
    // * blah blah
    // ! alert
    // ? what up
    // TODO

    char* code = malloc(4 * sizeof(char));
    char* secret_code = malloc(4 * sizeof(char));

    // * DEALING WITH COMMAND LINE INPUTS --------------------------------------------------------------

    if (ac == 1) {
        printf("only 1 argument passed i.e. ./my_mastermind\n");
        secret_code = generate_code(code);
    } else if (ac == 3) {
        // av[1] == "-c" || av[1] == "-t"
        for (int i = 1; i < ac - 1; i++) {
            if (strcmp(av[i], "-c") == 0) {
                if (validate_user_input(av[i + 1]) == true) {
                    printf("%s is valid input! \n", av[i + 1]);
                    // set code to user inputted code
                    int j = 0;
                    while (j < 4) {
                        code[j] = av[2][j];
                        j++;
                    }
                    secret_code = code;
                } else {
                    printf("%s is invalid! generating random code\n", av[i + 1]);
                    secret_code = generate_code(code);
                }
            } else {
                printf("no -c flag present! generating random code\n");
                secret_code = generate_code(code);
            }
        }
    } else if (ac == 5) {
        // av[1] == "-c" && av[3] == "-t"
        // validate av[2] and av[4]
        printf("5 arguments passed\n");
    } else {
        printf("incorrect number of arguments passed to command line\n");
        return 1;
    }

    // * PRINTING SECRET CODE TO CONSOLE ---------------------------------------------------------------
    // TODO remove for game
    printf("secret code: ASCII values\n");
    for (int i = 0; i < strlen(secret_code); i++) {
        printf("%c:%d ", secret_code[i], secret_code[i]);
    }
    printf("\n");

    // * PLAYING THE GAME ------------------------------------------------------------------------------

    printf("Will you find the secret code?\nPlease enter a valid guess.\n---\n");

    int attempts = 0;
    int rounds = 10;

    while (attempts < rounds) {
        printf("Round %d\n", attempts);

        // char c;
        // char* user_guess = malloc(4 * sizeof(char));
        // int i = 0;
        // label:

        // if (validate_user_input(user_guess) != true) {
        //     printf("Wrong input!\n");
        //     goto label;
        // }

        // ! how can I store the user input read from the console using pointers? such that I can use my validate_user_input function to validate that it is correct? instead of what I have below, the same function but it takes a string instead...

        // char user_guess[5];
        // int size;
        // label:
        // size = read(0, user_guess, sizeof(user_guess));

        // if (validate_user_input_string(user_guess) != true) {
        //     printf("Wrong input!\n");
        //     goto label;
        // }

        // for (int i = 0; i < 4; i++) {
        //     printf("user input: %c \n", user_guess[i]);
        // }

        printf("code was good, going to next round\n");

        char* guess = "3212";
        char* code = "1234";

        test_user_input(guess, code);

        attempts = 10;
    }

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