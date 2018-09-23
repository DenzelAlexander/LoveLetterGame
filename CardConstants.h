#ifndef CARDCONSTANTS_H_INCLUDED
#define CARDCONSTANTS_H_INCLUDED
#include <string>

using namespace std;

// Constants for Love Letter game cards, original/standard version

const int NUM_CARDS = 16;    // for Standard Deck

// Rank numbers for each card
const int GUARD_RANK = 1,
          PRIEST_RANK = 2,
          BARON_RANK = 3,
          HANDMAID_RANK = 4,
          PRINCE_RANK = 5,
          KING_RANK = 6,
          COUNTESS_RANK = 7,
          PRINCESS_RANK = 8;

// Counts for cards that appear more than once in the deck                                        //
const int NUM_GUARDS = 5,
          NUM_PRIESTS = 2,
          NUM_BARONS = 2,
          NUM_HANDMAIDS = 2,
          NUM_PRINCES = 2;

// Names on each card
const string GUARD_NAME = "Odette the Guard",
             PRIEST_NAME = "Priest Tomas",
             BARON_NAME = "Baron Tomas",
             HANDMAID_NAME = "Handmaid Susannah",
             PRINCE_NAME = "Prince Arnaud",
             KING_NAME = "King Arnaud IV",
             COUNTESS_NAME = "Countess Wilhelmina",
             PRINCESS_NAME = "Princess Annette";

#endif // CARDCONSTANTS_H_INCLUDED
