#pragma once

class Card {
    public:
        void checkHard();
        int getValue();
        char getFace();
    protected:
        char face;
        int value;
};