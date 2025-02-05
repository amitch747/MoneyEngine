#include "InputManager.h"

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "OrderBook.h"
#include "OrderBookManager.h"
#include <functional>


InputManager::InputManager(OrderBookManager& obm) : orderBookManager(obm) {};

void InputManager::CommandInput(const std::string& command)
{
    // Command function map
    static const std::unordered_map<std::string, std::function<void()>> commandHandlers = {
        {"ORDER", [this]() { this->OrderInput(); }},
        {"LIST", [this]() {orderBookManager.displayActiveOrders(); }}

    };

    if (!command.empty()) { // Users can press enter to skip input
        std::cout << "Command is: " << command << "\n";
        {
            auto it = commandHandlers.find(command);
            if (it != commandHandlers.end()) {
                it->second();  // Call the function without returning anything
                return;        // Exit the function after execution
            }
        }
        std::cout << "Unknown command!" << std::endl;
    }
}

void InputManager::OrderInput()
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
    orderBookManager.addOrder(symbol, price, quantity, isBuy);

    return;
}
