#include "OrderBookManager.h"

void OrderBookManager::addSymbol(const std::string& symbol) {
	// if symbol doesn't exist
	if (books.find(symbol) == books.end()) {
		// create 
		books.emplace(symbol, OrderBook(symbol));
	}
}

int OrderBookManager::addOrder(const std::string& symbol, double orderPrice, int orderQuantity, bool orderType) {
	addSymbol(symbol);
	// Returns orderId
	return books.at(symbol).addOrder(orderPrice, orderQuantity, orderType);
}