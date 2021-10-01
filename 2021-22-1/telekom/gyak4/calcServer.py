from socket import socket,AF_INET, SOCK_STREAM, timeout, SOL_SOCKET, SO_REUSEADDR
import struct
import select

server_addr = ('localhost', 10000)
unpacker = struct.Struct('I I 1s')  #int, int, char[1]

with socket(AF_INET, SOCK_STREAM) as server:
	server.bind(server_addr)
	server.listen(1)
	server.settimeout(1.0)
	server.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
	

	inputs = [ server ]
	outputs = [ ]
	while True:

		readable, writable, exceptional = select.select(inputs, outputs, inputs, 1)

		for s in readable:
			if s is server:
				client, client_addr = s.accept()
				inputs.append(client)
				print('szia')
			else:
				print('ok')
				try:
					data = s.recv(unpacker.size)
					print("Received:",data)

					unp_data = unpacker.unpack(data)
					print("Unpacked:",unp_data)
					
					x = eval(str(unp_data[0])+unp_data[2].decode()+str(unp_data[1]))
					
					s.sendall(str(x).encode())
				except timeout:
					pass
