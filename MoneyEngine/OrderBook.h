#pragma once

#include <map>
#include <list>
#include <iostream>
#include <string>

struct Order {
	int orderId;
	double orderPrice;
	int orderQuantity;
	bool orderType; // True = buy, False = sell
};

class OrderBook {
private:
	// std::greater reverses the sorting order so we have highest (best) first
	std::map<double, std::list<Order>, std::greater<double>> buyOrders; 
	// lowest sell is first here
	std::map<double, std::list<Order>> sellOrders;

	// Running counter of orders
	int nextOrderId;

	//Different book for each ticker
	std::string ticker;

public:
	OrderBook(const std::string& symbol);

	int addOrder(double orderPrice, int orderQuantity, bool orderType);

	void matchOrders();
};