from random import randint, random
from socket import socket, AF_INET, SOCK_STREAM
from time import sleep
import struct
import sys

packer = struct.Struct('1s I')

# < > =
# V Y V I N

server_addr = (sys.argv[1], int(sys.argv[2]))

range = 100
l = 0
r = range
last = 'N'

with socket(AF_INET, SOCK_STREAM) as client:
    client.connect(server_addr)

    while last == 'N' or last == 'I':
        mid = l + (r - l) // 2

        print('Check: ', mid, ' (' , l , '|' , r , ')')

        sleep(randint(0,5))
        client.sendall(packer.pack('='.encode(), int(mid)))   
        res = packer.unpack(client.recv(packer.size))
        last = res[0].decode()

        # Check the number
        if last == 'Y':
            print('The number was: ', mid)
            break
    
        if last == 'V':
            print('The number was found by another client')
        
        sleep(randint(0,5))
        client.sendall(packer.pack('>'.encode(), int(mid)))   
        res = packer.unpack(client.recv(packer.size))
        last = res[0].decode()


        # Next 
        if last == 'N':
            r = mid - 1
        else:
            l = mid + 1
