import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_addr = ('localhost', 10001)
sock.bind(server_addr)

while True:
    print("waiting...")
    data, address = sock.recvfrom(4096)
    print("recived: ", address)
    sent = sock.sendto(data, address)