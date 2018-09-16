import socket
from sys import argv



class UdpServer:
    def __init__(self, host, port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.host = host
        self.port = port
        self.type = type
        self.sock.bind((self.host, self.port))

    def recv(self, num_bytes=1024):
        data, address = self.sock.recvfrom(num_bytes)
        return data.decode(), address

    def send(self, data, address):
        sent = self.sock.sendto(data.encode(), address)
        return sent      







if __name__ == "__main__":
    # accept command line option
    if len(argv) == 3:
        _, host, port = argv
        port = int(port)
    else:
        host = "127.0.0.1"
        port = 5000

    server = UdpServer("127.0.0.1", 5000)

    while True:
        data, address = server.recv(num_bytes=4096)
        print("Received {0} bytes from {1}".format(len(data), address))

        if data:
            sent = server.send(data, address)