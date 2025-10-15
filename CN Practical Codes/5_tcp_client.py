import socket
def tcp_client(host='127.0.0.1', port=65432):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        message = "Hello TCP Server!"
        print(f"Sending: {message}")
        s.sendall(message.encode())
        data = s.recv(1024)
        print('Received from server:', data.decode())

if __name__ == '__main__':
    tcp_client()
