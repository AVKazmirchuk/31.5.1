#include <iostream>
#include <string>

#include "../include/header.h"


shared_ptr_toy make_shared_toy(std::string&& str)
{
    return shared_ptr_toy(new Toy(str));
}

shared_ptr_toy make_shared_toy(Toy* toy)
{
    return shared_ptr_toy(toy);
}

int main()
{
    //shared_ptr_toy

    std::cout << "\nshared_ptr_toy\n\n";

    {
        auto ptrToy = shared_ptr_toy(new Toy);
        {
            auto ptrToy_2(ptrToy);
        }
        std::cout << "1.1---------------------\n";
    }
    std::cout << "1.2---------------------\n";

    {
        auto ptrToy = shared_ptr_toy(new Toy);
        {
            auto ptrToy_2 = ptrToy;
        }
        std::cout << "1.3---------------------\n";
    }
    std::cout << "1.4---------------------\n";

    {
        shared_ptr_toy ptrToy;
        ptrToy = new Toy;
        {
            auto ptrToy_2 = ptrToy;
        }
        std::cout << "1.5---------------------\n";
    }
    std::cout << "1.6---------------------\n";

    {
        shared_ptr_toy ptrToy;
        Toy* toy = new Toy;
        ptrToy = toy;
        {
            auto ptrToy_2 = ptrToy;
        }
        std::cout << "1.7---------------------\n";
    }
    std::cout << "1.8---------------------\n";

    //make_shared_toy

    std::cout << "\nmake_shared_toy\n\n";

    {
        auto ptrToy = make_shared_toy("Ball");
        {
            auto ptrToy_2(ptrToy);
        }
        std::cout << "2.1---------------------\n";
    }
    std::cout << "2.2---------------------\n";

    {
        Toy* toy = new Toy;
        auto ptrToy = make_shared_toy(toy);
        {
            auto ptrToy2 = ptrToy;
        }
        std::cout << "2.3---------------------\n";
    }
    std::cout << "2.4---------------------\n";
}