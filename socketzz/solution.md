# Socketzz
Connect to the server and send the message inputs. The important part is that
input1 and input2 are in the right places in the message we are sending. 

- input1: starts on byte index 2 and takes up 1 byte
- input2: starts on byte index 3 and takes up 1 byte

When receiving the message from the server, just get the hashed key that the
server made from input1 and input2. It should reside after the four 1-byte
attributes in the protocol. So just skip the first 4 bytes, and get the rest of
the number. Overflow numbers may occur if a standard int is used in C or Java.
This is because the number from the server is of type *unsigned long*.

There is a bias against python solutions in this exercise, because of pythons 
interpretation of the message received from the server. Because python will
receive a tuple containing *(message, address)*, and pythons print function will
ignore the first 4 bytes of information related to length, type and inputs, and 
just print the hash straight out.

Just print out the hashed key from the server and you should have completed the
exercise.
