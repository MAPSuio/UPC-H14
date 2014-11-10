from struct import *
from socket import *
from sys import argv, exit

HOST = 'localhost'
PORT = 3950

sock = socket(AF_INET, SOCK_DGRAM)

# Build the message
input1      = raw_input('input1: ')
input2      = raw_input('input2: ')
length      = 0x04
packet_type = 0x02

# Padded single byte because we don't need to use the length factor when sending
msg = pack('BBBB', length, packet_type, int(input1), int(input2))

# Send the message
sock.sendto(msg, (HOST, PORT)) # TEMP

# Receive the message
msg = sock.recvfrom(256) # TEMP

# Decode the message and print it out
data = list(msg)
print data[0]

# Close the socket
sock.close()
