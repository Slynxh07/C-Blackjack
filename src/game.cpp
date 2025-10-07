#include "game.h"

Game::Game()
{
    isRunning = true;
    player = Player();
    deckManager = DeckManager();
    restartGame();
}

bool Game::running()
{
    return isRunning;
}

void Game::restartGame()
{
    for (int i = 0; i < 2; i++)
    {
        deckManager.deal(player.hand);
        deckManager.deal(dealerHand);
    }
    firstTurn = true;
}

void Game::showHands()
{
    if (firstTurn)
    {
        std::cout << "Dealer's Hand: " << dealerHand[0].getFace() << " X";
        firstTurn = false;
    }
    else
    {
        std::cout << "Dealer's Hand: ";
        for (Card c : dealerHand)
        {
            std::cout << c.getFace() << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Player's Hand: ";
    for (Card c : player.hand)
    {
        std::cout << c.getFace() << " ";
    }
    std::cout << player.calcHandVal();
    std::cout << std::endl;
}

void Game::hitOrStand()
{
    bool valid = false;
    bool canPlay = true;
    std::string choice;

    while(canPlay)
    {
        while (!valid)
        {
            std::cout << "Hit or Stand: ";
            std::cin >> choice;
            switch (toupper(choice[0]))
            {
                case ('H'):
                    deckManager.deal(player.hand);
                    showHands();
                    valid = true;
                    break;
                case('S'):
                    player.stand();
                    valid = true;
                    break;
                default:
                    std::cout << "Invalid Input! Try again: " << std::endl;
                    break;
            }

            if (player.isBust() || player.isStanding()) canPlay = false;
        }
    }

    
}