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
        bool VerificareLogare(Users&);
        bool InregistrareContNou(Users&);
        bool get_contacte(Users&);
        void adauga_contact(Users&);
        ~Network();
    private:
    int ServerSock;
    sockaddr_in ServerAddr;
};
