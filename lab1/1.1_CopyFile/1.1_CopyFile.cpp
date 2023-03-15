// 1.1_CopyFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << argc << "\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }
    return 0;
}
