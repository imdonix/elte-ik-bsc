from socket import socket, AF_INET, SOCK_DGRAM, SOCK_STREAM, timeout

sock = socket(AF_INET, SOCK_STREAM)
server_addr = ('localhost', 10000)
sock.bind(server_addr)
sock.settimeout(1.0) # needed on windows to catch KeyboardInterrupt
sock.listen(1)


udp_adr = ('localhost', 10001)
client = socket(AF_INET, SOCK_DGRAM)

while True:
    try: 
        print("waiting...")
        client_socket, client_addr = sock.accept()
        print("connected: ", client_addr)
        data = client_socket.recv(16)
        print("received: ", data.decode())
        if data:
            sent = client.sendto(data, udp_adr)
            data, address = client.recvfrom(4096)
            client_socket.sendall(data)
        else:
            print("disconnected")
        client_socket.close()
    except timeout:
        pass
    except KeyboardInterrupt:
        sock.close()
        break

client.close()