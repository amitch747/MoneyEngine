#include "InputManager.h"

#include <iostream>
#include <string>
#include <sstream>


std::string InputManager::CommandInput(const std::string& command)
{
    if (!command.empty()) { // Users can press enter to skip input
        if (command == "EXIT") {
            std::cout << "Command is: " << command << "\n";

            return std::string("EXIT"); //Another option to exit program
        }
        else if (command == "ORDER") {
            std::cout << "Command is: " << command << "\n";
            return std::string("ORDER"); //Another option to exit program
        }
        else {
            std::cout << "Command is: " << command << "\n";
            return std::string("INVALID");
        }
    }
    return std::string("INVALID");
}

std::string InputManager::OrderInput()
{
    std::string colorPrompt = "\033[34m"; // Blue for prompt
    std::string reset = "\033[0m";       // Reset color
    std::cout << "Handling Order" << std::endl;
    std::cout << colorPrompt << "Enter order (\"[BUY/SELL] [SYMBOL] [PRICE] [QUANTITY]\"): " << reset;

    std::string parameters;
    std::getline(std::cin, parameters);
    std::istringstream inputStream(parameters);
    std::string orderType, symbol;
    double price;
    int quantity;
    inputStream >> orderType >> symbol >> price >> quantity;

    bool isBuy = (orderType == "BUY");
    //orderBookManager.addOrder(symbol, price, quantity, isBuy);

	return std::string();
}
