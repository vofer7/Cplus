#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void Pytanie::wczytaj()
{
    fstream plik;
    plik.open("quiz.txt",ios::in);
    int nr_lini=(nr_pytania-1)*6+1;
    int aktualny_numer=1;
    string linia;
    while(getline(plik,linia))
    {
        if(aktualny_numer==nr_lini) tresc=linia;
        if(aktualny_numer==nr_lini+1) a=linia;
        if(aktualny_numer==nr_lini+2) b=linia;
        if(aktualny_numer==nr_lini+3) c=linia;
        if(aktualny_numer==nr_lini+4) d=linia;
        if(aktualny_numer==nr_lini+5) poprawna=linia;
        aktualny_numer++;
    }
    plik.close();
}

void Pytanie::zadaj()
{
    cout<<endl<<tresc<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<"----------------"<<endl;
    cout<<endl<<"Odpowiedz: ";
    cin>>odpowiedz;
}

void Pytanie::sprawdz()
{
    if(odpowiedz==poprawna)
    {
        punkt=1;
    }else punkt=0;
}
