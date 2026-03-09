#pragma once

#include <array>
#include <deque>
#include "order.h"

const int MAX_LEVELS = 10000;

class OrderBook
{
private:

    int base_price = 100;

    std::array<std::deque<Order>, MAX_LEVELS> bids;
    std::array<std::deque<Order>, MAX_LEVELS> asks;

public:

    int priceToIndex(int price) const;

    int indexToPrice(int index) const;

    void addOrder(const Order& order);

    void matchOrders();

    void cancelOrder(int id);

    void printBook();

    int bestBidIndex();

    int bestAskIndex();
};