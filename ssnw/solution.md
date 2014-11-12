# Socketzz
Connect to the server and send the message inputs. The important part is that
input1 and input2 are in the right places in the message we are sending. 

- input1: starts on byte index 2 and takes up 1 byte
- input2: starts on byte index 3 and takes up 1 byte

When receiving the message from the server, just get the hashed key that the
server made from input1 and input2. It should reside after the four 1-byte
attributes in the protocol. So just skip the first 4 bytes, and get the rest of
the number. Be sure to get *exactly* the right amount of bytes from the hash to 
not get a wrong diff in the hashkey. A nifty trick here in python is to just 
subtract the padding (length, type, input1, input2) which is 4 bytes long from 
the total message length. This does not work in Java though. Here you have to 
get the length attribute from the message in order to copy just the right 
amount of bytes out from the message. Else you will end up having lots of 
garbage bytes at the end of the hashed key and you will receive a wrong anser.

Just print out the hashed key from the server and you should have completed the
exercise.
