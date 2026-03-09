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

    if(order.isBuy())
        bids[idx].push_back(order);
    else
        asks[idx].push_back(order);
}

int OrderBook::bestBidIndex()
{
    for ( int i = MAX_LEVELS - 1 ; i >= 0 ; i--)
    {
        if(!bids[i].empty()){
            return i;
        }
    }
    return -1;
}

int OrderBook :: bestAskIndex()
{
    for ( int i = 0 ; i< MAX_LEVELS ;i++)
    {
        if (!asks[i].empty()){
            return i;
        }

    }
    return -1;
}

void OrderBook::printBook(){
    std::cout << "\nBIDS:\n";
    for ( int i = MAX_LEVELS-1 ; i>=0 ; i--){
        if(!bids[i].empty()){
            int price = base_price + i;
            std::cout << price << " : "
                      << bids[i].size() << "\n";
            
        }
    }

    std::cout << "\nASKS:\n";
    for ( int i = 0 ; i<MAX_LEVELS ; i++){
        if(!asks[i].empty()){
            int price = base_price + i;
            std::cout << price << " : "
                      << asks[i].size() << "\n";
            
        }
    }
}

void OrderBook::matchOrders()
{
    int bid = bestBidIndex();
    int ask = bestAskIndex();

    while(bid != -1 && ask != -1 && bid >= ask)
    {
        Order &buy = bids[bid].front();
        Order &sell = asks[ask].front();

        int trade_qty = std::min(buy.quantity, sell.quantity);

        buy.quantity -= trade_qty;
        sell.quantity -= trade_qty;

        std::cout << "TRADE "
                  << indexToPrice(ask)
                  << " qty "
                  << trade_qty
                  << "\n";

        if(buy.quantity == 0)
            bids[bid].pop_front();

        if(sell.quantity == 0)
            asks[ask].pop_front();

        bid = bestBidIndex();
        ask = bestAskIndex();
    }
}