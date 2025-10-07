#pragma once
#include "card.h"

class Ace : public Card {
    public:
        Ace()
        {
            this->value = 11;
            this->face = 'A';
        }
        void checkHard(int handVal) override
        {
            if (handVal > 21)
            {
                this->value = 1;
            }
        }
};

class King : public Card {
    public:
        King()
        {
            this->value = 10;
            this->face = 'K';
        }
};

class Queen : public Card {
    public:
        Queen()
        {
            this->value = 10;
            this->face = 'Q';
        }
};

class Jack : public Card {
    public:
        Jack()
        {
            this->value = 10;
            this->face = 'J';
        }
};

class Ten : public Card {
    public:
        Ten()
        {
            this->value = 10;
            this->face = 'T';
        }
};

class Nine : public Card {
    public:
        Nine()
        {
            this->value = 9;
            this->face = '9';
        }
};

class Eight : public Card {
    public:
        Eight()
        {
            this->value = 8;
            this->face = '8';
        }
};

class Seven : public Card {
    public:
        Seven()
        {
            this->value = 7;
            this->face = '7';
        }
};

class Six : public Card {
    public:
        Six()
        {
            this->value = 6;
            this->face = '6';
        }
};

class Five : public Card {
    public:
        Five()
        {
            this->value = 5;
            this->face = '5';
        }
};

class Four : public Card {
    public:
        Four()
        {
            this->value = 4;
            this->face = '4';
        }
};

class Three : public Card {
    public:
        Three()
        {
            this->value = 3;
            this->face = '3';
        }
};

class Two : public Card {
    public:
        Two()
        {
            this->value = 2;
            this->face = '2';
        }
    private:
};