#include "../include/execution_logger.h"

#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

void log_trade(const TradeLog& trade)
{
    static std::ofstream file("trade_log.txt", std::ios::app);
    if (!file.is_open()) return;

    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm* tm = std::localtime(&t);

    file << "["
         << std::put_time(tm, "%H:%M:%S")
         << "] STRAT=" << trade.strategy
         << " " << trade.side
         << " " << trade.symbol
         << " price=" << trade.price
         << " qty=" << trade.qty
         << "\n";
}