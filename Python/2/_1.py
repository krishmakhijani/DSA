# Develop a simple Python program of TCP, client that can connect to the server and client can send a "Hello, Server!" message to the server.

import socket

def client_program():
    host = socket.gethostname()
    port = 5000

    client_socket = socket.socket()
    client_socket.connect((host, port))

    message = input(" -> ")
    while message.lower().strip() != 'bye':
        client_socket.send("Hello, Server!".encode())
        data = client_socket.recv(1024).decode()
        print("Received from server: " + data)
        message = input(" -> ")

    client_socket.close()

if __name__ == '__main__':
    client_program()
