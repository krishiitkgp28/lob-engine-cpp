#pragma once

#include <string>

struct TradeLog
{
    std::string symbol;
    std::string side;
    int price;
    int qty;
    std::string strategy;
};

void log_trade(const TradeLog& trade);