import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Server address
host = '127.0.0.1'
port = 5000

# Connect to server
client_socket.connect((host, port))

# Send message to server
client_socket.send("Hello from client!".encode())

# Receive response
response = client_socket.recv(1024).decode()
print("📩 Server says:", response)

# Close socket
client_socket.close()