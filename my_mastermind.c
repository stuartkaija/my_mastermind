#include "my_mastermind.h"

int main(int ac, char **av) {
    char* code = malloc(4 * sizeof(char));
    char* secret_code = malloc(4 * sizeof(char));
    int rounds = 10;

    if (ac == 1) {
        // printf("only 1 argument passed, code generated randomly\n");
        secret_code = generate_code(code);
    }

    // * DEALING WITH COMMAND LINE INPUTS --------------------------------------------------------------
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-c") == 0) {
            if (validate_user_input(av[i + 1]) == true) {
                printf("Code set successfully!\n");
                int j = 0;
                while (j < 4) {
                    code[j] = av[i + 1][j];
                    j++;
                }
                secret_code = code;
            } else if (validate_user_input(av[i + 1]) == false) {
                printf("%s is not a valid code, code will be generated randomly\n", av[i + 1]);
                secret_code = generate_code(code);
            }
        }

        if (strcmp(av[i], "-t") == 0) {
            if (ac == 3) {
                secret_code = generate_code(code);
            }

            if (is_valid_rounds(atoi(av[i + 1])) == true) {
                printf("valid rounds\n");
                rounds = atoi(av[i + 1]);
            } else {
                printf("You didn't pass valid information for rounds - rounds will be set to 10.\n");
            }
        }
    }

    // COMMENT OUT FOR GAME - this prints the secret code to console -----------------------------------
    
    printf("secret code: ");
    for (int i = 0; i < strlen(secret_code); i++) {
        printf("%c", secret_code[i]);
    }
    printf("\n");

    // * PLAYING THE GAME ------------------------------------------------------------------------------

    printf("Will you find the secret code?\nPlease enter a valid guess.\n---\n");

    int attempts = 0;

    while (attempts < rounds) {
        printf("Round %d\n", attempts + 1);

        char user_guess[100];
        char c;
        int i = 0;

        while (read(0, &c, 1) >= 0 && c != '\n') {
            user_guess[i] = c;
            // if (user_guess[i] == 0) {
            //     printf("EOT\n");
            //     return 1;
            // }
            // printf("user_guess[i] d, c: %d, %c\n", user_guess[i], user_guess[i]);
            i++;
        }

        user_guess[i] = '\0';

        printf("user_guess: %s\n", user_guess);

        // checking if user_guess is valid
        if (validate_user_input_string(user_guess) == true) {
            printf("user_guess is valid\n");
            if (test_user_input(user_guess, secret_code) == 0) {
                printf("Congratz! You did it!\n");
                return 0;
            }
            attempts++;
        } else {
            if (my_strlen(user_guess) == 0) {
                printf("EOT in validation section\n");
                return 0;
            }
            // loop through secret_code and check if control d was inputted i.e. if user_guess length is 0
            for (int i = 0; i < my_strlen(user_guess); i++) {
                printf("failed validation print, user_guess[%i]: %d\n" , i, user_guess[i]);
                if (user_guess[i] == 0) {
                    printf("EOT\n");
                    return 0;
                }
            }

            // if (user_guess[0] == 4) {
            //     printf("EOT in validation section\n");
            //     return 0;
            // }
            printf("user_guess is NOT valid\n");
        }
    }

    printf("KO! Game over! You did NOT find the secret code...the secret code was: ");
    for (int i = 0; i < strlen(secret_code); i++) {
        printf("%c", secret_code[i]);
    }
    printf("\n");

    return 0;
}

// char guess[100];
// while((count = read(STDIN_FILENO, guess, 100) > 0)&&rounds<attempts){
// }