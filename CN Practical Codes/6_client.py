import socket
import os
def start_client(server_ip='127.0.0.1', server_port=12345, filename='testfile.txt'):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((server_ip, server_port))
        
        # 1. Send greeting
        s.sendall(b'Hello')
        
        # Receive server reply
        data = s.recv(1024)
        print('Server says:', data.decode())
        
        # 2. Send file info (filename, filesize)
        filesize = os.path.getsize(filename)
        file_info = f"{filename},{filesize}"
        s.sendall(file_info.encode())

        # Wait for server OK
        ack = s.recv(1024)
        if ack != b'OK':
            print('Server did not acknowledge file info.')
            return
        # 3. Send file data
        with open(filename, 'rb') as f:
            while True:
                bytes_read = f.read(4096)
                if not bytes_read:
                    break
                s.sendall(bytes_read)
        
        print(f'File {filename} sent successfully.')

if __name__ == '__main__':
    start_client()
