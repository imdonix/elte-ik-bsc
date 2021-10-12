from socket import socket, AF_INET, SOCK_STREAM
import struct
import sys
import select

server_addr = ('139.162.166.76', 10000)

with socket(AF_INET, SOCK_STREAM) as client:
    client.connect(server_addr)

    name = input("name")
    inputs = [client, sys.stdin]

    while True:
        readable, _, _ = select.select(inputs, [], [])
        for s in readable:
            if s is client:
                print(s.recv(1024).decode())
            else:
                data = sys.stdin.readlines()
                if data == "exit":
                    client.close()
                    exit()
                client.send(f'{name}: {data.strip()}'.encode())