# C++ Limit Order Book Engine

A simple price-time priority limit order book implemented in C++.

Project goals:
- Understand market microstructure
- Build low-latency trading infrastructure
- Practice systems-level C++

Architecture:

Order
↓
LimitOrderBook
↓
Matching Engine
↓
Trade