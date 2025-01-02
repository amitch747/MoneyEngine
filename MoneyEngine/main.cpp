#include <iostream>
#include "OrderBookManager.h"


int main()
{
    std::cout << "Starting Engine\n";

    OrderBookManager orderBookManager;

    std::cout << "\nPLTR\n" << std::endl;
    orderBookManager.addOrder("PLTR", 100.0, 10, true);   // Buy 10@100
    orderBookManager.addOrder("PLTR", 99.5, 5, false);    // Sell 5@99.5
    orderBookManager.addOrder("PLTR", 98.0, 2, false);    // Sell 2@98
    orderBookManager.addOrder("PLTR", 101.0, 10, true);   // Buy 10@101

    std::cout << "\nTSLA\n" << std::endl;
    orderBookManager.addOrder("TSLA", 200.0, 3, true);    // Buy 3@200
    orderBookManager.addOrder("TSLA", 199.0, 5, false);   // Sell 5@199
    orderBookManager.addOrder("TSLA", 202.0, 1, false);   // Sell 1@202
    orderBookManager.addOrder("TSLA", 210.0, 4, false);   // Sell 4@210
    orderBookManager.addOrder("TSLA", 205.0, 2, true);    // Buy 2@205

    std::cin.get();
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
