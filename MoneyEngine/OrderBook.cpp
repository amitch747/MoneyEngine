#include "OrderBook.h"


OrderBook::OrderBook(const std::string& symbol) : nextOrderId(1), ticker(symbol){}

int OrderBook::addOrder( double orderPrice, int orderQuantity, bool orderType) {

	Order newOrder {
		nextOrderId++,
		orderPrice,
		orderQuantity,
		orderType
	};
	std::string orderConfig;
	std::string colorConfig;

	if (orderType == true) {
		buyOrders[orderPrice].push_back(newOrder);
		orderConfig = "Buy";
		colorConfig = "\033[32m";
	}
	else { 
		sellOrders[orderPrice].push_back(newOrder); 
		orderConfig = "Sell";
		colorConfig = "\033[31m";

	}


	std::cout << colorConfig << orderConfig << " order placed for "
		<< orderQuantity << " shares of " << ticker << "(" << 
		newOrder.orderId << ")\033[0m" << std::endl;


	// After updating our maps, we try and match
	//matchOrders();
	return newOrder.orderId;
}

void OrderBook::matchOrders() {
	// Loop while there are possible matches
	std::cout << "Matching orders for: " << ticker << "\n";
	if (buyOrders.empty() || sellOrders.empty()) {
		std::cout << "\033[33mNO POSSIBLE TRADES\033[0m" << std::endl;
	}
	while (!buyOrders.empty() && !sellOrders.empty()) {

		// Get highest buy price (first key)
		double bestBuyPrice = buyOrders.begin()->first;
		// Get lowest sell price (first key)
		double bestSellPrice = sellOrders.begin()->first;

		// No matches, exit
		if (bestBuyPrice < bestSellPrice) {

			break; 
		}

		// Passing previous check means we have overlap, we can trade
		// Get refs to lists for best buy and sell prices
		auto& buyList = buyOrders.begin()->second;
		auto& sellList = sellOrders.begin()->second;

		// Get refs to front of each list
		Order& buyOrder = buyList.front();
		Order& sellOrder = sellList.front();


		int tradeQuantity = std::min(buyOrder.orderQuantity, sellOrder.orderQuantity);

		std::cout << "[Ticker: " << ticker << "] " << "Trade executed: "
			<< tradeQuantity << " shares at " << sellOrder.orderPrice << std::endl;

		// Update quantities
		buyOrder.orderQuantity -= tradeQuantity;
		sellOrder.orderQuantity -= tradeQuantity;

		if (buyOrder.orderQuantity == 0) {
			// Remove order
			buyList.pop_front();
			if (buyList.empty()) {
				// Remove key, no more orders at price
				buyOrders.erase(bestBuyPrice);
			}
		}
		if (sellOrder.orderQuantity == 0) {
			// Remove order
			sellList.pop_front();
			if (sellList.empty()) {
				// Remove key, no more orders at price
				sellOrders.erase(bestSellPrice);
			}
		}

	}
}