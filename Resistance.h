#include "pch.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
using namespace std;

class CARDS {

public:
	CARDS();
	void DECKSORT();
	void PLAYERS();
	void GAMEPLAY(int);
	void SHUFFLE();
	//  void Stories(char *);
	//  void EndTurn(char *);
	//  char DrawCard(char *);

private:
	int num_players;
	int fail_req;
	int num_sent;
	int num_res;
	int deck[52];
	int deck_red[26];
	int deck_black[26];
	char Players[10][20];
	char end_turn;
	char card[13][15];
};

CARDS::CARDS() {
	cout << "Welcome to Resistance." << "\n\n";
}

void
CARDS::PLAYERS() {

	char names[10][20];
	char b;
	cout << "How many players are participating? 5-10 Players allowed." << endl;
	cin >> num_players;
	cout << "Please enter players' names." << endl;
	for (int i = 0; i < num_players; i++) {
		cout << "Please pass device to Player " << i + 1 << " and press any key once done." << endl;
		cin >> b;
		if (b) {
			cout << "Player " << i + 1 << ": ";
			cin >> Players[i];
			cout << "\n\n";
		}
		else {
			cout << "You have pressed an incorrect key. Please try again." << endl;
			cin >> b;
			if (b) {
				cout << "Player " << i + 1 << ": ";
				cin >> Players[i];
				cout << "\n\n";
			}
		}
	}
	cout << "Confirm Players." << endl;
	for (int i = 0; i < num_players; i++) {
		cout << Players[i] << endl;
	}
}	//End of PLAYERS Method

