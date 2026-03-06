#ifndef TRADE_H
#define TRADE_H

struct Trade {
    int buy_order_id;
    int sell_order_id;
    double price;
    int quantity;
};

#endif