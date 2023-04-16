import socket

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432  # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #s.sendall(b"Hello, world")
    s.connect((HOST, PORT))
    while True:
        print('\nIngrese el dato a enviar:')
        dato = str(input())
        if dato == 'exit':
            break
        else:
            s.send(bytes(dato.encode('utf-8')))
        #data = s.recv(1024)

#print(f"Received {data!r}")
print('Conexion terminada')