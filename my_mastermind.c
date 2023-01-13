#include "my_mastermind.h"

int main(int ac, char **av) {
    // * blah blah
    // ! alert
    // ? what up
    // TODO

    char* code = malloc(4 * sizeof(char));
    char* secret_code = malloc(4 * sizeof(char));
    int rounds = 10;

    if (ac == 1) {
        printf("only 1 argument passed, code generated randomly\n");
        secret_code = generate_code(code);
    }

    // * DEALING WITH COMMAND LINE INPUTS --------------------------------------------------------------
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-c") == 0) {
            if (validate_user_input(av[i + 1]) == true) {
                printf("%s is valid code\n", av[i + 1]);
                int j = 0;
                while (j < 4) {
                    code[j] = av[i + 1][j];
                    j++;
                }
                secret_code = code;
            } else if (validate_user_input(av[i + 1]) == false) {
                printf("%s is not a valid code\n", av[i + 1]);
                secret_code = generate_code(code);
            }
        }

        if (strcmp(av[i], "-t") == 0) {
            printf("-t flag present\n");
            printf("after the t flag is %s\n", av[i + 1]);
            printf("a to i av[i+1] is %d\n", atoi(av[i + 1]));

            // if av[i + 1] is a number, it's valid for rounds - how do we check if av[i + 1] is a number...
            if (atoi(av[i + 1] > 0) && atoi(av[i + 1]) < 10) {
                printf("av[i + 1] is %s\n", av[i + 1]);
                printf("atoi(av[i + 1]) %d\n", atoi(av[i + 1]));
            }


            if (is_valid_rounds(av[i + 1]) == true) {
                printf("valid rounds\n");
                rounds = atoi(av[i + 1]);
            } else {
                printf("not valid rounds\n");
            }
            if (atoi(av[i + 1]) > 0 || atoi(av[i + 1]) < 10) {
                printf("atoi(av[i + 1]) is %d", atoi(av[i + 1]));
                printf("%s is valid rounds\n", av[i + 1]);
                // rounds = 5;
                // printf("ROUNDS SET TO %d\n", rounds);
            } else {
                printf("%s not valid rounds\n", av[i + 1]);
            }
        }
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
    // rounds = 10;

    while (attempts < rounds) {
        printf("Round %d\n", attempts);

        char user_guess[128];
        int size;
        label:
        size = read(0, user_guess, sizeof(user_guess));

        if (validate_user_input_string(user_guess) == true) {
            if (test_user_input(user_guess, secret_code) == 0) {
                printf("Congratz! You did it!\n");
                return 0;
            }
        } else {
            printf("Wrong input, user_guess: %s\n", user_guess);
            goto label;
        }
        
        attempts++;
    }

    printf("KO! Game over! You did NOT find the secret code...the secret code was: ");
    for (int i = 0; i < strlen(secret_code); i++) {
        printf("%c", secret_code[i]);
    }
    printf("\n");

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