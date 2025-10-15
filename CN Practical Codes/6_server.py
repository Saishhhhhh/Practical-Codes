import socket
def start_server(host='0.0.0.0', port=12345):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((host, port))
        s.listen(1)
        print(f'Server listening on {host}:{port}')
        
        conn, addr = s.accept()
        with conn:
            print(f'Connected by {addr}')
            
            # 1. Receive greeting
            data = conn.recv(1024).decode()
            print(f'Received from client: {data}')
            
            # Reply "Hello"
            if data.strip().lower() == 'hello':
                conn.sendall(b'Hello')
            else:
                conn.sendall(b'Unknown greeting')
                return
            
            # 2. Receive file info (filename and size)
            file_info = conn.recv(1024).decode()
            filename, filesize = file_info.split(',')
            filesize = int(filesize)
            print(f'Receiving file: {filename} ({filesize} bytes)')
            
            # Acknowledge file info receipt
            conn.sendall(b'OK')
            # 3. Receive the file data
            with open('received_' + filename, 'wb') as f:
                received = 0
                while received < filesize:
                    bytes_read = conn.recv(4096)
                    if not bytes_read:
                        break
                    f.write(bytes_read)
                    received += len(bytes_read)
            
            print(f'File received successfully as received_{filename}')

if __name__ == '__main__':
    start_server()
