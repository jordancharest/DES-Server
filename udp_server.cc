#include "udp_server.h"

#include <errno.h>
#include <string.h>

#include <iostream>

namespace UDP {
  const int kMaxBuffer = 1024;

// ----------------------------------------------------------------------------
Server::Server(const std::string& host, int port) : host_(host), port_(port) {
    
  // create the socket
  if ( (this->sd_ = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      std::cerr << "ERROR: " << strerror(errno) << "\nsocket() failed" << std::endl;
      std::exit(EXIT_FAILURE);
  }

  this->sock_.sin_family = AF_INET; // IPv4
  this->sock_.sin_addr.s_addr = htonl(INADDR_ANY);  // accept any address

  // specify port of this server
  this->sock_.sin_port = htons(this->port_);

  // bind to port
  if ( bind(this->sd_, (struct sockaddr* )&this->sock_, sizeof(this->sock_)) < 0) {
      std::cerr << "ERROR: " << strerror(errno) << "\nbind() failed" << std::endl;
      std::exit(EXIT_FAILURE);
  }
}

// ----------------------------------------------------------------------------
void Server::receive(std::string& return_buffer) {
  int n_bytes;
  char buffer[kMaxBuffer];
  struct sockaddr_in client;
  int len = sizeof client;
    
  // recvfrom is a blocking call
  n_bytes = recvfrom(this->sd_, buffer, kMaxBuffer, 0, (struct sockaddr* )&client, (socklen_t* )&len);
  if (n_bytes < 0) {
    std::cerr << "ERROR: " << strerror(errno) << "\nrecvfrom() failed" << std::endl;
  } else {
    std::cout << "Received datagram from: " << inet_ntoa(client.sin_addr) << "\n";
   
    // null terminate and copy it to the return string
    buffer[n_bytes] = '\0';
    return_buffer = buffer;
  }
}
    




} // namespace UDP