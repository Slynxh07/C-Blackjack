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

    private:
        bool standing;
        bool bust;
};