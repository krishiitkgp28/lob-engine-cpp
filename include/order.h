#ifndef ORDER_H
#define ORDER_H

enum Side {
    Buy,
    Sell
};

struct Order {
    int id;
    Side side;
    double price;
    int quantity;
};

#endif 