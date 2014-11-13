# @EXPECTED_RESULTS@: CORRECT

from sys import stdin
import socket, struct

HOST = '10.133.234.216'
PORT = 3950

in1, in2 = map(int, stdin.next().split())

# assemble payload
size = 4*8
msg_type = 0x02

payload = struct.pack('BBBB', size, msg_type, in1, in2)

# send key request
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto(payload, (HOST, PORT))

# receive response
response = sock.recv(2**8)

# parse response
HEAD_SIZE = 4
data = struct.unpack('BBBB%ds' % (len(response) - HEAD_SIZE), response)

print data[-1]
