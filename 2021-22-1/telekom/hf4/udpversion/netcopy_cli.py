from socket import socket, AF_INET, SOCK_DGRAM, SOCK_STREAM
from hashlib import md5
import sys

expire = 60
pck_size = 16
copy_adr = (sys.argv[1], int(sys.argv[2]))
check_adr = (sys.argv[3], int(sys.argv[4]))
file = (sys.argv[5], sys.argv[6])

hash = md5()
with socket(AF_INET, SOCK_DGRAM) as client:
    with open(file[1], "rb") as f:
        try:
            l = f.read(pck_size)
            while l:
                client.sendto('R'.encode(), copy_adr)
                client.sendto(l, copy_adr)
                hash.update(l)
                l = f.read(pck_size)
            client.sendto('E'.encode(), copy_adr)
        except:
            pass

data = hash.hexdigest()
print(f'SENT | {data}')

with socket(AF_INET, SOCK_STREAM) as client:
    client.connect(check_adr)
    client.sendall(f'BE|{file[0]}|{expire}|{len(data)}|{data}'.encode())
    res = client.recv(256).decode()
    if res == 'OK':
        print(f'CHECKSUM | submitted')
    else:
        print(f'CHECKSUM | error')