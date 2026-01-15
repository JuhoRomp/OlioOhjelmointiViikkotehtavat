#include "game.h"
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
#include <limits>
using namespace std;

Game::Game(int max) {
    maxNumber = max;
    cout <<"GAME CONSTRUCTOR: object initialized with "<<maxNumber<<" as a maximum value"<< endl;


}

Game::~Game() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout <<"GAME DESTRUCTOR: object cleared from stack memory"<< endl;


}

void Game::play(){
    srand(time(0));
    randomNumber = rand()%maxNumber+1;
    numOfGuesses=0;
    do{
        numOfGuesses++;
        cout << "Guess number between 1-"<< maxNumber << endl;
        cin>>playerGuess;
        if(playerGuess>randomNumber){
            cout << "Your guess is too big" << endl;

        } else if (playerGuess<randomNumber){
            cout << "Your guess is too small" << endl;

        } else {
            cout << "Your guess is right = "<< randomNumber << endl;

        }
    } while(playerGuess!=randomNumber);
    printGameResut(numOfGuesses);
}

void Game::printGameResut(int result){
    cout <<"You guessed the right answer "<<randomNumber<<" with "<<result<<" guesses"<<endl;
}
