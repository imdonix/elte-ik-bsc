from socket import socket, AF_INET, SOCK_DGRAM

server_addr = ('localhost', 10000)
client = socket(AF_INET, SOCK_DGRAM)

sent = client.sendto("hello".encode(), server_addr)

data, address = client.recvfrom(4096)

print("received: ", data.decode())

client.close()