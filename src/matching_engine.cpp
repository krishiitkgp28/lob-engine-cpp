#include "../include/matching_engine.h"
#include "../include/execution_logger.h"
#include "../include/order_book.h"
#include <algorithm>

MatchingEngine::MatchingEngine(OrderBook& book) : book(book) {}

void MatchingEngine::processOrder(Order order)
{
    if(order.isBuy())
        processBuy(order);
    else
        processSell(order);
}

void MatchingEngine::processBuy(Order order)
{
    matchBuyOrder(order);

    if(order.quantity > 0)
        book.addOrder(order);
}

void MatchingEngine::processSell(Order order)
{
    matchSellOrder(order);

    if(order.quantity > 0)
        book.addOrder(order);
}

void MatchingEngine::matchBuyOrder(Order& order)
{
    int ask = book.bestAskIndex();

    while(order.quantity > 0 && ask != -1)
    {
        int askPrice = book.indexToPrice(ask);

        if(askPrice > order.price){
            break;
        }   
        auto& level = book.getAskLevel(ask);

        if(level.empty())
            break;

        Order& sell = level.front();

        int trade_qty = std::min(order.quantity, sell.quantity);

        order.quantity -= trade_qty;
        sell.quantity -= trade_qty;

        Trade trade(order.id, sell.id, askPrice, trade_qty, order.timestamp);
        TradeLog log{
            "AAPL",
            "BUY",
            askPrice,
            trade_qty,
            "PairsTrade"
        };

        log_trade(log);
        trade.print();

        if(sell.quantity == 0){
            book.removeLookup(sell.id);
            level.pop_front();

            if (level.empty() && ask == book.bestAskIndex()){
                int next = ask + 1;

                while(next < MAX_LEVELS)
                {
                    if(!book.getAskLevel(next).empty())
                        break;
                
                    next++;
                }


                book.updateBestAsk(next);
            }
        }
        ask = book.bestAskIndex();
    }
}

void MatchingEngine::matchSellOrder(Order& order)
{
    int bid = book.bestBidIndex();

    while(order.quantity > 0 && bid != -1)
    {
        int bidPrice = book.indexToPrice(bid);

        if(bidPrice < order.price){
            break;
        }
        auto& level = book.getBidLevel(bid);

        if(level.empty())
            break;
        Order& buy = level.front();

        int trade_qty = std::min(order.quantity, buy.quantity);

        order.quantity -= trade_qty;
        buy.quantity -= trade_qty;

        Trade trade(buy.id, order.id, bidPrice, trade_qty, order.timestamp);
        TradeLog log{
            "AAPL",
            "SELL",
            bidPrice,
            trade_qty,
            "PairsTrade"
        };
        
        log_trade(log);
        trade.print();

        if(buy.quantity == 0)
        {
            book.removeLookup(buy.id);
            level.pop_front();
        
            if(level.empty() && bid == book.bestBidIndex())
            {
                int next = bid - 1;
            
                while(next >= 0)
                {
                    if(!book.getBidLevel(next).empty())
                        break;
                
                    next--;
                }
            
                if(next < 0)
                    next = -1;
            
                book.updateBestBid(next);
            }
        }

        bid = book.bestBidIndex();
    }
}