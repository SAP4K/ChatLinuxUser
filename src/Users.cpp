#include "Users.h"

Users::Users()
{
    this->ID_User = -5;
    this->Log.clear();
    this->Mail.clear();
    this->Pasword.clear();
}
void Users::Logare()
{
    std::cout<<"------------Introdu Loghinul: "; std::getline(std::cin,this->Log);
    std::cout<<"------------Introdu Parola: "; std::getline(std::cin,this->Pasword);
}
Users::~Users()
{

}
