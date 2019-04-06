#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

    extern  int liczba_sztuk_w_magazynie[100];
    extern float cena_jednostkowa[100];
    extern bool czy_znalazo;
    extern bool czy_usunelo;
    extern bool edycja;
    extern  bool look;

    void wprowadzenie_danych(int ile);
    void zapis_danych(int ile);
    void wyszukaj_w_bazie();
    void odczyt_bazy();
    void usun();
    void wyjscie();
    void edytuj_date_dostawy();
    void wyszukanie_regularne();

#endif // HEAD_H_INCLUDED
