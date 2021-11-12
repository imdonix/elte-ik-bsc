from socket import socket, AF_INET, SOCK_STREAM
import struct
import sys

packer = struct.Struct('8s I')
server_addr = ('localhost', 999)

offers = sys.argv[1:]

with socket(AF_INET, SOCK_STREAM) as client:
    client.connect(server_addr)

    for offer in offers:
        data = ("BID".encode(), int(offer))

        client.sendall(packer.pack(*data))

        data = client.recv(packer.size)
        resoult = packer.unpack(data)
        print("Uj ajanlat elküldve: ", offer, " a licit valasza: ", resoult[0].decode().replace('\x00','') )

