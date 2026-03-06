#include "../src/lob_engine.cpp"

int main () {
    LimitOrderBook book ;

    Order order1{ 1 , Buy , 100.5 , 10 };

    book.addOrder(order1);

    book.cancelOrder(1);

    return 0;
}