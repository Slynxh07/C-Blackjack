#pragma once

class Card {
    public:
        virtual void checkHard(int handVal);
        int getValue();
        char getFace();
    protected:
        char face;
        int value;
};