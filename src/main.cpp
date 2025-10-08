#include <iostream>
#include "game.h"

int main()
{
        Game game;
        char input;

        while (true)
        {
                game.showHands();
                game.hitOrStand();
                std::cout << "Play again (Y/N): ";
                std::cin >> input;
                if (toupper(input) != 'Y')
                {
                        break;
                }
        }
        return 0;
}