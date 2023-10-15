import socket
import time
host = 'localhost'
port = 54321
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
start = time.time()
client_socket.connect((host, port))
end = time.time()
print(f"Time elapsed: {end - start} seconds")
client_socket.close()
