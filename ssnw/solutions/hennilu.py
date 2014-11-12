# @EXPECTED_RESULTS@: CORRECT
from struct import *
from socket import *
from sys import stdin

#HOST    = 'localhost'
HOST    = '178.62.248.162'
PORT    = 3950
PADDING = 4 # Padding represents the bytes used for input1/2, length and packet_type

sock = socket(AF_INET, SOCK_DGRAM)

# Build the message
input1, input2 = map(int, stdin.read().split())
length      = 0x04
packet_type = 0x02

# Pack the message C-style and according to the protocol
msg = pack('BBBB', length, packet_type, input1, input2)

# Send the message
sock.sendto(msg, (HOST, PORT)) # TEMP

# Receive the message
msg = sock.recvfrom(256) # TEMP

# Decode the message and print it out
data = list(msg)
data_length = len(data[0]) - PADDING
data_as_string = str(data[0])
hash_key = data_as_string[PADDING:]
print hash_key

# Close the socket
sock.close()
