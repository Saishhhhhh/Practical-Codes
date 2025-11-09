import socket

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Server address
host = '127.0.0.1'
port = 5001

# Send message to server
message = "Hello from UDP client!"
client_socket.sendto(message.encode(), (host, port))
print("✅ Sent:", message)

# Receive response from server
data, server_address = client_socket.recvfrom(1024)
print("📩 Server says:", data.decode())

# Close socket
client_socket.close()