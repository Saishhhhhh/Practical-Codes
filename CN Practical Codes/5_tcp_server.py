import socket

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# AF_INET → IPv4
# SOCK_STREAM → TCP (reliable, connection-oriented)

# Bind server to host and port
host = '127.0.0.1'   # localhost
port = 5000
server_socket.bind((host, port))

# Listen for incoming connections
server_socket.listen(1) # 1 is backlog (how many clients can wait in queue)
print("✅ Server is listening on port", port)

# Accept a connection
client_socket, client_address = server_socket.accept()
print("✅ Connection received from:", client_address)

# Receive message from client
message = client_socket.recv(1024).decode()  #receive up to 1024 bytes
print("📩 Client says:", message)

# Send response back to client
client_socket.send("Hello from server!".encode())

# Close the connection
client_socket.close()
server_socket.close()
print("✅ Connection closed")
