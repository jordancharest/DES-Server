#include <iostream>

#include "udp_server.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "ERROR: Invalid argument(s)\nUSAGE: " << argv[0] 
              << "<host> <port>";
    return EXIT_FAILURE;
  }

  std::string host = argv[1];
  int port = atoi(argv[2]);
  std::cout << "Sanity check" << std::endl;

  UDP::Server server(host, port);

  std::cout << "server is built" << std::endl;


  std::string buffer;

  std::cout << "Trying to receive" << std::endl;

  while (true) {
    server.receive(buffer);
    std::cout << "Received " << buffer << std::endl;
  }


  return EXIT_SUCCESS;
}