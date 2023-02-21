#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include<chrono>
#include<thread>
#include<fcntl.h>
#include<vector>
#include<Users.h>
class Network
{
  public:
        Network(std::string,std::int32_t);
        Network();
        bool VerificareConectare();
        void RequestServer(Users& );
        ~Network();
    private:
    int ServerSock;
    sockaddr_in ServerAddr;

};

