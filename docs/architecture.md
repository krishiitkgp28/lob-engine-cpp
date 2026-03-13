Limit Order Book Architecture

Core Structures

Order
Represents a buy or sell request submitted to the exchange.

Fields:
id
side
price
quantity
timestamp

Trade
Represents an executed match between a buy and sell order.

Fields:
buyOrderId
sellOrderId
price
quantity
timestamp

Matching Principle

Price-Time Priority

Higher price buy orders execute first.
Lower price sell orders execute first.
If prices are equal, earlier timestamp wins.

Price Ladder

The order book uses a fixed price ladder indexed by price:

index = price - base_price

Each price level stores a FIFO queue of orders.