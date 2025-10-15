import socket
def udp_client(host='127.0.0.1', port=65433):
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        message = "Hello UDP Server!"
        s.sendto(message.encode(), (host, port))
        print(f"Sent: {message}")

        data, server = s.recvfrom(1024)  # Wait for response
        print(f"Received from server: {data.decode()}")

if __name__ == "__main__":
    udp_client()
