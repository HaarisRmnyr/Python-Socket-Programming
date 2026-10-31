# Python Socket Programming Experiments

A sandbox repository for exploring low-level network programming, TCP/IP socket lifecycles, and concurrency models using Python's built-in `socket` and `selectors` libraries.

## 📂 Repository Structure

```text
python-socket-programming/
│
├── basic-echo/
│   ├── server.py       # Single-connection blocking echo server
│   └── client.py       # Basic echo client
│
└── multiconn/
    └── multiconn.py    # Multiplexed multi-connection server using selectors
