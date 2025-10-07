#pragma once
#include "cards.cpp"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class DeckManager {
    public:
        DeckManager();
        void initDeck();
        void shuffleDeck();
        void deal(std::vector<Card> &hand);

    private:
        std::vector<Card> Deck;
};