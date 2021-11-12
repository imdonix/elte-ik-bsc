import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_addr = ('localhost', 998)

sock.bind(server_addr)

while True:
    data, address = sock.recvfrom(256)
    print("Új ajánlat érkezett:", data.decode())