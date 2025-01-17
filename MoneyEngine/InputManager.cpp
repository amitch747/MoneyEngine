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

std::string InputManager::ParametersInput(const std::string& parameters)
{
    //std::istringstream inputStream(parameters);
    //std::string ticker, orderType;
    //double price;
    //int quantity;
    //inputStream >> ticker >> price >> quantity >> orderType;

    //bool isBuy = (orderType == "BUY");
    //orderBookManager.addOrder(ticker, price, quantity, isBuy);



	return std::string();
}
