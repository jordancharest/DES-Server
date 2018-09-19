#include <iostream>

#include "des_cipher.h"
#include "udp_server.h"

int main(int argc, char** argv) {
  // if (argc != 3) {
  //   std::cerr << "ERROR: Invalid argument(s)\nUSAGE: " << argv[0] 
  //             << "<host> <port>";
  //   return EXIT_FAILURE;
  // }

  std::string host = "127.0.0.1";
  int port = 5000;

  UDP::Server server(host, port);
  DES::Cipher cipher;

  // UNIT TESTS ---------------------------------------------------------------
  std::cout << "Running two unit tests...\n\n";
  
  // test a single byte
  std::cout << "Testing a single byte:\n";
  uint16_t plain = 0xa4;
  uint16_t encrypted = cipher.encrypt(plain);
  uint16_t result = cipher.decrypt(encrypted);
  std::cout << "Plaintext: " << plain << "\n";
  std::cout << "Encrypted: " << encrypted << "\n";
  std::cout << "Decrypted: " << result << "\n";
  
  if (plain == result)
    std::cout << "Correct!\n";
  else
    std::cout << "Fail\n";

  // test a string
  std::cout << "Testing a human-readable string:\n";
  std::string plaintext = "This is a secret message.";

  std::string encrypted_string = "";
  for (char c : plaintext)
    encrypted_string += cipher.encrypt(c);

  std::string decrypted_string = "";
  for (char c : encrypted_string)
    decrypted_string += cipher.decrypt(c);

  std::cout << "\n\nPlaintext: " << plaintext << "\n";
  std::cout << "Encrypted: " << encrypted_string << "\n";
  std::cout << "Decrypted: " << decrypted_string << "\n";


  if (plaintext == decrypted_string)
    std::cout << "Correct!\n";
  else
    std::cout << "Fail\n";
  std::cout << "Finished unit tests.\n";
  // UNIT TESTS ---------------------------------------------------------------


  // run the server
  std::string buffer;
  server.receive(buffer);
  std::cout << "Received encrypted message: " << buffer << "\nDecrypting...\n";

  std::string decrypted = "";
  for (char c : buffer)
    decrypted += cipher.decrypt(c);

  std::cout << "\nThe decrypted message is: " << decrypted << std::endl;

  return EXIT_SUCCESS;
}