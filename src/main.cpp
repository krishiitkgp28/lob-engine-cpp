#include "../include/order_book.h"
#include "../include/order.h"
#include "../include/matching_engine.h"

int main()
{
    OrderBook book;

    Order o1(1, Side::Sell, 101, 100, 1);
    Order o2(2, Side::Sell, 101, 50, 2);
    Order o3(3, Side::Buy, 101, 120, 3);

    MatchingEngine engine(book);

    engine.processOrder(o1);
    engine.processOrder(o2);
    engine.processOrder(o3);
    
    book.cancelOrder(2);

    book.printBook();
}