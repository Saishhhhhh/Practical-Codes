import socket

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    host = '127.0.0.1'
    port = 7000

    client_socket.connect((host, port))
    print("✅ Connected to server")

    # -------------------------
    # Part 1: Hello Message
    # -------------------------
    message = "Hello Server!"
    client_socket.send(message.encode())
    print("✅ Sent:", message)

    reply = client_socket.recv(1024).decode()
    print("📩 Server replied:", reply)

    # -------------------------
    # Part 2: File Transfer
    # -------------------------
    print("📄 Receiving file...")

    data = client_socket.recv(4096)

    if data.decode(errors="ignore") == "File not found!":
        print("❌ Server: File not found!")
    else:
        with open("received_testfile.txt", "wb") as f:
            f.write(data)
        print("✅ File received and saved as received_testfile.txt")

    client_socket.close()
    print("✅ Connection closed")

if __name__ == "__main__":
    main()
