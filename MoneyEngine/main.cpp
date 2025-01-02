#include <iostream>
#include "OrderBookManager.h"


int main()
{
    std::cout << "Starting Engine\n";

    OrderBookManager orderBookManager;

    std::cout << "\nPLTR" << std::endl;
    orderBookManager.addOrder("PLTR", 100.0, 10, true);  
    orderBookManager.addOrder("PLTR", 99.5, 5, false); 
    orderBookManager.addOrder("PLTR", 98.0, 2, false);
    orderBookManager.addOrder("PLTR", 101.0, 10, true);

    std::cout << "\nTSLA" << std::endl;
    orderBookManager.addOrder("TSLA", 200.0, 3, true);
    orderBookManager.addOrder("TSLA", 199.0, 5, false);
    orderBookManager.addOrder("TSLA", 202.0, 1, false);
    orderBookManager.addOrder("TSLA", 210.0, 4, false);
    orderBookManager.addOrder("TSLA", 205.0, 2, true);

    std::cin.get();
    return 0;

}