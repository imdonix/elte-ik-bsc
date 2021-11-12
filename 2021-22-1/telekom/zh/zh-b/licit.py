from socket import socket,AF_INET, SOCK_STREAM, SOCK_DGRAM, timeout, SOL_SOCKET, SO_REUSEADDR
import struct
import select

packer = struct.Struct('8s I')
server_addr = ('localhost', 999)
log_addr = ('localhost', 998)

price = 0

with socket(AF_INET, SOCK_STREAM) as server:
    with socket(AF_INET, SOCK_DGRAM) as log:
        server.bind(server_addr)
        server.listen(1)
        server.settimeout(2)
        server.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

        inputs = [ server ]
        while True:
            readable, writable, exceptional = select.select(inputs, [], inputs, 1)

            for s in readable:
                if s is server:
                    print('Új licitáló')
                    client, client_addr = s.accept()
                    inputs.append(client)
                else:
                    try:
                        data = s.recv(packer.size)
                        request = packer.unpack(data)
                        

                        newprice = request[1]
                        print("A licitáló ajánlata: ", newprice)

                        resoult = ('LOW'.encode(), price)
                        if newprice > price:
                            price = newprice
                            resoult = ('OK'.encode(), price)
                            log.sendto(f"{price}".encode(), log_addr)
                        
                        print('Az ár a licit megtétele után: ', price)
                        s.sendall(packer.pack(*resoult))
                    except timeout:
                        pass
                    except struct.error:
                        inputs.remove(s)

