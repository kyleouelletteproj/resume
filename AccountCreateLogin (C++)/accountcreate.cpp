/*Hashing Algorithm Project
CSC 2710
Kyle Ouellette, Fenn Gurley, Connor Willians
MUST USE WINDOWS COMPILED ON MINGW32/8.2.0
Compiled in Notepad++ using 
g++ ./hashing.cpp ./SHA256/sha256.cpp ./SHA256/sha256.h
While CD in folder
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <functional>
#include ".\SHA256\sha256.h"
#include <windows.h>
#include <conio.h>

using namespace std;

//Initialize Function Signature
void loadMainLoop(bool, ofstream &output, ifstream &input);
void creatingAccount(bool, struct account *person, ofstream &output);
void hashPassword(string, ofstream &output);
void hashPassword(string, string);
void loggingIn(bool, ifstream &input);
inline bool existingUser(const string username);
void hidePassword(string&, bool);

//Create struct Account
struct account {
	string username;
	string firstName;
	string lastName;
	string password;
};
//Initialize struct person
account person;

int main() {
ofstream output;
ifstream input;
//Start main Loop
loadMainLoop(true,output, input);
return 0;
}

void loadMainLoop(bool mainLoop, ofstream& output, ifstream& input) {
	int userResponse;
	bool logIn;
	bool createAccount;
	while(mainLoop) {
		cout << "Enter the number of your choice" << endl;
		cout << "1. Create Account" << endl << "2. Log In" << endl << "3. Exit" << endl;
		cin >> userResponse;
		if(userResponse == 1) {
			createAccount = true;
			creatingAccount(createAccount, &person, output);
		}
		if(userResponse == 2) {
			logIn = true;
			loggingIn(logIn, input);
		}
		if(userResponse == 3) {
			mainLoop = false;
			break;
		}
		if(userResponse != 1 && userResponse != 2 && userResponse != 3) {
			cout << "Invalid Option. Restarting..." << endl;
		}
	
}
}

void creatingAccount(bool createAccount, account *person, ofstream& output) {
	system("CLS");
	while(createAccount) {
		string fileName;
		cout << "Create An Account" << endl << endl;
		cout << "Please Enter Your First Name" << endl;
		cin >> person->firstName;
		system("CLS");
		cout << "Create An Account" << endl << endl;
		cout << "Please Enter Your Last name" << endl;
		cin >> person->lastName;
		system("CLS");
		cout << "Create An Account" << endl << endl;
		cout << "Please Enter Your Username" << endl;
		cin >> person->username;
		system("CLS");
		cout << "Create An Account" << endl << endl;
		cout << "Please Enter Your Password" << endl;
		hidePassword(person->password,false);
		system("CLS");
		createAccount=false;
		fileName = "./Accounts/"+person->username+".txt";
		output.open(fileName);
		output << "Username: " << person->username << endl << "First Name: " << person -> firstName << endl
		<< "Last Name: " << person->lastName << endl << "Password: ";
		hashPassword(person->password,output);
		cout << "Account Creation Successful!" << endl;
	}
}
void hashPassword(string pass, ofstream& output) {
	output << endl << sha256(pass) << endl;
}
void hashPassword(string pass, string correctPass) {
	string test;
	if(correctPass.compare(sha256(pass)) == 0) {
		cout << "Log In Successful" << endl;
		cin >> test;
	} else {
		cout << "Invalid Username or Password. Please Try Again." << endl;
	}
}

void loggingIn(bool logIn,ifstream& input) {
	while(logIn) {
	system("CLS");
	string username, pass = "", fileName, correctPassword;
	cout << "Log In" << endl << endl;
	cout << "Please Enter Your Username" << endl;
	cin >> username;
	system("CLS");
	cout << "Log In" << endl << endl;
	cout << "Please Enter Your Password" << endl;
	hidePassword(pass,true);
	system("CLS");
	fileName = "./Accounts/"+username+".txt";
	if(existingUser(fileName)) {
		input.open(fileName);
		for(int i = 0; i < 5; i++) {
			getline(input,correctPassword);
		}
		logIn = false;
		hashPassword(pass,correctPassword);
		input.close();
	} else {
		cout << "Invalid Username or Password. Please Try Again." << endl << endl;
		logIn = false;
	}
	}
}
inline bool existingUser(const string username) {
    ifstream file(username);
    if(!file)            // If the file was not found, then file is 0, i.e. !file=1 or true.
        return false;    // The file was not found.
    else                 // If the file was found, then file is non-0.
        return true;     // The file was found.
}
void hidePassword(string &pass, bool loggingIn) {
	char ch;
	ch = 0;
	string length = "";
	while(ch != 13){//character 13 is enter
	ch = _getch();
	if(ch == 8) {
	cout << "\b";
	cout << "";
	pass.pop_back();
	length.pop_back();
	system("CLS");
	if(loggingIn) {
	cout << "Log In" << endl << endl;
	cout << "Please Enter Your Password" << endl;
	} else { 
	cout << "Create An Account" << endl << endl;
	cout << "Please Enter Your Password" << endl;
	}
	cout << length;
	} if (ch != 8) {
      pass.push_back(ch);
	  cout << "*";
	  length += "*";
	}
   }
}