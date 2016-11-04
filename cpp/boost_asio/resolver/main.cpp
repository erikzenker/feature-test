#include <boost/asio.hpp>
#include <iostream>

//compile: g++ main.cpp -std=c++11 -lboost_system -pthread

int main(){

    boost::asio::io_service io_service;
    boost::asio::ip::udp::resolver resolver(io_service);

    boost::asio::ip::udp::resolver::iterator endpointIterEnd;
    auto endpointIterBegin = resolver.resolve({"127.0.0.1", "0"});

    for(endpointIterBegin; endpointIterBegin != endpointIterEnd; endpointIterBegin++){
	std::cout << endpointIterBegin->endpoint().address() << std::endl;
    }
    
    return 0;
}
