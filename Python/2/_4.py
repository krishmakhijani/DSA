import socket
import random
host = 'localhost'
port = 12345
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((host, port))

print(f"Server listening on {host}:{port}")

while True:

    data, client_address = server_socket.recvfrom(1024)
    random_number = int(data.decode('utf-8'))
    print(f"Received from {client_address}: {random_number}")
    result = "Even" if random_number % 2 == 0 else "Odd"
    server_socket.sendto(result.encode('utf-8'), client_address)
    random_number = random.randint(1, 100)
    client_socket.sendto(str(random_number).encode('utf-8'), (host, port))
    result, server_address = client_socket.recvfrom(1024)
    print(f"Received from {server_address}: The number is {result.decode('utf-8')}.")
    client_socket.close()
