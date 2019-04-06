#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

    string nazwa[256];
    string producent[256];
    string model[50];
    string kategoria[100] ;
    int liczba_sztuk_w_magazynie[100];
    float cena_jednostkowa[100];
    string przewidywana_data_dostawy[100];
    bool czy_znalazo=false;
    bool czy_usunelo=false;
    bool edycja=false;
    bool look=false;
    void wprowadzenie_danych(int ile);
    void zapis_danych(int ile);
    void wyszukaj_w_bazie();
    void odczyt_bazy();
    void usun();
    void wyjscie();
    void edytuj_date_dostawy();
    void wyszukanie_regularne();

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

void wprowadzenie_danych(int ile)
{
    char decyzja;

    for (int i=0;i<ile;i++)
    {
        cout<<"Podaj nazwe : "; cin.ignore();getline(cin,nazwa[i]); cout<<endl;
        cout<<"Podaj producenta : ";cin>>producent[i]; cout<<endl;
        cout<<"Podaj model : "; cin>>model[i];cout<<endl;
        cout<<"Podaj kategorie : ";cin.ignore();getline(cin,kategoria[i]);cout<<endl;
        cout<<"Podaj liczbe sztuk w magazynie : " ;cin>>liczba_sztuk_w_magazynie[i];cout<<endl;
        cout<<"Podaj cene jednostkowa: "; cin>>cena_jednostkowa[i];cout<<endl;
        cout<<"Czy chcesz wprowadzic date ?? (t/n) : ";cin>>decyzja;
        if(decyzja=='t')
        {
            cout<<"Podaj date dostawy: "; cin>>przewidywana_data_dostawy[i];cout<<endl;
        }
    }
}

void zapis_danych(int ile)
{
    fstream plik;
    plik.open("baza.txt",ios::out|ios::app);
    for (int i=0;i<ile;i++)
    {
        plik<<"***********************"<<endl;
        plik<<"Nazwa: "<<nazwa[i]<<endl;
        plik<<"Producent : "<<producent[i]<<endl;
        plik<<"Model : "<<model[i]<<endl;
        plik<<"Kategoria : "<<kategoria[i]<<endl;
        plik<<"Liczba sztuk : "<<liczba_sztuk_w_magazynie[i]<<endl;
        plik<<"Cena : "<<cena_jednostkowa[i]<<endl;
        plik<<"Data dostawy: "<<przewidywana_data_dostawy[i]<<endl;

    }

}

void wyszukaj_w_bazie()
{
    int wybor;
    string *tablica;
    int licznik=0;
    fstream plik1,plik2;
    string szukaj,szukaj0,linia;

    plik1.open("baza.txt",ios::in);



    while(getline(plik1,linia))
    {
        licznik++;
    }


    plik1.close();


    tablica = new string [licznik];



    plik2.open("baza.txt",ios::in);

    for(int i=0;i<licznik;i++)
    {
        getline(plik2,linia);
        tablica[i]=linia;
    }


    cout<<"Wedlug czego chcesz szukac ?"<<endl;
    cout<<"1.Producent"<<endl;
    cout<<"2.Model"<<endl;
    cout<<"3.Nazwa"<<endl;
    cout<<"Wybierz : "; cin>>wybor;


    switch(wybor)
    {
    case 1:
        cout<<"Jakiego Producenta : "; cin>>szukaj;
        szukaj0="Producent : "+szukaj;
        system("cls");
        for(int i=0;i<licznik;i=i+8)
        if(szukaj0==tablica[i+2])
        {
            cout<<tablica[i]<<endl;
            cout<<tablica[i+2]<<endl;
            cout<<tablica[i+1]<<endl;
            cout<<tablica[i+3]<<endl;
            cout<<tablica[i+4]<<endl;
            cout<<tablica[i+5]<<endl;
            cout<<tablica[i+6]<<endl;
            cout<<tablica[i+7]<<endl;

            czy_znalazo=true;
        }
        break;

    case 2:
        cout<<"Jaki model? : "; cin>>szukaj;
            szukaj0="Model : "+szukaj;
         for(int i=0;i<licznik;i=i+8)
        if(szukaj0==tablica[i+3])
        {
            system("cls");
            cout<<tablica[i]<<endl;
            cout<<tablica[i+3]<<endl;
            cout<<tablica[i+1]<<endl;
            cout<<tablica[i+2]<<endl;
            cout<<tablica[i+4]<<endl;
            cout<<tablica[i+5]<<endl;
            cout<<tablica[i+6]<<endl;
            cout<<tablica[i+7]<<endl;
            czy_znalazo=true;

        }
        break;

        case 3:
        cout<<"Jaka nazwa ? : "; cin>>szukaj;
            szukaj0="Nazwa: "+szukaj;
         for(int i=0;i<licznik;i=i+8)
        if(szukaj0==tablica[i+1])
        {
            system("cls");
            cout<<tablica[i]<<endl;
            cout<<tablica[i+3]<<endl;
            cout<<tablica[i+1]<<endl;
            cout<<tablica[i+2]<<endl;
            cout<<tablica[i+4]<<endl;
            cout<<tablica[i+5]<<endl;
            cout<<tablica[i+6]<<endl;
            cout<<tablica[i+7]<<endl;
            czy_znalazo=true;

        }
        break;


    }




}

