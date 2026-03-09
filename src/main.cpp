#include "../include/order_book.h"
#include "../include/order.h"

int main()
{
    OrderBook book;

    Order o1(1, Side::Buy, 101, 10, 1);
    Order o2(2, Side::Buy, 102, 5, 2);
    Order o3(3, Side::Sell, 101, 8, 3);

    book.addOrder(o1);
    book.addOrder(o2);
    book.addOrder(o3);

    book.matchOrders();

    book.printBook();
}