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
        void playGame();
        
    private:
        bool dealerShow;
        Player player;
        DeckManager deckManager;
        std::vector<Card> dealerHand;
        void restartGame();
        void hitOrStand();
        void showHands();
        void dealerPlay();
        int dealerHandVal();
        bool dealerBust();
        bool playerWin();
    };