void odczyt_bazy()
{
    fstream plik;
    string linia,zmienna;
    plik.open("baza.txt",ios::in);
    while(!plik.eof())
    {
        getline(plik,linia);
        zmienna=linia;
        cout<<zmienna<<endl;
    }
}

void wyjscie()
{
    cout<<"Projekt wykonal : Juszczak Przemyslaw"<<endl;
    exit(0);


}

void usun()
{
    string nazwa;
    cout<<"Podaj nazwe produktu do usuniecia: "; cin.ignore(); getline(cin,nazwa);
    nazwa="Nazwa: "+nazwa;

    string *tablica;
    int licznik=0;
    fstream plik1,plik2,plik3;
    string linia;

    plik1.open("baza.txt",ios::in);



    while(getline(plik1,linia))
    {
        licznik++;
    }


    plik1.close();


    tablica = new string [licznik];



    plik2.open("baza.txt",ios::in);

    for(int i=0;i<licznik;i++)
    {
        getline(plik2,linia);
        tablica[i]=linia;
    }

    plik2.close();

    plik3.open("baza.txt",ios::out);
    for(int i=0;i<licznik;i=i+8)
        {
            if(nazwa==tablica[i+1])
            {
                czy_usunelo=true;

            }
            else
            {
            plik3<<tablica[i]<<endl;
            plik3<<tablica[i+1]<<endl;
            plik3<<tablica[i+2]<<endl;
            plik3<<tablica[i+3]<<endl;
            plik3<<tablica[i+4]<<endl;
            plik3<<tablica[i+5]<<endl;
            plik3<<tablica[i+6]<<endl;
            plik3<<tablica[i+7]<<endl;



            }

            plik3.close();
        }

}

void edytuj_date_dostawy()
{
    int licznik=0;
    fstream plik,plik1,plik2;
    string linia;
    string *tablica;
    string nazwa;
    string data;

    plik.open("baza.txt",ios::in);

    while(getline(plik,linia))
    {
        licznik++;
    }

    plik.close();

    tablica=new string[licznik];

    plik1.open("baza.txt",ios::in);

    for(int i=0;i<licznik;i++)
    {

        getline(plik1,linia);
        tablica[i]=linia;

    }

    cout<<"Podaj nazwe produktu aby zmienic jego date: ";cin.ignore(); getline(cin,nazwa);
    nazwa="Nazwa: "+nazwa;

    plik2.open("baza.txt",ios::out);

    for(int i=0;i<licznik;i=i+8)

    {
        if(nazwa==tablica[i+1])
        {
            cout<<"Podaj nowa date :  "; cin>>data;
            tablica[i+7]="Data dostawy: "+data;

            plik2<<tablica[i]<<endl;
            plik2<<tablica[i+1]<<endl;
            plik2<<tablica[i+2]<<endl;
            plik2<<tablica[i+3]<<endl;
            plik2<<tablica[i+4]<<endl;
            plik2<<tablica[i+5]<<endl;
            plik2<<tablica[i+6]<<endl;
            plik2<<tablica[i+7]<<endl;

            edycja=true;

        }else
        {
            plik2<<tablica[i]<<endl;
            plik2<<tablica[i+1]<<endl;
            plik2<<tablica[i+2]<<endl;
            plik2<<tablica[i+3]<<endl;
            plik2<<tablica[i+4]<<endl;
            plik2<<tablica[i+5]<<endl;
            plik2<<tablica[i+6]<<endl;
            plik2<<tablica[i+7]<<endl;
            czy_znalazo=true;

        }


    }



}


void wyszukanie_regularne()
{
    char znak;
    fstream plik,plik1;
    int licznik=0;
    string linia;
    string *tablica;
     size_t znalezionaPozycja ;

    cout<<"Na jaka litere zaczyna sie produkt ? "<<endl; cin>>znak;


         plik.open("baza.txt",ios::in);

    while(getline(plik,linia))
    {
        licznik++;
    }

    plik.close();

    tablica=new string[licznik];

    plik1.open("baza.txt",ios::in);

    for(int i=0;i<licznik;i++)
    {

        getline(plik1,linia);
        tablica[i]=linia;

    }


    for(int i=0;i<licznik;i=i+8)
    {
     znalezionaPozycja = tablica[i+1].find( znak );
     if(znalezionaPozycja==7)
     {
            system("cls");
            cout<<tablica[i]<<endl;
            cout<<tablica[i+3]<<endl;
            cout<<tablica[i+1]<<endl;
            cout<<tablica[i+2]<<endl;
            cout<<tablica[i+4]<<endl;
            cout<<tablica[i+5]<<endl;
            cout<<tablica[i+6]<<endl;
            cout<<tablica[i+7]<<endl;
            look=true;


     }

    }

}





