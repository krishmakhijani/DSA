import socket

def calculate_sum(numbers):
    return sum(numbers)

host = 'localhost'
port = 12345

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind((host, port))


server_socket.listen(5)
print(f"Server listening on {host}:{port}")

while True:
    client_socket(),