void
CARDS::SHUFFLE() {	//Look to add deck declared in main function as argument and change method to work with any size deck of integers.
	
	int suit, value, position;
	int temp = 0;

	srand(time(0));
	for (int i = 0; i < 52; i++) {
		deck[i] = i + 1;
	}
	string card_val[13] = { "King", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen" };
	string card_suit[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };

	for (int i = 0; i < 52; i++) {
		position = rand() % 52;
		temp = deck[i];
		deck[i] = deck[position];
		deck[position] = temp;
	}

	for (int j = 0; j < 52; j++) {
		value = deck[j] % 13;
		suit = deck[j] % 4;		//Continue next line by adding a character or string array to save the card names, using index j  for random-ordered deck.
		if (suit == 0 || suit == 2) {
			deck_red[j] = deck[j];
		}
		else if (suit == 1 || suit == 3) {
			deck_black[j] = deck[j];
		}
		else {
			cout << "There was an error." << endl;
		}
	}
}	//End of Shuffle Method


void
CARDS::GAMEPLAY(int round) {
	
	int res_index = 0;
	srand(time(0));		//Random number generator to choose the first person to pick team members.
	int num_spies = 0;
	int jcount = 0, kcount = 0, tempk = 0,ntemp = 0;
	//int num_sent;	//Number of people sent on mission
	//int fail_req = 1;
	int res_confirmed[10];	//Check against random number generator to ensure one isn't selected to resistance more than once.
	int spy_confirmed[10];
	int return_vals[4];
	int first_person;
	first_person = rand() % num_players;

	for (int i = 0; i < 10; i++) {
		res_confirmed[i] = 12;
	}
	//round indexed 0-4 for the 5 rounds.
	switch (round) {
	case 0: 
		switch (num_players) {
			case 5: num_sent = 2; //num_sent = { 2, 3, 2, 3, 3 }; 
					num_res = 3;
				break;
			case 6: num_sent = 2;//num_sent = { 2, 3, 4, 3, 4 }; 
					num_res = 4;
				break;
			case 7: num_sent = 2;//num_sent = { 2, 3, 3, 4, 4 }; 
					num_res = 4;
				break;
			case 8: num_sent = 3;//num_sent = { 3, 4, 4, 5, 5 }; 
					num_res = 5;
				break;
			case 9: num_sent = 3;//num_sent = { 3, 4, 4, 5, 5 }; 
					num_res = 6;
				break;
			case 10: num_sent = 3;//num_sent = { 3, 4, 4, 5, 5 }; 
					num_res = 6;
				break;
			default: cout << "Sorry, you don't have a suitable number of players. Get more or less \"friends\"." << endl;
		}
	case 1: 
		switch (num_players) {
		case 5: num_sent = 3; //num_sent = { 2, 3, 2, 3, 3 }; 
				num_res = 3;
			break;
		case 6: num_sent = 3; //num_sent = { 2, 3, 4, 3, 4 }; 
				num_res = 4;
			break;
		case 7: num_sent = 3; //num_sent = { 2, 3, 3, 4, 4 }; 
				num_res = 4;
			break;
		case 8: num_sent = 4; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 5;
			break;
		case 9: num_sent = 4; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		case 10: num_sent = 4; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		default: cout << "Sorry, you don't have a suitable number of players. Get more or less \"friends\"." << endl;
		}
	case 2:
		switch (num_players) {
		case 5: num_sent = 2; //num_sent = { 2, 3, 2, 3, 3 }; 
				num_res = 3;
			break;
		case 6: num_sent = 4; //num_sent = { 2, 3, 4, 3, 4 }; 
				num_res = 4;
			break;
		case 7: num_sent = 3; //num_sent = { 2, 3, 3, 4, 4 }; 
				num_res = 4;
			break;
		case 8: num_sent = 4; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 5;
			break;
		case 9: num_sent = 4; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		case 10: num_sent = 4; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		default: cout << "Sorry, you don't have a suitable number of players. Get more or less \"friends\"." << endl;
		}
	case 3:
		switch (num_players) {
		case 5: num_sent = 3; //num_sent = { 2, 3, 2, 3, 3 }; 
				num_res = 3;
			break;
		case 6: num_sent = 3; //num_sent = { 2, 3, 4, 3, 4 }; 
				num_res = 4;
			break;
		case 7: num_sent = 4; //num_sent = { 2, 3, 3, 4, 4 }; 
				num_res = 4;
			break;
		case 8: num_sent = 5; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 5;
			break;
		case 9: num_sent = 5; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		case 10: num_sent = 5; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		default: cout << "Sorry, you don't have a suitable number of players. Get more or less \"friends\"." << endl;
		}
	case 4: 
		switch (num_players) {
		case 5: num_sent = 3; //num_sent = { 2, 3, 2, 3, 3 }; 
				num_res = 3;
			break;
		case 6: num_sent = 4; //num_sent = { 2, 3, 4, 3, 4 }; 
				num_res = 4;
			break;
		case 7: num_sent = 4; //num_sent = { 2, 3, 3, 4, 4 }; 
				num_res = 4;
			break;
		case 8: num_sent = 5; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 5;
			break;
		case 9: num_sent = 5; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		case 10: num_sent = 5; //num_sent = { 3, 4, 4, 5, 5 }; 
				num_res = 6;
			break;
		default: cout << "Sorry, you don't have a suitable number of players. Get more or less \"friends\"." << endl;
		}
	}
	

	num_spies = num_players - num_res;
	if (num_players == 7 && round == 4) {
		fail_req = 2;
	}
	else if (num_players >= 8 && num_players <= 10 && round == 4) {
		fail_req = 2;
	}
	else {
		fail_req = 1;
	}
	cout << "Variables: fail_req, num_sent, num_res, num_players: " << fail_req << ", " << num_sent << ", " << num_res << ", " << num_players << "." << endl;
	
	// Now assign identity cards to each player.

	for (int l = 0; l < num_res; l++) {		// Check for doubles working.
		//Assign resistance members first.
	//	jcount = 0;
		res_index = rand() % num_players;
		for (int j = 0; j < l; j++) {
			if (res_index == res_confirmed[j]) {
				res_index = rand() % num_players;
			//	jcount += 1;
			//	j = j-jcount; --Do not need jcount variable anymore. Delete after checking entire working code.
				j = j - l;
			}

			else {
			//	res_confirmed[l] = res_index;
			}
		}
		res_confirmed[l] = res_index;
		cout << res_confirmed[l] << endl;		//cout Used to test that doubles aren't present.
	}

	/*Next, need to select the resistance members --Failed test
	for (int l = 0; l < num_spies; l++) {
		for (int p = 0; p < num_players; p++) {
			ltemp = p;
			for (int n = 0; n < num_res; n++) {
				if (res_confirmed[n] == p) {
					l = ltemp - 1;
				}

				else {
					spy_confirmed[l] = l;
					cout << spy_confirmed[l] << endl;
				}
			}
		}
	}

		for (int s = 0; s < num_spies; s++) {
		for (int i = 0; i < num_players & i < s; i++) {
			for (int r = 0; r < num_res && r <= i; r++) {
				if (res_confirmed[r] != i) {
					spy_confirmed[s] = i;
					r = num_res;
					i = num_players;
				}

				else {

				}
			}
		}
	*/

	}
	/*
	return_vals[0] = fail_req;
	return_vals[1] = num_sent;
	return_vals[2] = num_res;
	return_vals[3] = num_players;
	
	return return_vals;		-- Return does not work
	/*
	switch (round) {		//Gameplay Here Maybe

	}
	*/	
}
