#include "../include/lob_engine.h"
#include "../include/order.h"

int main()
{
    LimitOrderBook book;

    Order order1{1, Side::BUY, 100.5, 10, 1001};
    Order order2{2, Side::SELL, 100.5, 10, 1002};

    order1.print();
    order2.print();

    book.addOrder(order1);
    book.addOrder(order2);

    book.cancelOrder(1);

    return 0;
}