import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = '127.0.0.1'
port = 5001

server_socket.bind((host, port))
print(f"✅ UDP Server is listening on {host}:{port}")

# Receive only one message
data, client_address = server_socket.recvfrom(1024)
print(f"📩 Client says: {data.decode()} from {client_address}")

reply = "Hello from UDP server!"
server_socket.sendto(reply.encode(), client_address)

server_socket.close()
print("✅ Server closed.")