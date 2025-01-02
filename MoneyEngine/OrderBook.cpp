#include "OrderBook.h"


OrderBook::OrderBook(const std::string& symbol) : nextOrderId(1), ticker(symbol){}

int OrderBook::addOrder( double orderPrice, int orderQuantity, bool orderType) {

	// Create new order
	Order newOrder {
		nextOrderId++,
		orderPrice,
		orderQuantity,
		orderType
	};

	// Create key at price or add to end of list if exists
	if (orderType == true) { buyOrders[orderPrice].push_back(newOrder); }
	else { sellOrders[orderPrice].push_back(newOrder); }

	// After updating our maps, we try and match
	matchOrders();

	std::cout << "Order added:" << newOrder.orderId << std::endl;
	return newOrder.orderId;
}

void OrderBook::matchOrders() {
	// Loop while there are possible matches
	while (!buyOrders.empty() && !sellOrders.empty()) {

		// Get highest buy price (first key)
		double bestBuyPrice = buyOrders.begin()->first;
		// Get lowest sell price (first key)
		double bestSellPrice = sellOrders.begin()->first;

		// Can't match in this case
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