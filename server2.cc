#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "udp_server.h"
#include "des_cipher.h"



int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "ERROR: Invalid argument(s)\nUSAGE: " << argv[0] 
              << "<text file>";
    return EXIT_FAILURE;
  }

  // open a file and read the first line
  std::ifstream in(argv[1]);
  if (!in.good()){
    std::cerr << "ERROR: Invalid input file format\n";
    return EXIT_FAILURE;
  }

  // get a line from the text file
  std::string msg;
  std::getline(in, msg);
  std::cout << "Client wishes to send: " << msg
            << "\nEncrypting...\n";

  DES::Cipher cipher;
  std::string encrypted = "";
  for (char c : msg)
    encrypted += cipher.encrypt(c);

  std::cout << "Sending encrypted result: " << encrypted << "\n";

  // start server
  std::string host = "127.0.0.1";
  int port = 5001;
  UDP::Server server(host, port);

  // send encrypted message
  server.send("127.0.0.1", 5000, encrypted);

  return EXIT_SUCCESS;
}