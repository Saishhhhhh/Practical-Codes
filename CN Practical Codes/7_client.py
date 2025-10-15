import socket
import os
# Server details
SERVER_IP = "127.0.0.1"   # Change to server machine IP
SERVER_PORT = 5001
BUFFER_SIZE = 4096

# Create UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Files to send
files = [
    "files_to_send/script.py",
    "files_to_send/notes.txt",
    "files_to_send/video.mkv"
]

for filepath in files:
    filename = os.path.basename(filepath)

    # Send filename first
    client_socket.sendto(filename.encode(), (SERVER_IP, SERVER_PORT))

    # Send file content
    with open(filepath, "rb") as f:
        while True:
            bytes_read = f.read(BUFFER_SIZE)
            if not bytes_read:
                break
            client_socket.sendto(bytes_read, (SERVER_IP, SERVER_PORT))

    # Send end-of-file marker
    client_socket.sendto(b"EOF", (SERVER_IP, SERVER_PORT))

    print(f"File {filename} sent successfully!\n")
