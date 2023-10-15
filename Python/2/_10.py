# Write a Python program to receive UDP packets and display their content. Simulate sending UDP packets from a separate client program.

import socket

host = 'localhost'
port = 54321

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_socket.bind((host, port))

print(f"Server listening on {host}:{port}")

while True:

            data, client_address = server_socket.recvfrom(1024)
            print(f"Received from {client_address}: {data.decode('utf-8')}")
            response = "UDP Server Response"
            server_socket.sendto(response.encode('utf-8'), client_address)

            