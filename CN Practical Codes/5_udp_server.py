import socket
def udp_server(host='127.0.0.1', port=65433):
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.bind((host, port))
        print(f"UDP server listening on {host}:{port}...")
        while True:
            data, addr = s.recvfrom(1024)  # Receive data from client
            print(f"Received from {addr}: {data.decode()}")
            s.sendto(data, addr)  # Echo back to client

if __name__ == "__main__":
    udp_server()
