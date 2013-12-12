#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "defines.h"
#include <boost/asio.hpp>
#include <boost/ref.hpp>

using boost::asio::ip::tcp;

class Communication{
    public:
        static void initCommunication(tcp::socket**);
        static void waitCommunication(tcp::socket**);
        static void sendMessage(tcp::socket*, int, int);
        static void readMessage(tcp::socket*, int*, int*);
};

#endif
