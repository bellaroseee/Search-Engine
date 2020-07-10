/*
 * Copyright 2020 Bella Rose
 * name: Bella Rose
 * UW email: brose714@uw.edu
 */

#ifndef NETWORK_H_
#define NETWORK_H_


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

// from connect.cc & sendreceive.cc

bool LookUpName(char* name,
                unsigned short port,
                struct sockaddr_storage* ret_addr,
                size_t* ret_addrlen);

bool Connect(const struct sockaddr_storage& addr,
             const size_t& addrlen,
             int* ret_fd);

#endif  // NETWORK_H_
