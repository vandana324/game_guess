#include<iostream>
using namespace std;

class Guesser {
    int guessedNumber;

public:
    int takeGuesserInput() {
        cout << "Guesser, please input your number (1-100): ";
        while (true) {
            cin >> guessedNumber;
            if (guessedNumber >= 1 && guessedNumber <= 100) {
                break;
            } else {
                cout << "Invalid input. Please enter a number between 1 and 100: ";
            }
        }
        return guessedNumber;
    }
};

class Player {
    int playerNumber;

public:
    int takePlayerInput(int playerID) {
        cout << "Player " << playerID << ", enter your guess (1-100): ";
        while (true) {
            cin >> playerNumber;
            if (playerNumber >= 1 && playerNumber <= 100) {
                break;
            } else {
                cout << "Invalid input. Please enter a number between 1 and 100: ";
            }
        }
        return playerNumber;
    }
};

class Umpire {
    int guessedNumber;
    int p1Number, p2Number, p3Number;

public:
    void getNumberFromGuesser() {
        Guesser guesser;
        guessedNumber = guesser.takeGuesserInput();
    }

    void getNumberFromPlayers() {
        Player player;
        p1Number = player.takePlayerInput(1);
        p2Number = player.takePlayerInput(2);
        p3Number = player.takePlayerInput(3);
    }

    void printResult() {
        cout << "\n--- Game Results ---\n";
        bool player1Won = (guessedNumber == p1Number);
        bool player2Won = (guessedNumber == p2Number);
        bool player3Won = (guessedNumber == p3Number);

        if (player1Won && player2Won && player3Won) {
            cout << "All players guessed correctly! It's a draw.\n";
        } else if (player1Won && player2Won) {
            cout << "Players 1 and 2 guessed correctly! They win!\n";
        } else if (player1Won && player3Won) {
            cout << "Players 1 and 3 guessed correctly! They win!\n";
        } else if (player2Won && player3Won) {
            cout << "Players 2 and 3 guessed correctly! They win!\n";
        } else if (player1Won) {
            cout << "Player 1 wins!\n";
        } else if (player2Won) {
            cout << "Player 2 wins!\n";
        } else if (player3Won) {
            cout << "Player 3 wins!\n";
        } else {
            cout << "No one guessed correctly. Better luck next time!\n";
        }
    }
};

int main() {
    char playAgain;
    cout << "------ Welcome to the Guesser Game ------\n";

    do {
        Umpire umpire;
        umpire.getNumberFromGuesser();
        umpire.getNumberFromPlayers();
        umpire.printResult();

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "------ Thank you for playing! ------\n";
    return 0;
}
