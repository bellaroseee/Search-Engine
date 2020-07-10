/*
 * Copyright 2020 Bella Rose
 * name : Bella Rose
 * UW email : brose714@uw.edu
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include <cstdlib>

// from server_accept_rw_close.cc
int Listen(char* portnum, int* sock_family);


// from server_accept_rw_close.cc
void HandleClient(int c_fd, struct sockaddr *addr, size_t addrlen);

#endif  // NETWORK_H_
