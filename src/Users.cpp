#include "Users.h"
Users::Users()
{
    this->ID_User = "NULL";
    this->Log.clear();
    this->Mail.clear();
    this->Pasword.clear();
    this->check = false;
}
std::string Users::get_id_user()
{
    return this->ID_User;
}
std::string Users::get_log()
{
    return this->Log;
}
std::string Users::get_mail()
{
    return this->Mail;
}
void Users::Logare()
{
    std::cout<<"--------->Introdu Loghinul: "; std::getline(std::cin,this->Log);
    std::cout<<"--------->Introdu Parola: "; std::getline(std::cin,this->Pasword);
}
bool Users::Inregistrare()
{
    if(this->check==false){
        std::string parola_repetatl;
        std::cout<<"--------->Introdu Loghinul: "; std::getline(std::cin,this->Log);
        std::cout<<"--------->Introdu Parola: "; std::getline(std::cin,this->Pasword);
        std::cout<<"--------->Introdu Parola repetat: "; std::getline(std::cin,parola_repetatl);
        while(true)
        {
            if(this->Pasword.compare(parola_repetatl) != 0 )
                {
                    std::cout<<"Nu coincid parolele(0-Esire): \n";
                    std::cout<<"--------->Introdu Parola: "; std::getline(std::cin,parola_repetatl);
                    if(parola_repetatl[0] == '0'){
                        this->Curatire();
                        return false;
                        }
                    std::cout<<"--------->Introdu Parola repetat: ";
                    std::getline(std::cin,this->Pasword);
                }
            else
            {
                std::cout<<"--------->Introdu Mailul: "; std::getline(std::cin,this->Mail);
                return true;
            }
        }
    }
    return false;
}
void Users::obtinere_date_server(char* art)
{
    int i=2;
    int q=0;
    this->ID_User.clear();
    while(art[i]!='\000')
    {
            if(q==0)
            {
                this->ID_User.push_back(art[i]);
            }
            if(q==1)
            {
                this->Log.push_back(art[i]);
            }
            if(q==3)
            {
                this->Mail.push_back(art[i]);
            }
            if(art[i+1]=='L'&&art[i+2]=='&')
            {
                q=1;
                i+=2;
            }
            if(art[i+1]=='E'&&art[i+2]=='m'&&art[i+3]=='&')
            {
                q=3;
                i+=3;
            }
             i++;
    }
}
void Users::Curatire()
{
    this->Log.clear();
    this->Pasword.clear();
    this->Mail.clear();
    this->ID_User.clear();
}
Users::~Users()
{
    std::cout<<"test\n";
}
