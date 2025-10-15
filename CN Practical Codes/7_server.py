import socket
import os

# Server settings
SERVER_IP = "0.0.0.0"
SERVER_PORT = 5001
BUFFER_SIZE = 4096
SAVE_DIR = "received_files"

os.makedirs(SAVE_DIR, exist_ok=True)

# Create UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((SERVER_IP, SERVER_PORT))

print(f"UDP Server listening on {SERVER_IP}:{SERVER_PORT}...")

while True:
    # Receive file name
    filename, client_addr = server_socket.recvfrom(BUFFER_SIZE)
    filename = filename.decode()
    print(f"Receiving file: {filename} from {client_addr}")

    # Open file for writing
    with open(os.path.join(SAVE_DIR, filename), "wb") as f:
        while True:
            data, addr = server_socket.recvfrom(BUFFER_SIZE)
            if data == b"EOF":
                break
            f.write(data)

    print(f"File {filename} received successfully!\n")
