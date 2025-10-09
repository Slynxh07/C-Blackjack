#pragma once
#include "deckManager.h"
#include "cards.cpp"
#include "player.h"
#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

class Game {
    public:
        Game();
        void playGame();
        bool gameOver();
        
    private:
        bool dealerShow;
        double bet;
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
        bool checkBlackJack();
        void placeBet();
    };