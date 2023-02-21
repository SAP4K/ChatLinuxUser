#include<iostream>
class Users
{
    public:
        Users();
    void Logare();
        ~Users();
    private:
    std::string Log;
    std::string Pasword;
    std::string Mail;
    int ID_User;
    friend class Network;
};

