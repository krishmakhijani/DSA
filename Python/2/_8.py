import socket

# Client configuration
host = 'localhost'
port = 12345

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client_socket.connect((host, port))

while True:
    # Input a message to send to the server
    message = input("Enter a message (or 'exit' to quit): ")

    if message.lower() == 'exit':
        break

    # Send the message to the server
    client_socket.send(message.encode('utf-8'))

    # Receive the echoed response from the server
    response = client_socket.recv(1024)
    print(f"Received from the server: {response.decode('utf-8')}")

# Close the client socket
client_socket.close()
