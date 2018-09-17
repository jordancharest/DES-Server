import UdpServer as us
from sys import argv



if  __name__ == "__main__":
    if len(argv) == 3:
        _, host, port = argv
        port = int(port)
    else:
        host = "127.0.0.1"
        port = 5001


    server = us.UdpServer(host, port)

    while True:
        data, address = server.recv()
        print("Received {0} bytes from {1}. Printing:\n{2}".format(len(data), address, data))

        if data:
            sent = server.send(data.upper(), address)
            print("Returned data to sender")