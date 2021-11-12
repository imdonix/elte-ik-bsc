import builtins
from socket import socket,AF_INET, SOCK_STREAM, timeout, SOL_SOCKET, SO_REUSEADDR
import struct
import select
import sys
import random

packer = struct.Struct('32s I I')
server_addr = ('localhost', 1000)
shop_port = 1001

build = sys.argv[1:]

cure = {}
for i in range(len(build) // 2):
	cure[build[i*2]] = build[i*2+1]

print(cure)
with socket(AF_INET, SOCK_STREAM) as server:
    server.bind(server_addr)
    server.listen(1)
    server.settimeout(1.0)
    server.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)


    inputs = [ server ]
    while True:

        readable, writable, exceptional = select.select(inputs, [], inputs, 1)

        for s in readable:
            if s is server:
                client, client_addr = s.accept()
                inputs.append(client)
                print('Beteg érkezett')
            else:
                try:
                    data = s.recv(packer.size)
                    req = packer.unpack(data)
					
                    ill = req[0].decode().replace('\x00','')
                    print("Beteg tünetei:", ill)
                    res = ('NINCS'.encode(), 0, shop_port)
                    if ill in cure:
                        res = (cure[ill].encode(), random.randint(1,3), shop_port)
					
                    print('Betegségre gyógyszer:', res)
                    s.sendall(packer.pack(*res))
                except timeout:
                    pass
                except struct.error:
                    inputs.remove(s)

