#ifndef ORDER_H
#define ORDER_H

enum Side
{
    BUY,
    SELL
};

struct Order
{
    int id;
    Side side;
    double price;
    int quantity;
};

#endif