# Socketzz

Applications in 2014 often requeres to communicate with either servers, or 
other clients. An importent aspect of this communication is a well defined
protocol so the messages passed are understood correctly by any parties.

In this task you must be able to send two inputs to our server via our defined
protocol. The server will reply with a key that can vary up to the total message
size. (2^8 bytes).

In this task we have prepaired a server running on port 3950 at <this server>.
you can use this when you are testing, but when you deliver you must make
sure that localhost or 127.0.0.1 is the hostname or address.

## Input
You can freely choose input in input1 and input2. But please hardcode it
in your code so our jugingsystem will be able to test your solution.

## Output
Your program should output the key you got from the server.

## Constraints

Our server is using the protocol described here. It is important that you use 
the same length of all fields, and send then via network order endian if 
neasesary. 
![](../images/protocol.png)

## Sample input
```
12
4
```

## Sample output
```
15192330574732399779
```
