#include <iostream>
#include <random>
int main()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(5, 9); // define the range

    for(int n=0; n<10; ++n)
        std::cout << distr(gen) <<","; // generate numbers
}
