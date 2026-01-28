#include <iostream>
#include <limits>
#include <random> 

using namespace std;

void playGame() {
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 100);

    int target = distr(gen);
    int guess = 0;
    int tries = 0;

    cout << "\n--- I'm thinking of a number between 1 and 100 ---" << endl;

    while (guess != target) {
        cout << "Take a guess: ";
        
        
        if (!(cin >> guess)) {
            cout << "Oops! That's not a number. Try again." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }

        tries++;

        if (guess < target) {
            cout << "A bit higher..." << endl;
        } else if (guess > target) {
            cout << "Lower than that!" << endl;
        } else {
            cout << "\nNice! You got it in " << tries << " tries." << endl;
        }
    }
}

int main() {
    char playAgain;

    cout << "Welcome to the Guessing Game!" << endl;

    do {
        playGame();
        cout << "Want to play another round? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}