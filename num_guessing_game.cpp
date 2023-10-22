#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // Seed for random number generation
    int randomNumber = (rand() % 50) + 1; // Generating random number between 1 to 50

    int guessedNumber;
    int attempts = 0;
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Guess a number between 1 to 50: ";
        std::cin >> guessedNumber;

        if (guessedNumber > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guessedNumber < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        }

        attempts++;
    } while (guessedNumber != randomNumber);

    std::cout << "Congratulations! You guessed the correct number " << randomNumber << " in " << attempts << " attempts." << std::endl;

    return 0;
}
