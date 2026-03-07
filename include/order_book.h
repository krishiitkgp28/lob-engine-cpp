#pragma once

#include <map>
#include <functional>

class OrderBook
{
private:

    std::map<double, int, std::greater<double>> bids;
    std::map<double, int> asks;

public:

    void addBid(double price, int qty);

    void addAsk(double price, int qty);

    double bestBid();

    double bestAsk();

    void printBook();
};