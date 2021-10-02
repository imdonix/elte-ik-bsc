from socket import socket, AF_INET, SOCK_STREAM
import struct
import sys

packer = struct.Struct('1s I')

# < > =
# V Y V I N

server_addr = (sys.argv[1], int(sys.argv[2]))
client = socket(AF_INET, SOCK_STREAM)
client.connect(server_addr)

client.sendall(packer.pack('='.encode(), 50))

res = packer.unpack(client.recv(packer.size))
print(res)

client.close()
