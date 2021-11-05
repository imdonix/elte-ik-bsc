from socket import socket, AF_INET, SOCK_STREAM, SOCK_DGRAM
import struct

packer = struct.Struct('32s I I')
server_addr = ('localhost', 1000)


with socket(AF_INET, SOCK_STREAM) as client:
    client.connect(server_addr)

    data = ("HUZODAS".encode(), 0, 0)

    client.sendall(packer.pack(*data))

    data = client.recv(packer.size)
    res = packer.unpack(data)
    med = res[0].decode().replace('\x00','')
    print("Gyógyszer: ", med, " ennyit: ", res[1])

    if med != 'NINCS':
        patika_port = res[2]
        with socket(AF_INET, SOCK_DGRAM) as patika:

            server_addr = ('localhost', patika_port)

            print("Kertem a patikaba gyogyszert:")

            sent = patika.sendto(med.encode(), server_addr)

            data, address = patika.recvfrom(4)

            print("Patika valasza: ", data.decode())