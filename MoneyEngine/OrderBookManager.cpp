#include "OrderBookManager.h"
#include <unordered_map>




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

void OrderBookManager::matchAllOrders() {
	for (auto& [symbol, orderBook] : books) {
		orderBook.matchOrders();
	}
}
void OrderBookManager::displayActiveOrders()
{
    for (const auto& [symbol, orderBook] : books) {
        std::cout << "Symbol: " << symbol << std::endl;
        std::cout << "Buy Orders:\n";
        for (const auto& [price, orderList] : orderBook.getBuyOrders()) {
            std::cout << " Price: " << price << std::endl;
            for (const auto& order : orderList) {
                std::cout << "Order Quantitiy : " << order.orderQuantity << std::endl;
            }
        }

        std::cout << "Sell Orders:\n";
        for (const auto& [price, orderList] : orderBook.getSellOrders()) {
            std::cout << "Price: " << price << std::endl;
            for (const auto& order : orderList) {
                std::cout << "Order Quantitiy: " << order.orderQuantity << std::endl;
            }
        }
        std::cout << "\n";
    }
}

