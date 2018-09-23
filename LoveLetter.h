#ifndef LOVELETTER_H_INCLUDED
#define LOVELETTER_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

#include "Player.h"

using namespace std;

/**
 Represents a simplified version of Seiji Kanai's Love Letter game
 */

class LoveLetter {
private:
    const int MINPLAYERS = 2, MAXPLAYERS = 4;
    const int MINVALUE = 1;
    const int MAXVALUE = 8;

    static Deck * deck;

public:
    /**
      Initialize game
    */
    LoveLetter();

    /**
      Display the winner(s) of the round
    */
    void displayWinner();

    /**
      Main function to play the game
    */
    void play();
	/*
	Function to display winner(s) of entire game
	*/
	void displayGameWinner();
};

#endif // LOVELETTER_H_INCLUDED
