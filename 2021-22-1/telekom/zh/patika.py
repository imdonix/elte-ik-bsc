import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_addr = ('localhost', 1001)
sock.bind(server_addr)

while True:
    print("várakozok betegre...")
    data, address = sock.recvfrom(256)
    print("beteg érkezett: ", address, " ilyen gyószert kér: ", data.decode() )

    sock.sendto("KESZ".encode(), address)