// Goal: Create a program...
// that lets the user pick between 0-100...
// and tells the user if the right ans is
// higher or lower than the selected number
// so the user can narrow down his search.
// "binary search game"

#include <iostream>
#include <cstdlib>
// from http://www.cplusplus.com/reference/cstdlib/rand/:
#include <stdio.h> // for NULL
#include <stdlib.h> // for srand
#include <time.h> // for time

int main() {

    srand (time(NULL));

    int guess;
    int tries = 0;
    int min = 1;
    int max = 100;
    int answer = rand() % 100 + 1;;
    char replay = 'y';

    std::cout << "\nPick between 1 and 100. Try to guess the number!\n";
    std::cout << "You'll find out if its too high or too low.\n";

    while (guess != answer && tries < 12) {
        std::cout << "Guess the number, between " << min << " and " << max << ": ";
        std::cin >> guess;
        tries++;

        if (guess > answer) {
            std::cout << "Wrong answer! You guessed too high.\n";
            if (guess < max) {
                max = guess;
            };
        } else if (guess < answer) {
            std::cout << "Wrong answer! You guessed too low.\n";
            if (guess > min) {
                min = guess;
            };
        } else {
            std::cout << "Congrats! You guessed right! Replay? ";
            std::cin >> replay;
            if (replay == 'y') {
                std::cout << "\nOkay! New Game!\n";
                main();
            } else {
                break;
            }
        }
    } 
}