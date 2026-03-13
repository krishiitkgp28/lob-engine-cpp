# C++ Limit Order Book & Matching Engine

This project implements a simplified **electronic exchange limit order book** in C++ using price-time priority.

It is designed as a learning project for **quantitative developer / HFT infrastructure roles**.

---

## Features

* Price-time priority matching
* Fixed price ladder using `std::array`
* FIFO order queues using `std::deque`
* O(1) order cancellation via lookup table
* Partial order fills
* Best bid / best ask tracking
* Trade logging to file

---

## Architecture

```
Incoming Order
     ↓
MatchingEngine
     ↓
OrderBook
     ↓
Price Levels (bids / asks)
     ↓
Trade Generated
```

Core components:

| Component       | Responsibility                        |
| --------------- | ------------------------------------- |
| Order           | Represents an incoming buy/sell order |
| Trade           | Represents executed trade             |
| OrderBook       | Stores price levels and order queues  |
| MatchingEngine  | Implements price-time matching logic  |
| ExecutionLogger | Logs executed trades                  |

---

## Price Ladder Design

Instead of using slow containers like `std::map`, the order book uses a **fixed price ladder**:

```
std::array<std::deque<Order>, MAX_LEVELS>
```

Advantages:

* O(1) price level access
* cache-friendly memory
* predictable latency

---

## Example

Orders submitted:

```
Sell 100 @101
Sell 50  @101
Buy 120 @101
```

Trades generated:

```
Trade[buy=3 sell=1 price=101 quantity=100]
Trade[buy=3 sell=2 price=101 quantity=20]
```

Remaining book:

```
ASKS
101 : 30
```

---

## Build

```
g++ src/*.cpp -o lob
```

Run:

```
./lob
```

---

## Learning Goals

This project demonstrates core exchange concepts:

* limit order book design
* price-time priority
* matching engine logic
* constant-time order cancellation
* cache-friendly data structures

Future improvements:

* market orders
* memory pool allocator
* intrusive order queues
* latency benchmarking
