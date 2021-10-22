from socket import socket, AF_INET, SOCK_STREAM

server_addr = ('localhost', 10000)
client = socket(AF_INET, SOCK_STREAM)
client.connect(server_addr)

client.sendall("Hello Server!".encode())
data = client.recv(16)
print("received: ", data.decode())

client.close()
