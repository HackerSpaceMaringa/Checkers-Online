#include "Communication.h"

void Communication::initCommunication(tcp::socket **socket, char *address){
    boost::asio::io_service io_service;
    (*socket) = new tcp::socket(io_service);
    tcp::resolver resolver(io_service);
    boost::asio::connect(*(*socket), resolver.resolve({address,
                to_string(9000).c_str()}));
}

void Communication::sendMessage(tcp::socket *socket, int newId, int oldId){
    boost::system::error_code error;
    string message;
    ostringstream convert;
    convert << newId << ":" << oldId;
    message = convert.str();
    boost::asio::write(*socket, boost::asio::buffer(message), error);
}

void Communication::readMessage(tcp::socket *socket, int *newId, int *oldId){
    try{
        boost::system::error_code error;
        char data[10];
        size_t len = socket->read_some(boost::asio::buffer(data), error);
        data[len] = '\0';
        char *coords[2];
        coords[0] = strtok(data,":");
        coords[1] = strtok(NULL,":");
        *newId = atoi(coords[0]);
        *oldId = atoi(coords[1]);
    }
    catch (exception &ex){
        cout << ex.what() << endl;
    }
}

void Communication::waitCommunication(tcp::socket **socket){
    boost::asio::io_service io_service;
    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), 9000));
    (*socket) = new tcp::socket(io_service);
    a.accept(*(*socket));
}
