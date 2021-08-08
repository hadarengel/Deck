#include <iostream>
#include <time.h>
#include "Deck.h"


int main(int argc, char const *argv[])
{
    srand(time(nullptr));
    Dadu::Deck deck(10);
    std::cout << "deck size:" << deck.getDeckSize() << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout<< deck.pullIndex() <<" ";
    }
    std::cout << std::endl << "deck size:"<< deck.getCurrentSize() << std::endl;
    for (int i = 0; i < 5; i++)
    {
        deck.pushIndex(i*2);
        std::cout << std::endl << "deck size:"<< deck.getCurrentSize() << std::endl;
    }
    for (int i = 0; i < 6; i++)
    {
        try
        {
            std::cout<< deck.pullIndex() <<" ";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout<<"succes"<<std::endl;
    return 0;
}
