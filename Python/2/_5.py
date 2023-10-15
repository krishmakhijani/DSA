# Write a Python program to create a UDP server that listens on port 54321. Ensure the
# # server can receive UDP packets from clients.

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

        