# Something, something network

Applications in 2014 often requeres to communicate with either servers, or 
other clients. An important aspect of this communication is a well defined
protocol so that messages passed are understood correctly by all parties.

In this task you must be able to send two inputs to our server via our defined
protocol. The server will reply with a key that can vary in length up to the
total message size. (2^8 bytes).

In this task we have prepared a server running on port 3950 at vor.ifi.uio.no.
you can use this when you are testing, but when you deliver you must make
sure that your client is connecting to 178.62.248.162 at port 3950.

## Input
Input is two integers with newlines separating them.

## Output
Your program should output the key you got from the server.

## Constraints

Our server is using the protocol described here. It is important that you use 
the same length in all fields, and send then via network order endian if 
necessary. 
![](../images/protocol.png)

	- Total message size: Must contain the messages length
	- Message type is defined as:
		- 0x02 - Request a key
		- 0x03 - Answer from server with key
	- Input field 1/2: numbers read from stdin

## Sample input
```
12
4
```

## Sample output
```
15192330574732399779
```
