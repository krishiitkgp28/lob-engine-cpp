# Limit Order Book Architecture

Core Components:

Order
Represents an incoming order with price, quantity, side, and id.

Trade
Represents an executed match between a buy and sell order.

OrderBook
Maintains price levels for bids and asks.

MatchingEngine
Matches incoming orders using price-time priority.

LimitOrderBook
High-level API used by trading systems to interact with the order book.

Flow:

Incoming Order
     ↓
LimitOrderBook::addOrder
     ↓
MatchingEngine
     ↓
Trade Generated
     ↓
OrderBook Updated