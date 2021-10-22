from socket import socket,AF_INET, SOCK_STREAM, timeout, SOL_SOCKET, SO_REUSEADDR
import select
import time
import sys

def ct():
    return round(time.time())

#id|time|cslength|checksum
cache = list()

server_addr = (sys.argv[1], int(sys.argv[2]))
with socket(AF_INET, SOCK_STREAM) as server:
    server.bind(server_addr)
    server.listen(1)
    server.settimeout(1.0)
    server.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

    print(f'LISTENING | {server_addr[0]}:{server_addr[1]}')

    inputs = [ server ]
    while True:
        readable, writable, exceptional = select.select(inputs, [], inputs, 1)

        for s in readable:
            if s is server:
                client, client_addr = s.accept()
                inputs.append(client)
            else:
                try:
                    data = s.recv(256)
                    command = data.decode().split('|')

                    if command[0] == 'BE' :
                        expire = ct() + int(command[2])
                        rec = (command[1], expire, int(command[3]), command[4])
                        cache.append(rec)
                        s.sendall('OK'.encode())
                        print(f'IN | {command[1]} -> {rec}')
                    elif command[0] == 'KI':
                        res = '0|'
                        for record in cache:
                            if record[0] == command[1] and record[1] > ct():
                                res = f'{record[2]}|{record[3]}'
                                break
                        s.sendall(res.encode())
                        print(f'OUT | {command[1]} -> {res}')
                    else:
                        inputs.remove(s)
                except timeout:
                    pass
