#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "fun.cpp"
using namespace std;


    int liczba_sztuk_w_magazynie[100];
    float cena_jednostkowa[100];
    bool czy_znalazo=false;
    bool czy_usunelo=false;
    bool edycja=false;
    bool look=false;


int main()
{

    int ile;
    int znak;
    char znak_decyzji;
    bool decyzja1=false;

    do{
    system("cls");
    cout << "----------MENU-----------" << endl;
    cout << "1.Wprowadzenie Danych" << endl;
    cout << "2.Zapisanie Danych do Pliku" <<endl;
    cout << "3.Wyszukaj w bazie"   <<endl;
    cout << "4.Odczytaj baze"   <<endl;
    cout << "5.Usun produkt "   <<endl;
    cout << "6.Edytuj date dostawy"<<endl;
    cout << "7.Wyszukiwanie Regularne"<<endl;
    cout<<  "8.Wyjscie"<<endl;

    cout<<"Wybierz Opcje : "; cin>>znak;

    switch(znak)
    {
        case 1:
        cout<<"Ile produktow chcesz wprowadzic ?"<<endl;
        cin>>ile;
        wprowadzenie_danych(ile);
        decyzja1=true;
        break;

        case 2:
        if(decyzja1==true)
        {
            zapis_danych(ile);
            cout<<"ZAPISANO !"<<endl;

        }else
        {
            cout<<"Najpierw wprowadz Dane !"<<endl;
        }

        break;

        case 3:
           wyszukaj_w_bazie();
           if(czy_znalazo==false)
            cout<<"NIE ZNALEZIONO"<<endl;
           break;

        case 4:
          odczyt_bazy();
          break;

        case 5:
            usun();
            if(czy_usunelo==true)
            {
                cout<<"Usunieto!"<<endl;
            }else
            {
                cout<<"Nie ma takiego produktu do Usuniecia !"<<endl;
            }
            break;

        case 6:

         edytuj_date_dostawy();
         if(edycja==true)
         {
             cout<<"ZEDYTOWANO"<<endl;
         }else
         {
             cout<<"Nie ma takiego produktu do edycji !"<<endl;
         }
         break;

        case 7:
            wyszukanie_regularne();
            if(look==false)
            {
                cout<<"Nie zanleziono"<<endl;
            }

            break;

        case 8:
            system("cls");
            wyjscie();
            break;

    }


        cout<<"Czy chcesz zakonczyc progam ? (t/n) : ";cin>>znak_decyzji; cout<<"/n";
    }while(znak_decyzji!='t');
    return 0;
}
