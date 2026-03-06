#include "../include/lob_engine.h"
#include <iostream>

void LimitOrderBook::addOrder(const Order& order) {
    std::cout << "Adding order id : " << order.id << "\n";
};

void LimitOrderBook::cancelOrder(int id) {
    std::cout << "Cancelling order id : " << id << "\n";
};