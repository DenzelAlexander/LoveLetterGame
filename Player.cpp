#include "Player.h"

// This is where the variables actually have to
// have memory allocated for them
// This way the compiler will only create the variables once
// This also makes all players accessible to any other player
// when implementing the cards that need it
Player ** Player::players;
int Player::numPlayers;


// Initialize the player's name and first card
// Hold onto the deck for taking turns
Player::Player(string _name, Deck * _deck) {
    name = _name;
    deck = _deck;
	//draw initial
    card = deck->draw();
}

// Draw a card and choose which card to discard
void Player::takeTurn() {
	int playerChoice = -1;

	// if player is not out of the round the game will proceed giving the player a turn
	if (getPlayerStatus() != "Out" ) { 
		// if the player is immune this will set the player's status to normal
		setPlayerStatus("Active");
		
		// Draws new card and give player the option to keep or discard it
		LLCard * newCard = deck->draw();
		char choice = 'n';
		cout << name << ", you got a : " << newCard->getRank() << endl;
		cout << "You have a : " << card->getRank() << endl;
		// If current card is Rank 7, will discard it if player has 5 or 6 as per the games rules.
		if (card->getRank() == 7) {
			if (newCard->getRank() == 5 || newCard->getRank() == 6) {
				cout << "Countess must be discarded when a King or Prince is in hand." << endl;
				card = newCard;
				cout << "Your card is now " << card->getRank() << " now." << endl;
				return;
			}

		}
		// if new card is Rank 7, it will automatically discarded if a player has 5 or 6.
		if (newCard->getRank() == 7) {
			if (card->getRank() == 5 || card->getRank() == 6) {
				cout << "Countess must be discarded when a King or Prince is in hand." << endl;
				cout << "Your card is still " << card->getRank() << "." << endl;
				return;
			}

		}
		// gives player option to keep new card or not.
		cout << "Do you want to keep the new card? (y/n) " << endl;
		cin >> choice;
		if ('y' == choice || 'Y' == choice) {
		card->doEffect();
			// if player discards 8 they are out of round
			if (card->getRank() == 8)
				setPlayerStatus("Out");

			// if player discards 6 they trade with another player still in the round
			if (card->getRank() == 6) {
				while (playerChoice<0 || playerChoice > Player::numPlayers - 1 || Player::players[playerChoice]->getPlayerStatus() != "Active") {
					cout << "Choose which player to discard's hand (0-" << Player::numPlayers - 1 << ")" << endl;
					cin >> playerChoice;
				}
				LLCard * temp = newCard;
				newCard = Player::players[playerChoice]->getCard();
				Player::players[playerChoice]->card = temp;
				cout << Player::players[playerChoice]->getName() << " now has a " << Player::players[playerChoice]->getCard()->getRank() << endl;
				cout << name << "now has a " << card->getRank() << endl;
			}

			// if player discards 4 they are immune for one turn
			if (card->getRank() == 4) {
				setPlayerStatus("Immune");
				cout << "You are immune until your next turn." << endl;
			}
			


			if (card->getRank() == 3) {
				while (playerChoice<0 || playerChoice > Player::numPlayers - 1 || Player::players[playerChoice]->getPlayerStatus() != "Active") {
					cout << "Choose a player to compare cards with (0-" << numPlayers - 1 << ")";
						cin >> playerChoice;
				}
				if (newCard->getRank() > Player::players[playerChoice]->getCard()->getRank()) {
					Player::players[playerChoice]->setPlayerStatus("Out");
					cout << Player::players[playerChoice]->getName() << "is now out for the round.";
				}
				if (Player::players[playerChoice]->getCard()->getRank() > newCard->getRank()) {
					setPlayerStatus("Out");
					cout << getName() << "is now out for the round.";
				}
			}
			if (card->getRank() == 1) {
				while (playerChoice<0 || playerChoice > Player::numPlayers - 1 || Player::players[playerChoice]->getPlayerStatus() != "Active") {
					cout << "Choose a player to compare cards with (0-" << numPlayers - 1 << ")";
					cin >> playerChoice;
					if (Player::players[playerChoice]->getPlayerStatus() == "Immune")
						cout << Player::players[playerChoice]->getName() << " is immune please choose another." << endl;
					if (Player::players[playerChoice]->getPlayerStatus() == "Out")
						cout << Player::players[playerChoice]->getName() << " is out of the round please choose another." << endl;
				}
				int playerGuess =1;
				while (playerGuess < 2 || playerGuess > 8) {
					cout << "Make a guess of what the selected player has (2-8)";
						cin >> playerGuess;
				}
				if (playerGuess == Player::players[playerChoice]->getCard()->getRank())
				{
					Player::players[playerChoice]->setPlayerStatus("Out");
					cout << "Correct! " <<  Player::players[playerChoice]->getName() << "is now out for the round.";
				}

				
			}
			

			card = newCard;
		

		}
		else {
			newCard->doEffect();
			// again newly picked up 8 discarded they are also out of the round
			if (newCard->getRank() == 8)
				setPlayerStatus("Out");
			// if player discards 6 they trade with another player still in the round
			if (newCard->getRank() == 6) {
				while (playerChoice<0 || playerChoice > Player::numPlayers - 1 || Player::players[playerChoice]->getPlayerStatus() != "Active") {
					cout << "Choose which player to discard's hand (0-" << Player::numPlayers - 1 << ")" << endl;
					cin >> playerChoice;
				}
				LLCard * temp = card;
				card = Player::players[playerChoice]->getCard();
				Player::players[playerChoice]->card = temp;
				cout << Player::players[playerChoice]->getName() << " now has a " << Player::players[playerChoice]->getCard()->getRank() << endl;
				cout << name << "now has a " << card->getRank() << endl;
			}


			// again newly obtained 4 discarded they are out of the round/
			if (newCard->getRank() == 4) {
				setPlayerStatus("Immune");
				cout << "You are immune until your next turn." << endl;
			}
			//again 3 is discaded who ever has the lower card is out.
			if (newCard->getRank() == 3) {
				while (playerChoice<0 || playerChoice > Player::numPlayers - 1 || Player::players[playerChoice]->getPlayerStatus() != "Active") {
					cout << "Choose a player to compare cards with (0-" << numPlayers - 1 << ")";
					cin >> playerChoice;
				}
				if (card->getRank() > Player::players[playerChoice]->getCard()->getRank()) {
					Player::players[playerChoice]->setPlayerStatus("Out");
					cout << Player::players[playerChoice]->getName() << "is now out for the round.";
				}
			}
			if (newCard->getRank() == 1) {
				while (playerChoice<0 || playerChoice > Player::numPlayers - 1 || Player::players[playerChoice]->getPlayerStatus() != "Active") {
					cout << "Choose a player to guess which card they have (0-" << numPlayers - 1 << "): ";
					cin >> playerChoice;
				}
				int playerGuess = 1;
				while (playerGuess < 2 || playerGuess > 8) {
					cout << "Make a guess of what the selected player has (2-8)";
					cin >> playerGuess;
				}
				if (playerGuess == Player::players[playerChoice]->getCard()->getRank())
				{
					Player::players[playerChoice]->setPlayerStatus("Out");
					cout << Player::players[playerChoice]->getName() << "is now out for the round.";
				}


			}

		}
	}
	else return;
}




