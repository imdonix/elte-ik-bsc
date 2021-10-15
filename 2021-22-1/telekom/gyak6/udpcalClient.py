from socket import socket, AF_INET, SOCK_DGRAM
import struct

server_addr = ('localhost', 10000)
client = socket(AF_INET, SOCK_DGRAM)

packer = struct.Struct('I I 1s')
data = (int(2),int(5),'+'.encode())

client.sendto(packer.pack(*data), server_addr)

data, address = client.recvfrom(16)
print("received: ", data.decode())

client.close()
