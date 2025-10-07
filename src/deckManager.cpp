#include "deckManager.h"

DeckManager::DeckManager()
{
    initDeck();
    shuffleDeck();
}

void DeckManager::initDeck()
{
    std::vector<Card> cardTypes = {Ace(), Two(), Three(), Four(), Five(), Six(), Seven(), Eight(), Nine(), Ten(), Jack(), Queen(), King()};

    for (int i = 0; i < cardTypes.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Deck.push_back(cardTypes.at(i));
        }
    }
}

void DeckManager::shuffleDeck()
{
    unsigned seed = time(NULL);
    std::shuffle(Deck.begin(), Deck.end(), std::default_random_engine(seed)); 
}

void DeckManager::deal(std::vector<Card> &hand)
{
    hand.push_back(Deck.back());
    Deck.pop_back();
}