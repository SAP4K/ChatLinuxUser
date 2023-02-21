#include<Network.h>
int main()
{
    Network net;
    Users Utilizator;
    std::string conducator;

    if(net.VerificareConectare())
    {

        while(true)
        {
            std::cout<<"\n1-Logare\n2-Inregistrare\nIntrodu: ";
            std::getline(std::cin,conducator);
            switch(conducator[0])
            {
                case '1':{ Utilizator.Logare();
                net.RequestServer(Utilizator);  }break;

            }

        }
    }

}
