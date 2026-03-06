#ifndef TRADE_H
#define TRADE_H

#include <iostream>
#include <stdexcept>

struct Trade
{
    int buy_order_id;
    int sell_order_id;
    double price;
    int quantity;
    long timestamp;

    Trade(int buyId, int sellId, double price, int quantity, long timestamp) : buy_order_id(buyId), sell_order_id(sellId), price(price), quantity(quantity), timestamp(timestamp)
    {
        if (quantity <= 0)
            throw std::invalid_argument("Quantity must be positive.");
    }

    void print() const
    {
        std::cout << "Order["
                  << "buy=" << buy_order_id
                  << ", sell=" << sell_order_id
                  << ", price=" << price
                  << ", quantity=" << quantity
                  << ", timestamp=" << timestamp
                  << "]\n";
    }
};

#endif