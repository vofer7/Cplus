#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std ;
int licznik=0;
void *wczytaj_tab(int tab_a[],int tab_b[],int rozA,int rozB);
void *wyswietl(int tab_a[],int tab_b[],int rozA,int rozB);
void *np_c(int tab_a[],int tab_b[],int rozA,int rozB);
void *minimalna_maxymalna(int tab_a[],int tab_b[],int rozA,int rozB);
int main()
{
    int rozmiar_a,rozmiar_b;
    int *tab_A,*tab_B;
    cout<<"Podaj rozmiar tablicy A"<<endl;
    cin>>rozmiar_a;
    tab_A=new int[rozmiar_a];

    cout<<"Podaj rozmiar tablicy B"<<endl;
    cin>>rozmiar_b;
    tab_B=new int[rozmiar_b];
    wczytaj_tab(tab_A,tab_B,rozmiar_a,rozmiar_b);
    wyswietl(tab_A,tab_B,rozmiar_a,rozmiar_b);
    np_c(tab_A,tab_B,rozmiar_a,rozmiar_b);
    delete [] tab_A;
    delete [] tab_B;


}

void *wczytaj_tab(int tab_a[],int tab_b[],int rozA,int rozB)
{
    srand(time(NULL));
    int liczba=(rand()%10)+2;
    for(int i=0;i<rozA;i++)
    {
        liczba=(rand()%10)+2;
        tab_a[0+i]=liczba;
    }

     for(int i=0;i<rozB;i++)
    {
        liczba=(rand()%10)+6;
        tab_b[0+i]=liczba;
    }

}

void *wyswietl(int tab_a[],int tab_b[],int rozA,int rozB)
{
       for(int i=0;i<rozA;i++)
    {
        cout<<"tab_a["<<i<<"]= "<<tab_a[0+i]<<endl;
    }

    cout<<"------------------------------------"<<endl;
     for(int i=0;i<rozB;i++)
    {
      cout<<"tab_b["<<i<<"]= "<<tab_b[0+i]<<endl;
    }


}

void *np_c(int tab_a[],int tab_b[],int rozA,int rozB)
{
    int c_rozmiar=0;
    int suma=0;
    int ile_nieparzystych_b=0;
    int ile_nieparzystych_a=0;

    for(int i=0;i<rozB;i++)
    {
     if(tab_b[i]%2!=0)      //2

        ile_nieparzystych_b++;
    }

    for(int i=0;i<rozA;i++)
    {
     if(tab_a[i]%2!=0)              //3

        ile_nieparzystych_a++;
    }

    int *tab_C;
    suma =ile_nieparzystych_a+ile_nieparzystych_b;

    tab_C=new int[suma];
    for(int i=0;i<rozA;i++)
    {
     if(tab_a[i]%2!=0)              //3 5,7,9,
        {
        tab_C[licznik]=tab_a[i];
        licznik++;
        }
    }

    for(int i=0;i<rozB;i++)
    {
        if(tab_b[i]%2!=0){

        tab_C[licznik]=tab_b[i];
        licznik++;
        }
    }
        cout<<"----------------------------"<<endl;
        for(int i=0;i<suma;i++)
        {
            for(int j=0;j<suma-1;j++)
            {
               if( tab_C[j]==tab_C[j+1])
               {


                   tab_C[j]=0;

               }
               swap(tab_C[j],tab_C[j+1]);

            }
        }

        for(int i=0;i<suma;i++)
        {
    {
     if(tab_C[i]!=0)              //3 5,7,9,
        {
        c_rozmiar++;
        }
    }
        }


    int *Tab_c;
    Tab_c=new int[c_rozmiar];

    for(int i=0;i<suma;i++)
    {
        if(tab_C[i]!=0)
        {
                    c_rozmiar--;
            Tab_c[c_rozmiar]=tab_C[i];

            cout<<"Tab_C["<<c_rozmiar<<"] = "<< Tab_c[c_rozmiar]<<endl;
        }
    }






    delete [] Tab_c;
    delete [] tab_C;

}





