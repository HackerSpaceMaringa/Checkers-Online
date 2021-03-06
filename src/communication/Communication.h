#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "defines.h"
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Communication{
    public:
        static void initCommunication(tcp::socket**, char*);
        static void waitCommunication(tcp::socket**);
        static void sendMessage(tcp::socket*, int, int);
        static void readMessage(tcp::socket*, int*, int*);
};

#endif
