
#define ASIO_STANDALONE

#include <iostream>
#include <cstdlib>
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <netdb.h>

#include "../include/CommandLine.h"


using namespace mspeck;

int main(int argc, char **argv) {

    
    CommandLine arg_t = CommandLine(argc, argv);
    mspeck::CommandLine::getHelp();
}