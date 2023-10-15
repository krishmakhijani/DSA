# Develop a simple Python program that sends a small text file from a TCP client to a TCP server. Confirm that the file is received and saved correctly.

import socket

host = 'localhost'
port = 12345

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client_socket.connect((host, port))

with open('test.txt', 'r') as f:

    for line in f:
        client_socket.send(line.encode('utf-8'))
        response = client_socket.recv(1024)
        print(f"Received from the server: {response.decode('utf-8')}")
        if not response:
            break

client_socket.close()

