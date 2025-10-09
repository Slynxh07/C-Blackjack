#include "game.h"

Game::Game()
{
    isRunning = true;
    player = Player();
    deckManager = DeckManager();
    //restartGame();
}

bool Game::running()
{
    return isRunning;
}

void Game::restartGame()
{
    player.hand.clear();
    dealerHand.clear();
    deckManager.initDeck();
    deckManager.shuffleDeck();
    player.playerReset();
    for (int i = 0; i < 2; i++)
    {
        deckManager.deal(player.hand);
        deckManager.deal(dealerHand);
    }
    dealerShow = false;
}

void Game::showHands()
{
    if (!dealerShow)
    {
        std::cout << "Dealer's Hand: " << dealerHand[0].getFace() << " X";
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
                    canPlay = !player.isBust();
                    showHands();
                    valid = true;
                    break;
                case('S'):
                    player.stand();
                    canPlay = !player.isStanding();
                    dealerShow = true;
                    valid = true;
                    break;
                default:
                    std::cout << "Invalid Input! Try again: " << std::endl;
                    break;
            }
        }
        valid = false;
    }

    
}

void Game::playGame()
{
    restartGame();
    showHands();
    hitOrStand();
}