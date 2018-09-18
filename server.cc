#include <iostream>

#include "des_cipher.h"
#include "udp_server.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "ERROR: Invalid argument(s)\nUSAGE: " << argv[0] 
              << "<host> <port>";
    return EXIT_FAILURE;
  }

  std::string host = argv[1];
  int port = atoi(argv[2]);

  UDP::Server server(host, port);
  std::string buffer;


  DES::Cipher cipher;

  // test a single byte
  uint16_t plain = 0xa4;
  std::cout << "Plaintext: " << plain << "\n";
  uint16_t encrypted = cipher.encrypt(plain);
  std::cout << "Encrypted: " << encrypted << "\n";
  uint16_t result = cipher.decrypt(encrypted);
  std::cout << "Decrypted: " << result << "\n";
  
  if (plain == result)
    std::cout << "Correct!\n";
  else
    std::cout << "Fail\n";

  // test a string
  std::string plaintext = "This is a secret message.";
  std::cout << "\n\nPlaintext: " << plaintext << "\n";
  std::string encrypted_string = "";
  for (char c : plaintext)
    encrypted_string += cipher.encrypt(c);

  std::cout << "Encrypted: " << encrypted_string << "\n";

  std::string decrypted_string = "";
  for (char c : encrypted_string)
    decrypted_string += cipher.decrypt(c);

  std::cout << "Decrypted: " << decrypted_string << "\n";


  if (plaintext == decrypted_string)
    std::cout << "Correct!\n";
  else
    std::cout << "Fail\n";


  // while (true) {
  //   server.receive(buffer);
  //   std::cout << "Received " << buffer << std::endl;
  // }


  return EXIT_SUCCESS;
}