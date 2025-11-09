import socket
import os
import time

SERVER_IP = "127.0.0.1"
SERVER_PORT = 5001
BUFFER_SIZE = 4096

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

files = [
    "files_to_send/script.py",
    "files_to_send/notes.txt",
    "files_to_send/video.mkv"
]

for filepath in files:
    filename = os.path.basename(filepath)

    # Send filename
    client_socket.sendto(filename.encode(), (SERVER_IP, SERVER_PORT))

    # Wait for ACK before sending file data
    ack, _ = client_socket.recvfrom(BUFFER_SIZE)
    if ack != b"OK":
        print("❌ Server did not respond")
        continue

    # Send file in chunks
    with open(filepath, "rb") as f:
        while True:
            chunk = f.read(BUFFER_SIZE)
            if not chunk:
                break
            client_socket.sendto(chunk, (SERVER_IP, SERVER_PORT))

    # Send termination flag
    client_socket.sendto(b"EOF", (SERVER_IP, SERVER_PORT))

    print(f"✅ File sent: {filename}\n")

    # Small delay between files
    time.sleep(0.1)

client_socket.close()
