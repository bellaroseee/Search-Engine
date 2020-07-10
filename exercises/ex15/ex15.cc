/*
 * Copyright 2020 Bella Rose
 * name: Bella Rose
 * UW email: brose714@uw.edu
 *
 * read and write the bytes from local file over TCP connection
 */

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include "network.h"
#define BUF 256

// taken from sendreceive.cc
void Usage(char *progname);


int main(int argc, char **argv) {
  // argc needs to accept
  // - hostname of server
  // - port number of the server
  // - name of local file
  if (argc != 4) {
    Usage(argv[0]);
  }

  // check the port
  unsigned short port = 0;
  if (sscanf(argv[2], "%hu", &port) != 1) {
    Usage(argv[0]);
  }

  // get the correct hostname
  struct sockaddr_storage addr;
  size_t addrlen;
  if (!LookUpName(argv[1], port, &addr, &addrlen)) {
    Usage(argv[0]);
  }

  // establish connection
  int socket_fd;
  if (!Connect(addr, addrlen, &socket_fd)) {
    Usage(argv[0]);
  }

  // open file to read
  int file = open(argv[3], O_RDONLY);
  if (file == -1) {
    std::cerr << "fiile cannot be opened" << std::endl;
  }

  // READ
  char readbuf[BUF];
  int res;
  while (1) {
    res = read(file, readbuf, sizeof(readbuf));

    // termination condition
    if (res == 0) {
      break;
    }
   
    if (res == -1) {
      if (errno == EINTR) {
	continue;	
      }
      std::cerr << "failed to read file" << std::endl;
      close(file);
      close(socket_fd);
      return EXIT_FAILURE;
    }
    readbuf[res] = '\0';
    break;
  }

  // WRITE
  while (1) {
    int wres = write(socket_fd, readbuf, res);
    if (wres == 0) {
      std::cerr << "socket closed prematurely" << std::endl;
      close(file);
      close(socket_fd);
      return EXIT_FAILURE;
    }
    if (wres == -1) {
      if (errno == EINTR) {
	continue;
      }
      std::cerr << "socket write failure" << std::endl;
      close(file);
      close(socket_fd);
      return EXIT_FAILURE;
    }
    break;
  }

  // clean up
  close(file);
  close(socket_fd);
  return EXIT_SUCCESS;
}


void Usage(char *progname) {
  std::cerr << "usage: " << progname << " hostname port filename" << std::endl;
  exit(EXIT_FAILURE);
}
