from socket import socket,AF_INET, SOCK_STREAM, timeout, SOL_SOCKET, SO_REUSEADDR
import struct
import select
import sys
import random

packer = struct.Struct('1s I')

server_addr = (sys.argv[1], int(sys.argv[2]))
with socket(AF_INET, SOCK_STREAM) as server:
	server.bind(server_addr)
	server.listen(1)
	server.settimeout(1.0)
	server.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

	target = random.randint(1,100)
	end = False
	print('Target: ', target)

	inputs = [ server ]
	while True:
		readable, writable, exceptional = select.select(inputs, [], inputs, 1)

		for s in readable:
			if s is server:
				client, client_addr = s.accept()
				inputs.append(client)
			else:
				try:
					raw = s.recv(packer.size)
					guess = packer.unpack(raw)
					print("Guess: ", guess)

					operator, number = guess
					op = operator.decode()

					if end == True:
						res = packer.pack('V'.encode(), 0)
					else:
						if op == '=':
							res = packer.pack(('Y' if number == target else 'N').encode(), 0)
							if number == target:
								end = True
						elif op == '>':
							res = packer.pack(('I' if number > target else 'N').encode(), 0)
						elif op == '<':
							res = packer.pack(('I' if number < target else 'N').encode(), 0)
						else:
							raise ValueError()
					
					s.sendall(res)
				except struct.error:
					print('Client is disconnected')
					inputs.remove(s)
				except timeout:
					pass
				except ValueError:
					print('Bad operator')
