from socket import socket,AF_INET, SOCK_DGRAM, timeout, SOL_SOCKET, SO_REUSEADDR
import struct
import select

server_addr = ('localhost', 10000)
unpacker = struct.Struct('I I 1s')  #int, int, char[1]

with socket(AF_INET, SOCK_DGRAM) as server:
	server.bind(server_addr)
	server.settimeout(1.0)

	while True:
		try:
			data, address = server.recvfrom(unpacker.size)
			unp_data = unpacker.unpack(data)
			print("Recived:",unp_data)

			x = eval(str(unp_data[0])+unp_data[2].decode()+str(unp_data[1]))

			server.sendto(str(x).encode(), address)
		except timeout:
			pass
