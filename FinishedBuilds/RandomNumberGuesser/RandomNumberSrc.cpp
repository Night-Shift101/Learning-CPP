#include <iostream>
#include <random>
using namespace std;



int main()
{
    random_device rd; 
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100);
    int secret_number = distribution(generator);
    int attempts = 0;
    while (true) {
        int guess;
        attempts++;
        cout << "Guess the secret number (between 1 and 100): ";
        cin >> guess;

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number between 1 and 100." << endl;
            continue;
        }

        if (guess < secret_number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secret_number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the secret number: " << secret_number << endl;
            cout << "It took you " << attempts << " attempts." << endl;
            break;
        }
    }
    return 0;
}
