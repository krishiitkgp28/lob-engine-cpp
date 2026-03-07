#pragma once

#include "order.h"

class LimitOrderBook
{
public:
    void addOrder(const Order &order);

    void cancelOrder(int id);
};

#