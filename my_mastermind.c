#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int generate_number() {
    int num = rand() % 9;
    return num;
}

int main(int ac, char **av) {
    int secret_code[5] = {};

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            secret_code[i] = '\0';
            printf("%d\n", secret_code[i]);
            break;
        }
        secret_code[i] = generate_number();
        printf("%d\n", secret_code[i]);
    }

    printf("Will you find the secret code?\nPlease enter a valid guess.\n");

    // accept user input, it needs to be numbers between 0 and 8 (or 9?), and the user must type in four numbers
    // I believe this will be accepted in as chars, we can store them in a string, then convert to ints, or vice versa?
    char c;
    int numbers[4];

    for (int i = 0; i < 4; i++) {
        read(0, &c, 1);
        numbers[i] = atoi(&c);
    }

    printf("The numbers you entered are: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", numbers[i]);
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