#include "game.h"

Game::Game()
{
    player = Player();
    deckManager = DeckManager();
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
    std::cout << "===============================";
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
    std::cout << std::endl << "Player Hand Value: " << player.calcHandVal();
    std::cout << std::endl << "Dealer Hand Value: " << dealerHandVal();
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

void Game::dealerPlay()
{
    dealerShow = true;
    showHands();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    while (dealerHandVal() < 17)
    {
        deckManager.deal(dealerHand);
        showHands();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int Game::dealerHandVal()
{
    if (!dealerShow) return dealerHand[0].getValue();
    int sum = 0;
    for (Card c : dealerHand)
    {
        sum += c.getValue();
    }
    return sum;
}

bool Game::dealerBust()
{
    if (dealerHandVal() > 21)
    {
        for (Card &c : dealerHand)
        {
            if (c.getValue() == 11)
            {
                c.checkHard();
                return dealerBust();
            }
        }
        return true;
    }
    return false;
}

bool Game::playerWin()
{
    if (player.isBust()) return false;
    else if (dealerBust()) return true;
    
    if (player.calcHandVal() > dealerHandVal()) return true;
    else return false;
}

void Game::playGame()
{
    restartGame();
    showHands();
    hitOrStand();
    if (!player.isBust())
    {
        dealerPlay();
    }
    if (playerWin()) std::cout << "You win!" << std::endl;
    else std::cout << "You lose!" << std::endl;
}