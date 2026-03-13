#pragma once

#include <array>
#include <deque>
#include "order.h"
#include <unordered_map>

const int MAX_LEVELS = 10000;

struct OrderLocation
{
    Side side;
    int price_index;
    std::deque<Order>::iterator order_it;
};

class OrderBook
{
private:

    int base_price = 100;

    std::array<std::deque<Order>, MAX_LEVELS> bids;
    std::array<std::deque<Order>, MAX_LEVELS> asks;
    std::unordered_map<int, OrderLocation> order_lookup;
    int best_bid_index = -1;
    int best_ask_index  = MAX_LEVELS;
    
    public:
    
    int priceToIndex(int price) const;
    
    int indexToPrice(int index) const;
    
    void addOrder(const Order& order);
    
    void cancelOrder(int id);
    
    void printBook();
    
    int bestBidIndex();
    int bestAskIndex();

    void updateBestBid(int idx);
    void updateBestAsk(int idx);

    void removeLookup(int order_id);

    std::deque<Order>& getBidLevel(int index);
    std::deque<Order>& getAskLevel(int index);
};