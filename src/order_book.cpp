#include <iostream>
#include <functional>
#include <map>

class OrderBook
{
private:
    std::map<double, int, std::greater<double>> bids;
    std::map<double, int> asks;

public:
    void addBid(double price, int qty)
    {
        bids[price] += qty;
    }
    void addAsk(double price, int qty)
    {
        asks[price] += qty;
    }

    double bestBid()
    {
        if (bids.empty())
            return 0;

        return bids.begin() -> first;
    }
    double bestAsk()
    {
        if (asks.empty())
            return 0;

        return asks.begin()->first;
    }

    void printBook(){
        std::cout << "\nBIDS:\n";
        for ( auto &b : bids ){
            std::cout << b.first << " : " << b.second << "\n";
        }

        std::cout << "\nASKS:\n";
        for ( auto &a : asks ){
            std::cout << a.first << " : " << a.second << "\n";
        }
    };
};