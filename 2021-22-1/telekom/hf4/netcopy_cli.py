from socket import socket, AF_INET, SOCK_DGRAM, SOCK_STREAM
from hashlib import md5
import sys

expire = 60
pck_size = 16
copy_adr = (sys.argv[1], int(sys.argv[2]))
check_adr = (sys.argv[3], int(sys.argv[4]))
file = (sys.argv[5], sys.argv[6])

hash = md5()
with socket(AF_INET, SOCK_STREAM) as client:
    client.connect(copy_adr)

    with open(file[1], "rb") as f:
        l = f.read(pck_size)
        while l:
            client.sendall(l)
            hash.update(l)
            l = f.read(pck_size)

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