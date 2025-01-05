#pragma once

#include <unordered_map>
#include <string>
#include "OrderBook.h"

class OrderBookManager {
public:
	void addSymbol(const std::string& symbol);

	int addOrder(const std::string& symbol, double orderPrice, int orderQuantity, bool orderType);

	void matchAllOrders();

private:
	std::unordered_map<std::string, OrderBook> books;
};