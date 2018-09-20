# Data Encryption Standard
This is a toy implementation of the Data Encryption Standard with two rounds, 8-bit blocks and a 10-bit key. To test it out, you will need C++14.

## Instructions
Clone the repo and run:
```./build.sh```

This will build two separate executables, one for each server. To run, run the following commands in two separate processes:
```./server1
./server2 <text file>
```

Server 1 will execute two unit tests, where it will encrypt and decrypt a single byte and check that it matches, then will encrypt and decrypt a string of bytes and check that it matches. Then it will wait to receive a single encrypted message over UDP. It will decrypt the message that it receives and print it out. 

Server 2 will open up the file that is passed as a command line argument and read the first line (up to 1024 bytes), encrypt it, and send it to Server 1. Since this is not an exercise in file reading, anything else in the file past the first line or first 1024 bytes will be ignored.

This is the output I get when I run it using the provided ```test.txt```:

From Server 1:
```
Running two unit tests...

Testing a single byte:
Plaintext: 164
Encrypted: 182
Decrypted: 164
Correct!


Testing a human-readable string:
Plaintext: This is a secret message.
Encrypted: Z)՘)g)&|&&))g&a
Decrypted: This is a secret message.
Correct!
Finished unit tests.


Received datagram from: 127.0.0.1
Received encrypted message: Z)՘)gu&u|+&&))g&a
Decrypting...

The decrypted message is: This is an encrypted message.
```

From Server 2:
```
Client wishes to send: This is an encrypted message.
Encrypting...
Sending encrypted result: Z)՘)gu&u|+&&))g&a
```

