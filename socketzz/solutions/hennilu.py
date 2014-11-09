from struct import *
from socket import *
from sys import argv, exit

HOST = 'localhost'
PORT = 3950
sock = socket(AF_INET, SOCK_DGRAM)

# TODO: 1. Build the message
input1      = raw_input('input1: ')
input2      = raw_input('input2: ')
packet_type = 0x02

# Save the characters
char1 = chr(input1) 
char2 = chr(input2)

# Padded single byte because we don't need to use the length factor when sending
msg = pack('xBBB', packet_type, input1, input2)
print "Packed message: {0}".format(msg)

# TODO: 2. Send the message
sock.sendto(msg, HOST, PORT) # TEMP

# TODO: 3. Receive the message
msg = sock.recvfrom(256) # TEMP

# TODO: 4. Decode the message and print it out
data = unpack('BBBBs', msg)
print "Unpacked message: {0}".format(data)
hash = ''

if len(data) == 5:
    print "{0}".format(data[4] # TEMP

else:
    print "Something has gone wrong!?!?"
