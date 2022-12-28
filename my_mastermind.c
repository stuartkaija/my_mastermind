#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int generate_number() {
    int num = rand() % 9;
    return num;
}

int main(int ac, char **av) {
    int secret_code[4] = {};

    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        secret_code[i] = generate_number();
    }

    // return secret_code;
    // currently generating random number that is ~10 digits long, we just need 4 digits, and likely it'll make the most sense to store them in an array

    return 0;
}

// initial prompt, on launching the program via the command line, will also take in the secret code with the flag "-c" i.e. ./my_mastermind -c "0123" - if the c flag is omitted, a random code will be generated, i.e. if ac is 1, generate the random code - except we're using a make file, so not sure how this will be implemented yet

// code to generate random 4 digits
// code to accept player's input
// code to compare player's input to secret code, checking and keeping track of well placed pieces and misplaced pieces
    // check if input is correct i.e. digits from 0 to 8
    // for well placed pieces - should this be stored globally, so as when it reaches 4 (i.e. all pieces are well placed), the player has won the game?

// the count for well placed pieces and misplaced pieces will then be displayed to the player
// code to keep track of rounds (there are 10 rounds)


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