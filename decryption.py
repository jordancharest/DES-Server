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

    address = ("127.0.0.1", 5000)
    data = "This is the message being sent!"
    sent = server.send(data, address)
    print("Returned data to sender")    

    data, address = server.recv()
    print("Received {0} bytes from {1}".format(len(data), address))

