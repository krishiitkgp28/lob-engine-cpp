#include "../include/lob_engine.h"

int main()
{
    LimitOrderBook book;

    Order order1{1, BUY, 100.5, 10};

    book.addOrder(order1);

    book.cancelOrder(1);

    return 0;
}