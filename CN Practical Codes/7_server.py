import socket
import os

SERVER_IP = "127.0.0.1"
SERVER_PORT = 5001


os.makedirs("received_files", exist_ok=True)

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((SERVER_IP, SERVER_PORT))

print(f"✅ UDP Server listening on {SERVER_IP}:{SERVER_PORT}...")

while True:
    # Receive filename
    filename, client_addr = server_socket.recvfrom(4096)
    filename = filename.decode()
    print(f"📩 Receiving: {filename}")

    # Send ACK to start data transmission
    server_socket.sendto(b"OK", client_addr)

    # Create file to store data
    file_path = os.path.join("received_files", filename)

    with open(file_path, "wb") as f:
        while True:
            data, addr = server_socket.recvfrom(4096)
            if data == b"EOF":
                break
            f.write(data)

    print(f"✅ File saved: {file_path}\n")
