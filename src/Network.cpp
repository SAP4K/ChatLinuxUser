#include "Network.h"
Network::Network()
{
    int port = 5001;
    this->ServerSock = socket(AF_INET, SOCK_STREAM, 0);
    this->ServerAddr.sin_family = AF_INET;
    this->ServerAddr.sin_port = htons(port);
    inet_pton(AF_INET,"127.0.0.1",&this->ServerAddr.sin_addr);
    while(connect(this->ServerSock,(struct sockaddr*)&this->ServerAddr,sizeof(this->ServerAddr)) != 0 )
    {
        port++;
        this->ServerAddr.sin_port = htons(port);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
bool Network::get_contacte(Users& userul)
{
    char bufer[5000];
    send(this->ServerSock,"001",3,0);
    recv(this->ServerSock,bufer,4999,0);
    std::cout<<bufer<<std::endl;
    return true;
}
void Network::adauga_contact(Users& userul)
{
    std::string comand = "010";
    std::cout<<"Introdu Loginul persoanei cautate: ";
    std::string login;
    std::getline(std::cin,login);
    comand+=login;
    char bufer[500];
    send(this->ServerSock,comand.c_str(),comand.size(),0);
    recv(this->ServerSock,bufer,4999,0);
    switch(bufer[0])
    {
        case '0':{ std::cout<<">Nu exista asa utilizator\n";}break;
        case '1':{ std::cout<<">A fost adaugat cu succes\n";}break;
        case '2':{ std::cout<<">Deja este adaugat acest utilizator\n";}break;
    }
}
Network::~Network()
{
    close(this->ServerSock);
    std::cout<<"exit\n";
}


bool Network::VerificareLogare(Users& user)
{
    char raspuns[1000];
    std::string send_date_inregistrare="L&"+user.Log+"P&"+user.Pasword;
    send(this->ServerSock,send_date_inregistrare.c_str(),send_date_inregistrare.size(),0);
    recv(this->ServerSock,raspuns,999,0);
    if(raspuns[0] == '0')
    {
        std::cout<<"Eroare!!!!\nParola sau loghinul este incrorect\n";
        return false;
    }
    std::cout<<"conectact cu succes\n";
    user.Curatire();
    user.obtinere_date_server(raspuns);
    return true;

}
bool Network::InregistrareContNou(Users& user)
{
    char raspuns[200];
    memset(raspuns,0,199);
    std::string trimite_mesaj_ingregistrare = "ReG-5L&"+user.Log+"P&"+user.Pasword+"M&"+user.Mail;
    send(this->ServerSock,trimite_mesaj_ingregistrare.c_str(),trimite_mesaj_ingregistrare.size(),0);
    recv(this->ServerSock,raspuns,199,0);
    while(raspuns[0] == '0')
    {
        std::cout<<"Eroare!!!!!\nDeja exista asa utilizator\n1-Reintrodu alte date\n0-esire\nIntrodu: ";
        std::string raspuns_temporar;
        std::getline(std::cin,raspuns_temporar);
        if(raspuns_temporar[0]=='0')
        {
            return false;
        }
        else
        {
            user.Inregistrare();
        }
        trimite_mesaj_ingregistrare = "ReG-5L&"+user.Log+"P&"+user.Pasword+"M&"+user.Mail;
        send(this->ServerSock,trimite_mesaj_ingregistrare.c_str(),trimite_mesaj_ingregistrare.size(),0);
        recv(this->ServerSock,raspuns,199,0);
    }
    user.obtinere_date_server(raspuns);
    std::cout<<"Inregistrarea a avut loc cu succes!!!!\n";
    user.check=true;
    return true;
}
