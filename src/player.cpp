#include "player.h"

Player::Player()
{
    standing = false;
    bust = false;
    bank = 1000.0;
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
        for (Card &c : hand)
        {
            if (c.getValue() == 11)
            {
                c.checkHard();
                return isBust();
            }
        }
        bust = true;
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

void Player::playerReset()
{
    standing = false;
    bust = false;
}

void Player::returnBet(double amount)
{
    bank += amount;
}

double Player::getBankAmount()
{
    return bank;
}