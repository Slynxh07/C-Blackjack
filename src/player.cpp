#include "player.h"

Player::Player()
{
    standing = false;
    bust = false;
}

void Player::stand()
{
    standing = true;
}

bool Player::isStanding()
{
    return standing;
}

bool Player::isBust()
{
    if (calcHandVal() > 21)
    {
        for (Card c : hand)
        {
            if (c.getValue() == 11)
            {
                c.checkHard(calcHandVal());
                return isBust();
            }
        }
        bust = true;
        std::cout << "BUST! You lose";
    }
    return bust;
}

int Player::calcHandVal()
{
    int sum = 0;
    for (Card c : hand)
    {
        sum += c.getValue();
    }
    return sum;
}