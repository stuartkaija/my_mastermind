#include "my_mastermind.h"

// ./my_mastermind -c "0123" -t 6

int main(int ac, char **av) {
    // * blah blah
    // ! alert
    // ? what up
    // TODO

    char* code = malloc(4 * sizeof(char));
    char* secret_code = malloc(4 * sizeof(char));
    int rounds = 10;

    // * DEALING WITH COMMAND LINE INPUTS ------------------------------------------------------------

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

    // * PRINTING SECRET CODE TO CONSOLE ------------------------------------------------------------
    // ! (remove for game)
    printf("secret code: ASCII values\n");
    for (int i = 0; i < strlen(secret_code); i++) {
        printf("%c:%d ", secret_code[i], secret_code[i]);
    }
    printf("\n");

    // * PLAYING THE GAME --------------------------------------------------------------------------------

    printf("Will you find the secret code?\nPlease enter a valid guess.\n---\n");

    int attempts = 0;
    while (attempts < rounds) {
        printf("Round %d\n", attempts);

        char c;
        char* user_guess = malloc(4 * sizeof(char));

        for (int i = 0; i < 4; i++) {
            read(0, &c, 1);
            user_guess[i] = c;
        }

        // this prints the user input to the console
        printf("Numbers entered: ASCII codes - \n");
        for (int i = 0; i < 4; i++) {
            printf("%c:%d ", user_guess[i], user_guess[i]);
            // validate_user_input(user_guess, i);
        }
        printf("\n");

        attempts++;
    }
    // // accept user input
    // char c;
    // char* user_guess = malloc(4 * sizeof(char));

    // for (int i = 0; i < 4; i++) {
    //     read(0, &c, 1);
    //     user_guess[i] = c;
    // }

    // // this prints the user input to the console
    // printf("Numbers entered: ASCII codes are:\n");
    // for (int i = 0; i < 4; i++) {
    //     printf("%c:%d ", user_guess[i], user_guess[i]);
    //     // validate_user_input(user_guess, i);
    // }
    // printf("\n");


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