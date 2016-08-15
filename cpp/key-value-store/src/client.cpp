// ZMQ
#include <zmq.hpp>

// CLIBS
#include <cstdlib>

// STL
#include <iostream>
#include <sstream>

void recvFromSocket(zmq::socket_t& socket, std::stringstream& ss)
{
    ::zmq::message_t message;                
    socket.recv(&message);
    ss << static_cast<char*>(message.data());
}

void sendToSocket(zmq::socket_t& socket, std::stringstream const & ss)
 {
    std::string string = ss.str();
    ::zmq::message_t message(sizeof(char) * string.size());
    memcpy (static_cast<char*>(message.data()), string.data(), sizeof(char) * string.size());
    socket.send(message);
}

int main()
{

    // Create receiving socket
    zmq::context_t context;
    zmq::socket_t socket(context, ZMQ_REQ);
    socket.connect("tcp://127.0.0.1:5051");

    std::stringstream reqMsg;
    std::stringstream repMsg;    
    
    // Receive messages
    while(true){
	reqMsg << "Hello world!\n";
	sendToSocket(socket, reqMsg);
	recvFromSocket(socket, repMsg);
	std::cout << repMsg.str() << std::endl;	
    }
    
    return EXIT_SUCCESS;
}
