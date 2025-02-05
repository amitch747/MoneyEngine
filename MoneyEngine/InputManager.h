#pragma once

#include <string>
#include "OrderBook.h"
#include "OrderBookManager.h"


class InputManager {
public:

	explicit InputManager(OrderBookManager& obm);

	void CommandInput(const std::string& command); // This should deal with everything, outputs False if input fails
	void OrderInput();

private:
	OrderBookManager& orderBookManager;
};