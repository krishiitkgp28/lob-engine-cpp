#include <iostream>
#include "../src/order_book.cpp"

int main()
{
    OrderBook book;

    book.addBid(100.1,10);
    book.addBid(100.3,5);
    book.addBid(99.9,2);

    book.addAsk(100.5,8);
    book.addAsk(100.7,4);

    std::cout << "Best Bid: " << book.bestBid() << std::endl;
    std::cout << "Best Ask: " << book.bestAsk() << std::endl;

    book.printBook();

    return 0;
}