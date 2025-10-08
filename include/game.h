#pragma once
#include "deckManager.h"
#include "cards.cpp"
#include "player.h"
#include <string>
#include <vector>
#include <iostream>

class Game {
    public:
        Game();
        bool running();
        void showHands();
        void restartGame();
        void hitOrStand();
        void playGame();

    private:
        bool isRunning;
        bool dealerShow;
        Player player;
        DeckManager deckManager;
        std::vector<Card> dealerHand;
};