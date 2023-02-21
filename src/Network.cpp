#include "Network.h"

Network::Network()
{

    this->ServerSock = socket(AF_INET, SOCK_STREAM, 0);
    this->ServerAddr.sin_family = AF_INET;
    this->ServerAddr.sin_port = htons(5001);
    inet_pton(AF_INET,"192.168.0.135",&this->ServerAddr.sin_addr);
    connect(this->ServerSock,(struct sockaddr*)&this->ServerAddr,sizeof(this->ServerAddr));

        std::cout<<"test\n";


}

Network::~Network()
{
    //dtor
}
bool Network::VerificareConectare()
{
     char buffer[300];
     int x = recv(this->ServerSock,buffer,299,0);
     if(x>0)
     {
        return true;
     }
     else
     {
        return false;

     }
}

void Network::RequestServer(Users& User)
{
    std::string Send="Log: "+User.Log+" Password: "+User.Pasword;
    send(this->ServerSock,Send.c_str(),Send.size(),0);
    std::cout<<Send<<std::endl;
}
