#include "Card.h"
#include "Loveletter.h"
// Carry out effect of discarding this card
// For the next assignment, it seems probably easier to
// just carry out the effects in the Player class
void LLCard::doEffect() {
	int playerChoice = -1;
	cout << "The name of the card that was discarded is: " << getName() << endl;
	cout << "The rank of the card that was discarded is: " << getRank() << endl;
	if (getRank() == 1) {
		return;//card effect done in player.cpp
		
	}
	if (getRank() == 2) {
		// Rank 2 card will be allowed to view a player's cards unless they are immune to which this will ask which player again
		while(playerChoice<0 || playerChoice > Player::numPlayers-1|| Player::players[playerChoice]->getPlayerStatus() != "Active"){
			cout << "Choose which player to view's hand (0-" << Player::numPlayers-1 << ")"<< endl;
			cin >> playerChoice;
			if (Player::players[playerChoice]->getPlayerStatus() == "Immune")
				cout << "Player is immune please choose another." << endl;
			if (Player::players[playerChoice]->getPlayerStatus() == "Out")
				cout << "Player is out of the round please choose another." << endl;
			}
			cout << Player::players[playerChoice]->getName() << " has a " << Player::players[playerChoice]->getCard()->getRank() << endl;

	}
	if (getRank() == 3) {
		
	}
	if (getRank() == 4) {
		return;	// Card effect done in player.cpp

	}
	if (getRank() == 5) {
		// If discarded card is rank 5 this will allow player to force another to discard their card and draw another.
		while (playerChoice<0 || playerChoice > Player::numPlayers - 1 || Player::players[playerChoice]->getPlayerStatus() != "Active") {
			cout << "Choose which player to discard's hand (0-" << Player::numPlayers - 1 << ")" << endl;
			cin >> playerChoice;
			if (Player::players[playerChoice]->getPlayerStatus() == "Immune")
				cout << "Player is immune please choose another." << endl;
			if (Player::players[playerChoice]->getPlayerStatus() == "Out")
				cout << "Player is out of the round please choose another." << endl;
			}
		if (Player::players[playerChoice]->getCard()->getRank() == 8) {
				Player::players[playerChoice]->setPlayerStatus("Out");
				cout << Player::players[playerChoice] << " is out of the round for discarding a princess.";
		}
			Player::players[playerChoice]->card = Player::players[playerChoice]->deck->draw();
			cout << Player::players[playerChoice]->getName() << "'s card has been discard.";
	}
	if (getRank() == 6) {
		// Card effect done in player.cpp
	}
	if (getRank() == 7) {
		return; // Card effect done in player.cpp
	}
	if (getRank() == 8) {
		return; // Card effect done in player.cpp	
	}
}
