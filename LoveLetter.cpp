#include "LoveLetter.h"
#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>

int maxwins =0;
Deck * LoveLetter::deck;
int gen(int limit) {
	return rand() % limit;
}
/**
  Initialize game
*/
LoveLetter::LoveLetter()
{
    cout << "Welcome to the game of Love Letter (version 0.01)" << endl << endl;
    do
    {
        cout << "How many players are playing? (2-4): ";
        cin >> Player::numPlayers;
    }
    while (Player::numPlayers < MINPLAYERS || Player::numPlayers > MAXPLAYERS);

    deck = new Deck();
    Player::players = new Player * [Player::numPlayers];
     // initialize random number generation with a random seed
    
	 srand (time(NULL));
	random_shuffle(deck->cards, deck->cards+16, gen); // What to shuffle?
	


    for (int player = 0; player < Player::numPlayers; player++)
    {
        string name;
        cout << "Please enter a (single word) name for player " << player << ": ";
        cin >> name;
        Player::players[player] = new Player(name, deck);
		Player::players[player]->setPlayerStatus("Active");
    }
}


/**
  Display the winner(s) of the round
*/
void LoveLetter::displayWinner()
{
	string name;
	int winner;
    int maxCard = MINVALUE-1;
    // find max Card value
    for (int player = 0; player < Player::numPlayers; player++)
		if (Player::players[player]->getPlayerStatus() == "Active") {
			if (Player::players[player]->getCard()->getRank() > maxCard)
				maxCard = Player::players[player]->getCard()->getRank();
		}
		
    cout << "The highest card is " << maxCard << endl;
    cout << "The winners are: ";
	for (int player = 0; player < Player::numPlayers; player++)
		if (Player::players[player]->getPlayerStatus() == "Active") {
			if (Player::players[player]->getCard()->getRank() == maxCard) {
				winner = Player::players[player]->getWins();
				winner++;
				Player::players[player]->setWins(winner);
			}
		}
			


			
    // list winners
	for (int player = 0; player < Player::numPlayers; player++) {
		if (maxCard == Player::players[player]->getCard()->getRank())
			cout << Player::players[player]->getName() << endl;
		Player::players[player]->setPlayerStatus("Active");
		

	}
		
	
}
void LoveLetter::displayGameWinner() {
	for (int player = 0; player < Player::numPlayers; player++) {
		if (Player::numPlayers == 2)
			if (Player::players[player]->getWins() == 7) {
				maxwins = 1;
				cout << Player::players[player]->getName() << " has won the game" << endl;
			}

		if (Player::numPlayers == 3)
			if (Player::players[player]->getWins() == 5) {
				maxwins = 1;
				cout << Player::players[player]->getName() << " has won the game" << endl;
			}

		if (Player::numPlayers == 4)
			if (Player::players[player]->getWins() == 4) {
				maxwins = 1;
				cout << Player::players[player]->getName() << " has won the game" << endl;
			}



	}
}
/**
  Main function to play the game
*/
void LoveLetter::play()
{
	while (maxwins < 1) {
		int current = 0;    // current player index
		int cardsLeft = NUM_CARDS - Player::numPlayers;
		while (cardsLeft > 0)
		{
			Player::players[current]->takeTurn();
			cardsLeft--;
			current = (current + 1) % Player::numPlayers;
		}
		displayWinner();
		deck->resetDeck();
		random_shuffle(deck->cards, deck->cards + 16, gen);
		for (int i = 0; i < Player::numPlayers; i++) 
			Player::players[i]->card = Player::players[i]->deck->draw();
		
		displayGameWinner();
	}
}
