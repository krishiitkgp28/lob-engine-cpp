#include "../include/order_book.h"
#include <iostream>

void OrderBook::addBid(double price, int qty)
{
    bids[price] += qty;
}

void OrderBook::addAsk(double price, int qty)
{
    asks[price] += qty;
}

double OrderBook::bestBid()
{
    if (bids.empty())
        return 0;

    return bids.begin()->first;
}

double OrderBook::bestAsk()
{
    if (asks.empty())
        return 0;

    return asks.begin()->first;
}

void OrderBook::printBook()
{
    std::cout << "\nBIDS\n";

    for (auto &b : bids)
    {
        std::cout << b.first << " : " << b.second << "\n";
    }

    std::cout << "\nASKS\n";

    for (auto &a : asks)
    {
        std::cout << a.first << " : " << a.second << "\n";
    }
}