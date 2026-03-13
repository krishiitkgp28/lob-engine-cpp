#pragma once

#include "order_book.h"
#include "trade.h"

class MatchingEngine
{
private:
    OrderBook& book;

public:
    MatchingEngine(OrderBook& book);

    void processOrder(Order order);

private:
    void processBuy(Order order);
    void processSell(Order order);

    void matchBuyOrder(Order& order);
    void matchSellOrder(Order& order);
};