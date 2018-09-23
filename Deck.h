#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include <cstdlib>
#include "CardConstants.h"
#include "Card.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>

class Deck {

private:

public:
	// Initialize the deck with the actual cards
	LLCard **cards;   // array of (Card *)
	int nextCard = 0;   // where we are in the deck

						// To add multiple instances of a particular card to the deck
	void addCardType(int rank, string name, int startIndex, int copies) {
		for (int i = startIndex; i < startIndex + copies; i++)
			cards[i] = new LLCard(rank, name);
	}


    Deck() {
        int cardIndex = 0;
        cards = new LLCard *[NUM_CARDS];
        addCardType(GUARD_RANK, GUARD_NAME, cardIndex, NUM_GUARDS);
        cardIndex += NUM_GUARDS;
        addCardType(PRIEST_RANK, PRIEST_NAME, cardIndex, NUM_PRIESTS);
        cardIndex += NUM_PRIESTS;
        addCardType(BARON_RANK, BARON_NAME, cardIndex, NUM_BARONS);
        cardIndex += NUM_BARONS;
        addCardType(HANDMAID_RANK, HANDMAID_NAME, cardIndex, NUM_HANDMAIDS);
        cardIndex += NUM_HANDMAIDS;
        addCardType(PRINCE_RANK, PRINCE_NAME, cardIndex, NUM_PRINCES);
        cardIndex += NUM_PRINCES;
        cards[cardIndex++] = new LLCard(KING_RANK, KING_NAME);
        cards[cardIndex++] = new LLCard(COUNTESS_RANK, COUNTESS_NAME);
        cards[cardIndex] = new LLCard(PRINCESS_RANK, PRINCESS_NAME);
    }

    // Get "top" card, which is wherever nextCard is
    LLCard * draw() {
        if (nextCard == NUM_CARDS) {
            cerr << "Error! tried to draw from empty deck" << endl;
            exit(1);
        }
        return cards[nextCard++];
    }
	// Resets the deck brings next card back to the beginning of the array.
	LLCard * resetDeck() {
		nextCard = 0;
		return NULL;
	}

};


#endif // DECK_H_INCLUDED
