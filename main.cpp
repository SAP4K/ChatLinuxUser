#include<Network.h>
Network net;
Users Utilizator;
int meniu()
{
    std::string meniu_control;
    while(true)
    {
        std::cout<<"1-Afisare date personale\n2-Afisare Contacte\n3-Adauga un nou contact\n0-Esire";
        std::cout<<"\nIntrodu: ";
        std::getline(std::cin,meniu_control);
        switch(meniu_control[0])
        {
            case '1':
            {
                std::cout<<">ID_User: "<< Utilizator.get_id_user();
                std::cout<<"\n>Mail: "<<Utilizator.get_mail();
                std::cout<<"\n>Log: "<<Utilizator.get_log()<<"\n";
            }break;
            case '2':
            {
                net.get_contacte(Utilizator);
            }break;
            case '3':
            {
                net.adauga_contact(Utilizator);
            }break;
            case '0':
            {
                return 0;
            }break;
        }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
int main()
{
    std::string conducator;

        while(true)
        {
            std::cout<<"\n1-Logare\n2-Inregistrare\n0-Esire\nIntrodu: ";
            std::getline(std::cin,conducator);
            switch(conducator[0])
            {
                case '1':{
                    Utilizator.Logare();
                    if(net.VerificareLogare(Utilizator))
                    {

                        if(meniu() == 0)
                        {
                            return 0;
                        }
                    }
                }break;
                case '2':
                {
                    if(Utilizator.Inregistrare()){
                        if(net.InregistrareContNou(Utilizator))
                        {
                            if(meniu() == 0)
                            {
                                return 0;
                            }
                        }
                    }
                }break;
                case '0':
                {
                    return 0;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
}
