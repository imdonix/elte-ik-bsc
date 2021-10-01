from socket import socket, AF_INET, SOCK_STREAM
import struct

server_addr = ('localhost', 10000)
client = socket(AF_INET, SOCK_STREAM)
client.connect(server_addr)

packer = struct.Struct('I I 1s')
data = (int(2),int(5),'+'.encode())

client.sendall(packer.pack(*data))

data = client.recv(16)
print("received: ", data.decode())

client.close()
