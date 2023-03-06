#include<iostream>
#include<stdio.h>
class Users
{
    public:
        Users();
        ~Users();
    void Logare();
    bool Inregistrare();
    void Curatire();
    std::string get_log();
    std::string get_mail();
    std::string get_id_user();
    private:
    std::string Log;
    std::string Pasword;
    std::string Mail;
    std::string ID_User;
    bool check;
    friend class Network;
    void obtinere_date_server(char*);
};
