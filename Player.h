#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <iostream>
#include "Deck.h"

using namespace std;

/**
  Represents a player in the Love Letter game
*/

class Player {
private:
    string name;
	int wins;
	string playerStatus;
public:
	LLCard * card;
	Deck * deck; // support Player drawing the card directly
    // Declare the static variables here so other
    // code can use them, but since they are "static"
    // the compiler will not create them
    // We won't have separate copies of these variables inside
    // each Player
    static Player ** players;
    static int numPlayers;

    // Initialize Player with name and deck
    Player(string _name, Deck * _deck);
    void setName(string _name) {
        name = _name;
    }
	// when a player wins a round the player gains a win
	void setWins(int _wins) {
		wins = _wins;
	}
	// returns wins that the player has acquired.
	int getWins() {
		return wins;
	}
	// returns name for player
    string getName() {
        return name;
    }
	// returns card that player has
    LLCard * getCard() {
        return card;
    }
	// sets status for player such as "Out" or "Immune" or "Active"
	void setPlayerStatus(string _playerStatus) {
		playerStatus = _playerStatus;
	}
	// returns current status for player
	string getPlayerStatus() {
		return playerStatus;
	}
	// function lets player take their turn
    void takeTurn();

};


#endif // PLAYER_H_INCLUDED
