#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// Represents a Card in the game of Love Letter
class LLCard {
private:
    int rank;
    string name;
public:
    // initialize rank and name of card
    LLCard(int _rank, string _name) : rank(_rank), name(_name) {}
    int getRank() { return rank; }
    string getName() { return name; }
    // Carry out effect of discarding this card
    void doEffect();
};


#endif // CARD_H_INCLUDED
