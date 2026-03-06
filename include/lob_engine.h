#ifndef LOB_ENGINE_H
#define LOB_ENGINE_H

#include "./order.h"

class LimitOrderBook {
    public:
        void addOrder(const Order& order);

        void cancelOrder(int id);
};

#endif