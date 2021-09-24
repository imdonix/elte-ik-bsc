import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_addr = ('localhost', 10000)
sock.bind(server_addr)
sock.settimeout(1.0) # needed on windows to catch KeyboardInterrupt
sock.listen(1)

while True:
    try: 
        print("waiting...")
        client_socket, client_addr = sock.accept()
        print("connected: ", client_addr)
        data = client_socket.recv(16)
        print("received: ", data.decode())
        if data:
            client_socket.send("Hello Client!".encode())
        else:
            print("disconnected")
        client_socket.close()
    except socket.timeout:
        pass
    except KeyboardInterrupt:
        sock.close()
        break

