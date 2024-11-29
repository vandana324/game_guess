#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Guesser {
    int guessedNumber;

public:
    int generateRandomNumber() {
        // Computer generates a random number between 1 and 100
        srand(time(0));
        guessedNumber = (rand() % 100) + 1;
        return guessedNumber;
    }

    int getGuessedNumber() {
        return guessedNumber;
    }
};

class Player {
public:
    int takePlayerGuess() {
        int playerGuess;
        cout << "Enter your guess (1-100): ";
        while (true) {
            cin >> playerGuess;
            if (playerGuess >= 1 && playerGuess <= 100) {
                break;
            } else {
                cout << "Invalid input. Please enter a number between 1 and 100: ";
            }
        }
        return playerGuess;
    }
};

class Umpire {
    int computerNumber;
    int playerGuess;
    int attempts;

public:
    Umpire() : attempts(0) {}

    void setComputerNumber() {
        Guesser guesser;
        computerNumber = guesser.generateRandomNumber();
    }

    bool getPlayerGuess() {
        Player player;
        playerGuess = player.takePlayerGuess();
        attempts++;
        return checkGuess();
    }

    bool checkGuess() {
        if (playerGuess == computerNumber) {
            cout << "\nCongratulations! You guessed it right in " << attempts << " attempts!\n";
            return true;
        } else if (playerGuess < computerNumber) {
            cout << "Your guess is too low. Try again!\n";
        } else {
            cout << "Your guess is too high. Try again!\n";
        }
        return false;
    }

    void playGame() {
        bool guessedCorrectly = false;
        while (attempts < 10 && !guessedCorrectly) {  // Limit attempts to 10
            guessedCorrectly = getPlayerGuess();
        }
        if (!guessedCorrectly) {
            cout << "\nGame Over! You've used all 10 attempts. The correct number was " << computerNumber << ".\n";
        }
    }
};

int main() {
    char playAgain;

    cout << "------ Welcome to the Guesser Game ------\n";

    do {
        Umpire umpire;
        umpire.setComputerNumber();
        umpire.playGame();

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "------ Thank you for playing! ------\n";
    return 0;
}
