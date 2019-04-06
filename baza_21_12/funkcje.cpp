#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void wprowadzenie_danych(dane & produkt,int ile);
{
    for (int i=0;i<ile;i++)
    {
      cin>>produkt[i].nazwa<<endl;
      cin>>produkt[i].producent<<endl;
    }
}
