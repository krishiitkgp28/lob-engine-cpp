#ifndef ORDER_H // INSTEAD WE CAN USE #pragma once
#define ORDER_H 

#include <iostream>
#include <stdexcept>

enum class Side
{
    Buy,
    Sell
};

struct Order
{
    int id;
    Side side;
    int price;
    int quantity;
    long timestamp;

    Order(int id, Side side, double price, int quantity, long timestamp) : id(id), side(side), price(price), quantity(quantity), timestamp(timestamp)
    {
        if (quantity <= 0)
            throw std::invalid_argument("Quantity must be positive.");

        if (price <= 0)
            throw std::invalid_argument("Price must be positive.");
    }

    bool isBuy() const
    {
        return side == Side::Buy;
    }

    void print() const
    {
        std::cout << "Order["
                  << "id=" << id
                  << ", side=" << (side == Side::Buy ? "Buy" : "Sell")
                  << ", price=" << price
                  << ", quantity=" << quantity
                  << ", timestamp=" << timestamp
                  << "]\n";
    }
};

#endif