#include "../include/order_book.h"
#include <iostream>

int OrderBook::priceToIndex(int price) const
{
    int idx = price - base_price;

    if(idx < 0 || idx >= MAX_LEVELS)
        throw std::out_of_range("Price outside ladder range");

    return idx;
}

int OrderBook::indexToPrice(int index) const
{
    return index + base_price;
}

void OrderBook::addOrder(const Order& order)
{
    int idx = priceToIndex(order.price);

    if(order.isBuy()) {
        bids[idx].push_back(order);
        auto it = std::prev(bids[idx].end());

        order_lookup[order.id] = {Side::Buy, idx, it};

        if (idx > best_bid_index) {
            best_bid_index = idx;
        }
    } 
    else {
        asks[idx].push_back(order);
        auto it = std::prev(asks[idx].end());

        order_lookup[order.id] = {Side::Sell, idx, it};
        if (idx < best_ask_index) {
            best_ask_index = idx;
        }
    }
}

int OrderBook::bestBidIndex()
{
    if(best_bid_index == -1)
        return -1;

    return best_bid_index;
}

int OrderBook::bestAskIndex()
{
    if(best_ask_index == MAX_LEVELS)
        return -1;

    return best_ask_index;
}

void OrderBook::printBook(){
    std::cout << "\nBIDS:\n";
    for ( int i = MAX_LEVELS-1 ; i>=0 ; i--){
        if(!bids[i].empty()){
            int price = base_price + i;
            int totalQty = 0;

            for(const auto& o : bids[i])
                totalQty += o.quantity;

            std::cout << price << " : "
                      << totalQty << "\n";

        }
    }

    std::cout << "\nASKS:\n";
    for ( int i = 0 ; i<MAX_LEVELS ; i++){
        if(!asks[i].empty()){
            int price = base_price + i;
            int totalQty = 0;

            for(const auto& o : asks[i])
                totalQty += o.quantity;
            
                std::cout << price << " : "
                          << totalQty << "\n";
        }
    }
}

std::deque<Order>& OrderBook::getBidLevel(int index)
{
    return bids[index];
}

std::deque<Order>& OrderBook::getAskLevel(int index)
{
    return asks[index];
}

void OrderBook::updateBestBid(int idx)
{
    best_bid_index = idx;
}

void OrderBook::updateBestAsk(int idx)
{
    best_ask_index = idx;
}

void OrderBook::cancelOrder(int id)
{
    if(order_lookup.find(id) == order_lookup.end())
        return;

    OrderLocation loc = order_lookup[id];

    if(loc.side == Side::Buy)
    {
        bids[loc.price_index].erase(loc.order_it);
    }
    else
    {
        asks[loc.price_index].erase(loc.order_it);
    }

    order_lookup.erase(id);

    if(loc.side == Side::Buy)
    {
        if(bids[loc.price_index].empty() && loc.price_index == best_bid_index)
        {
            int next = loc.price_index - 1;
            while(next >= 0 && bids[next].empty())
                next--;

            best_bid_index = next; 
        }
    }
    else if(loc.side == Side::Sell) 
    {
        if(asks[loc.price_index].empty() && loc.price_index == best_ask_index)
        {
            int next = loc.price_index + 1;

            while(next < MAX_LEVELS && asks[next].empty()) 
                next++;

            best_ask_index = next; 
        }
    }

    
}

void OrderBook::removeLookup(int id)
{
    order_lookup.erase(id);
}