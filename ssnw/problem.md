# Something, something network
__Problem ID__: _socket_

Most applications in 2014 often have to communicate with servers or other
clients. An important aspect of this communication is to have a well defined
protocol, so that messages are understood correctly by all parties.

In this task you must be able to transmit two numbers to our server using our
protocol. The server will reply with a key that can vary in length up to the
total message size (2<sup>8</sup> bytes).

Our server (IP `10.133.234.216`) is running at UDP port `3950`. However, this
server is only for submission and is not accessible from the UiO network. For
testing, we have another address: (DNS `vor.ifi.uio.no`) on UDP port `3950`. We
assume that you hardcode these parameters into your code. Double check that you
are using the first IP (10...) on submission and the second one (DNS: vor....)
for testing.

## Protocol
Both clients and the server should send messages conforming to the following
protocol over UDP. It is important that you use the exact length in 
all fields, and send via network order endian where applicable.

![](../images/protocol.png)

- Total message size: Number of bytes in message
- Message type is defined as:
    - 0x02 - Key request sent from client to server
    - 0x03 - Key response from server
- Input field 1/2: numbers read from stdin

## Input
Input consists of two space separated numbers.

## Output
Your program should output the key as received from the server.

## Sample input
```
4 4
```

## Sample output
```
15192330574732399515
```
