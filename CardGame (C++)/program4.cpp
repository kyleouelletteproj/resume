/*Kyle Ouellette
Program 4
CSC 1720
Write a program that implements a Card Guessing Game. Your program should first create a
deck of cards. While you are free to implement this with any data structure that you would like,
you must choose it from the Standard Template Library. 
*/
#include <stack>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <windows.h>
#include <stdlib.h>
#include <vector>


using namespace std;

//Declaring a global win count
int winCount = 0;

//Prototypes for functions
void initializeDeck(string x[]);
string getCard(string x[]);
void shuffleDeck(string x[]);
void decideGame(int user);
void loadPregameInterface();
void determineOutcome(int choice, int user);
void askToPlay();

//Declare global variables
string deck[52];
vector<string> cardDeck;
bool gameLoop = true;

int main() {
int userInput;
int gameAnswer;
initializeDeck(deck);
//Starting Game loop
while(gameLoop) {
	cout << "Wins: " << winCount << endl;
	loadPregameInterface();
	cin >> userInput;
	decideGame(userInput);
	if(!gameLoop) {
	break;
	}
	cin >> gameAnswer;
	determineOutcome(gameAnswer, userInput);
	askToPlay();
}
return 0;
}

void initializeDeck(string x[]) {
int counter = 0;
string currentCard = "";
string suits[4] = {"Spades", "Diamonds", "Clubs", "Hearts"};
string faces[13] = {"Ace of ", "Two of ", "Three of ", "Four of ", "Five of ", "Six of ",
"Seven of ", "Eight of ", "Nine of ", "Ten of ","Jack of ", "Queen of ", "King of "};
for(int i = 0; i < 13; i++) {
for(int k = 0; k < 4; k++) {
currentCard = faces[i]+suits[k];
x[counter]= currentCard;
counter++;
}
}
}

//Returns a random card
string getCard(string x[]) {
	return x[0];
}

//Shuffles the deck to get a new card
void shuffleDeck(string x[]) {	
cardDeck.clear();
random_shuffle(&x[0],&x[52]);
for(int i = 0; i < 53; i++) {
	cardDeck.push_back(x[i]);
}
}
//Function to load the pregame interface
void loadPregameInterface() {
	cout << "Type in 1, 2, or 3." << endl;
	cout << "1. Guess the suit of the card" << endl;
	cout << "2. Guess the face of the card" << endl;
	cout << "3. Quit"<< endl;
}
//Function to decide the game
void decideGame(int user) {
	if(user == 1) {
		shuffleDeck(deck);
		cout << "Type the number of your choice" << endl;
		cout << "1. Hearts" << endl << "2. Spades" << endl << "3. Clubs" << endl << "4. Diamonds" << endl;
	}
	if(user == 2) {
	shuffleDeck(deck);
	cout << "Type the number of your choice" << endl;
	cout << "1.  Ace" << endl << "2.  Two" << endl << "3.  Three" << endl << "4.  Four" << endl << "5.  Five" << endl << "6.  Six" << endl << "7.  Seven" << endl
	<< "8.  Eight" << endl << "9.  Nine" << endl << "10. Ten" << endl << "11. Jack" << endl << "12. Queen" << endl << "13. King" << endl;
	}
	if(user == 3) {
	 gameLoop = false;
	}
	if(user > 3) {
		cout << "Invalid Input Option. Please try again" << endl;
		cin >> user;
		cout << endl;
	decideGame(user);
	}
}
//Function that checks to see if the user won or lost
void determineOutcome(int choice, int user) {
	string faceCheck[] = {"Ace", "Two", "Three", "Four", "Five", "Six",
"Seven", "Eight", "Nine", "Ten of ","Jack of ", "Queen of ", "King"};
	string suitCheck[] = {"Hearts", "Spades", "Clubs", "Diamonds"};
	string computerCard = cardDeck.front();
	
	if(user == 1) {
	if(choice > 4) {
		cout << "Invalid Input Option. Please try again" << endl;
		cin >> choice;
		cout << endl;
	}
	if (computerCard.find(suitCheck[choice-1]) != string::npos) {
		cout << "You win! Your card was the " + cardDeck.front() << endl;
		winCount++;
	} else {
		cout << "Aw. Your card was the " + cardDeck.front() << endl;
	}
	}
	if(user == 2) {
	if(choice > 13) {
		cout << "Invalid Input Option. Please try again" << endl;
		cin >> choice;
		cout << endl;
	}
	if(computerCard.find(faceCheck[choice-1]) != string::npos) {
		cout << "You win! Your card was the " + cardDeck.front() << endl;
		winCount++;
	} else {
		cout << "Aw. Your card was the " + cardDeck.front() << endl;
	}
	}
	if(user > 2) {
		cout << "Invalid Input Option. Please try again" << endl;
		cin >> user;
		cout << endl;
	}
}
void askToPlay() {
	int user;
	cout << "Do you want to play again?" << endl << "1. Yes" << endl << "2. No" << endl;
	cin >> user;
	if(user == 1) {
	}
	if(user == 2) {
	gameLoop = false;
	}
	if(user > 2) {
		cout << "Invalid Input Option. Please try again" << endl;
		cin >> user;
		cout << endl;
	}
}

