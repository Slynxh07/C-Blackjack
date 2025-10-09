#include "cards.cpp"
#include <iostream>
#include <vector>

class Player {
    public:
        Player();
        std::vector<Card> hand;
        void stand();
        bool isStanding();
        bool isBust();
        int calcHandVal();
        void playerReset();
        double getBankAmount();
        void returnBet(double amount);

    private:
        bool standing;
        bool bust;
        double bank;
};