import UdpServer as us
from sys import argv

test = True
key = 0b1011010111

S0 =   [[1,0,3,2], 
        [3,2,1,0],
        [0,2,1,3],
        [3,1,3,2]]

S1 =   [[0,1,2,3],
        [2,0,1,3],
        [3,0,1,0],
        [2,1,0,3]]


def test():
    print(S0[3][2])
    print(S0[1][0])
    print(S1[3][2])
    print(S1[1][0])
    print("Key: ", key)


# receives a single character (1 byte) and encrypts it using a key
def DES(char):
    pass


if __name__ == "__main__":
   
    if test:
        test()
    else:
        # accept command line option
        if len(argv) == 4:
            _, host, port, filename = argv
            port = int(port)
        else:
            host = "127.0.0.1"
            port = 5000

        # open and read data in file
        file = open(filename, 'r')
        data = file.read()
        print(data)

        # encrypt the data, one byte at a time
        encrypted = ""
        for c in data:
            encrypted.append(DES(data))
        print(data)


        # send the encrypted data to the receiver
        server = us.UdpServer(host, port)
        address = ("127.0.0.1", 5001)
        sent = server.send(data, address)

        data, address = server.recv()
        print("Received {0} bytes from {1}".format(len(data), address))


