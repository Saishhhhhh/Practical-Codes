import socket
import os

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    host = '127.0.0.1'
    port = 7000

    server_socket.bind((host, port))
    server_socket.listen(1)
    # 1 is backlog (how many clients can wait in queue)
    
    print(f"✅ Server listening on {host}:{port}")

    client_socket, client_address = server_socket.accept()
    print("✅ Client connected:", client_address)

    # -------------------------
    # Part 1: Hello Message
    # -------------------------
    hello_msg = client_socket.recv(1024).decode()
    print("📩 Client says:", hello_msg)

    reply = "Hello from Server!"
    client_socket.send(reply.encode())
    print("✅ Hello message sent")

    # -------------------------
    # Part 2: File Transfer
    # -------------------------
    filename = "testfile.txt"
    print(f"📄 Preparing to send: {filename}")

    if os.path.exists(filename):
        with open(filename, "rb") as f:
            data = f.read()
            client_socket.sendall(data)
            print("✅ File sent successfully")
    else:
        client_socket.send("File not found!".encode())
        print("❌ File not found")

    client_socket.close()
    server_socket.close()
    print("✅ Server closed")

if __name__ == "__main__":
    main()
