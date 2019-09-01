#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

struct kontakt
{
    int id;
    int id_uzytkownika;
    string imie;
    string nazwisko;
    string adres;
    string nr_tel;
    string email;
};

struct uzytkownik
{
    int id;
    string nazwa;
    string haslo;
};

struct dane_po_logowaniu
{
    bool powodzenie_logowania;
    int id_uzytkownika;
};

int pokaz_id_ostatniego_rekordu()
{
    string linia_tekstu;
    string ostatnia_linia_tekstu;
    string id_str;
    int ilosc_linii_tekstu = 0;
    char znak_temp;
    int id;

    fstream plik_kontaktow;
    plik_kontaktow.open("plik_kontaktow.txt", ios::in);
    if (plik_kontaktow.good()==false)
    {
        cout<<"Nie udalo sie odtworzyc pliku.";
        exit(0);
    }
    while(getline(plik_kontaktow, linia_tekstu))
        ilosc_linii_tekstu++;
    plik_kontaktow.close();

    plik_kontaktow.open("plik_kontaktow.txt", ios::in);
    for (int j = 0; j <ilosc_linii_tekstu; j++)
    {
        getline(plik_kontaktow, linia_tekstu);
        ostatnia_linia_tekstu = linia_tekstu;
    }
    plik_kontaktow.close();

    int i = 0;
    while (isdigit(ostatnia_linia_tekstu[i]) == true)
    {
        znak_temp = ostatnia_linia_tekstu[i];
        id_str += znak_temp;
        i++;
    }
    id = atoi(id_str.c_str());

    return id;
}

void dodaj_kontakt (vector <kontakt> lista_kontaktow, dane_po_logowaniu poprawne_logowanie)
{
    int id;
    string imie;
    string nazwisko;
    string adres;
    string nr_tel;
    string email;

    system("cls");
    cout << "Dodawanie nowego kontatku." << endl;
    cout << "___________________________________________" << endl;
    cout << "Podaj imie: ";
    cin.sync();
    getline(cin, imie);
    cout << "Podaj nazwisko: ";
    cin.sync();
    getline(cin, nazwisko);
    cout << "Podaj adres zamieszkania: ";
    cin.sync();
    getline(cin, adres);
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, nr_tel);
    cout << "Podaj adres email: ";
    cin.sync();
    getline(cin, email);

    fstream plik_kontaktow;
    plik_kontaktow.open("plik_kontaktow.txt", ios::out | ios::app);

    id = pokaz_id_ostatniego_rekordu() + 1;

    plik_kontaktow << id << "|";
    plik_kontaktow << poprawne_logowanie.id_uzytkownika << "|";
    plik_kontaktow << imie << "|";
    plik_kontaktow << nazwisko << "|";
    plik_kontaktow << adres << "|";
    plik_kontaktow << nr_tel<< "|";
    plik_kontaktow << email << "|" <<endl;

    plik_kontaktow.close();

    cout << "___________________________________________" << endl;
    cout << "Kontakt dodany!" << endl;
    system("pause");
}

void wyszukaj_w_kontaktach_po_imieniu (vector <kontakt> lista_kontaktow)
{
    string poszukiwana_fraza;
    system ("cls");

    system ("cls");
    cout << "Wyszukaj w kontaktach po imieniu" << endl;
    cout << "____________________________________" << endl;
    cout << "Podaj imie i zatwierdz enterem: " << endl;
    cin >> poszukiwana_fraza;
    system ("cls");
    cout << "ID. Imie i nazawisko, Adres zamieszkania, Telefon, Adres email"<< endl;
    cout << "________________________________________________________________" << endl << endl;
    int licznik_spelnienia_warunku = 0;
    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
    {
        if (poszukiwana_fraza == p -> imie)
        {
            licznik_spelnienia_warunku++;
            cout << p -> id << ". " <<
                 p -> imie << ", " <<
                 p -> nazwisko << ", " <<
                 p -> adres << ", " <<
                 p -> nr_tel << ", " <<
                 p -> email << endl;
        }
    }
    if (licznik_spelnienia_warunku == 0)
        cout << "Nie istnieje taki kontakt." << endl;
    else
    {
        cout << endl;
        cout << "________________________________________________________________" << endl;
        cout << "Znaleziono rekordow: " << licznik_spelnienia_warunku << endl;
    }

    system("pause");
}

void wyszukaj_w_kontaktach_po_nazwisku (vector <kontakt> lista_kontaktow)
{
    string poszukiwana_fraza;
    system ("cls");
    system ("cls");
    cout << "Wyszukaj w kontaktach po nazwisku" << endl;
    cout << "____________________________________" << endl;
    cout << "Podaj nazwisko i zatwierdz enterem: " << endl;
    cin >> poszukiwana_fraza;
    system ("cls");
    cout << "ID. Imie i nazawisko, Adres zamieszkania, Telefon, Adres email"<< endl;
    cout << "________________________________________________________________" << endl << endl;
    int licznik_spelnienia_warunku = 0;
    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
    {
        if (poszukiwana_fraza == p -> nazwisko)
        {
            licznik_spelnienia_warunku++;
            cout << p -> id << ". " <<
                 p -> imie << " " <<
                 p -> nazwisko << ", " <<
                 p -> adres << ", " <<
                 p -> nr_tel << ", " <<
                 p -> email << endl;
        }
    }
    if (licznik_spelnienia_warunku == 0)
        cout << "Nie istnieje taki kontakt." << endl;
    else
    {
        cout << endl;
        cout << "________________________________________________________________" << endl;
        cout << "Znaleziono rekordow: " << licznik_spelnienia_warunku << endl;
    }
    system("pause");
}

void wypisz_wszystko (vector <kontakt> lista_kontaktow)
{
    system ("cls");
    cout << "LISTA KONTAKTOW"<< endl;
    cout << "Suma wszystkich rekordow: "<< lista_kontaktow.size() << endl;
    cout << "ID. Imie i nazawisko, Adres zamieszkania, Telefon, Adres email"<< endl;
    cout << "________________________________________________________________" << endl << endl;

    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
    {
        cout << p -> id
             << ". " << p -> imie
             << " " << p -> nazwisko
             << ", "<< p -> adres
             << ", "<< p -> nr_tel
             << ", "<< p -> email
             << endl;
    }
    cout << endl;
    cout << "________________________________________________________________" << endl;
    system ("pause");
}

kontakt edycja_zapisz_nowe_dane_do_struktury(vector <kontakt> lista_kontaktow, dane_po_logowaniu poprawne_logowanie)
{
    int id;
    int wybor_parametru;
    string imie, nazwisko, adres, telefon, email;
    kontakt osoba;
    osoba.id = 0;
    cout << "Podaj ID kontaktu, ktory chcesz edytowac: ";
    cin >> id;
    cout << "___________________________________________" << endl;
    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
    {
        if (p -> id == id)
        {
            cout << "ID = " << p -> id <<endl;
            cout << "___________________________________________" << endl;
            cout << "1. Imie: " << p -> imie << endl;
            cout << "2. Nazwisko: " << p -> nazwisko << endl;
            cout << "3. Adres: " << p -> adres << endl;
            cout << "4. Numer telefonu: " << p -> nr_tel << endl;
            cout << "5. Adres e-mail: " << p -> email << endl;
            cout << endl;
            cout << "___________________________________________" << endl;
            cout << "Wybierz parametr, ktory ma zostac zmieniony: ";
            cin >> wybor_parametru;
            osoba.id = id;
            osoba.id_uzytkownika = poprawne_logowanie.id_uzytkownika;
            switch (wybor_parametru)
            {
            case 1:
                cout << "Podaj nowe imie: ";
                cin >> imie;
                osoba.imie = imie;
                osoba.nazwisko = p -> nazwisko;
                osoba.adres = p -> adres;
                osoba.nr_tel = p -> nr_tel;
                osoba.email = p -> email;
                break;
            case 2:
                cout << "Podaj nowe nazwisko: ";
                cin >> nazwisko;
                osoba.imie = p-> imie;
                osoba.nazwisko = nazwisko;
                osoba.adres = p -> adres;
                osoba.nr_tel = p -> nr_tel;
                osoba.email = p -> email;
                break;
            case 3:
                cout << "Podaj nowy adres: ";
                cin >> adres;
                osoba.imie = p -> imie;
                osoba.nazwisko = p -> nazwisko;
                osoba.adres = adres;
                osoba.nr_tel = p -> nr_tel;
                osoba.email = p -> email;
                break;
            case 4:
                cout << "Podaj nowy numer telefonu: ";
                cin >> telefon;
                osoba.imie = p -> imie;
                osoba.nazwisko = p -> nazwisko;
                osoba.adres = p -> adres;
                osoba.nr_tel = telefon;
                osoba.email = p -> email;
                break;
            case 5:
                cout << "Podaj nowy adres email: ";
                cin >> email;
                osoba.imie = p -> imie;
                osoba.nazwisko = p -> nazwisko;
                osoba.adres = p -> adres;
                osoba.nr_tel = p -> nr_tel;
                osoba.email = email;
                break;
            }
        }
    }
    return osoba;
}

void edytuj_kontakt (vector <kontakt> lista_kontaktow, dane_po_logowaniu poprawne_logowanie)
{
    system ("cls");
    kontakt osoba;
    osoba = edycja_zapisz_nowe_dane_do_struktury(lista_kontaktow, poprawne_logowanie);
    if (osoba.id == 0)
        cout << "Nie istnieje kontakt o takim ID." <<endl;
    else
    {
        string linia_tekstu, id_str;
        char znak_temp;
        int id_plik_glowny;
        fstream plik_kontaktow, plik_tymczasowy;
        plik_kontaktow.open("plik_kontaktow.txt", ios::in);
        plik_tymczasowy.open("plik_tymczasowy.txt", ios::out);
        while(getline(plik_kontaktow, linia_tekstu))
        {
            id_str = "";
            int i = 0;
            while (isdigit(linia_tekstu[i]) == true)
            {
                znak_temp = linia_tekstu[i];
                id_str += znak_temp;
                i++;
            }
            id_plik_glowny = atoi(id_str.c_str());
            if (id_plik_glowny != osoba.id)
            {
                plik_tymczasowy << linia_tekstu <<endl;
            }
            else
            {
                plik_tymczasowy << osoba.id << "|";
                plik_tymczasowy << osoba.id_uzytkownika << "|";
                plik_tymczasowy << osoba.imie << "|";
                plik_tymczasowy << osoba.nazwisko << "|";
                plik_tymczasowy << osoba.adres << "|";
                plik_tymczasowy << osoba.nr_tel<< "|";
                plik_tymczasowy << osoba.email << "|" << endl;
            }
        }
        plik_kontaktow.close();
        plik_tymczasowy.close();

        remove("plik_kontaktow.txt");

        rename("plik_tymczasowy.txt", "plik_kontaktow.txt");

        cout << endl << "___________________________________________" << endl;
        cout << "Pomyslnie edytowano." << endl << endl;
    }
    system ("pause");
}

void usun_kontakt ( vector <kontakt> lista_kontaktow)
{
    system ("cls");
    int id, wybor_parametru, licznik_spelnienia_warunku = 0;
    char decyzja;
    cout << "Podaj ID kontaktu, ktory chcesz usunac: ";
    cin >> id;
    cout << "___________________________________________" << endl;
    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); ++p)
    {
        if (p -> id == id)
        {
            licznik_spelnienia_warunku++;
            cout << "ID = " << id <<endl;
            cout << "___________________________________________" << endl;
            cout << "1. Imie: " << p -> imie << endl;
            cout << "2. Nazwisko: " << p -> nazwisko << endl;
            cout << "3. Adres: " << p -> adres << endl;
            cout << "4. Numer telefonu: " << p -> nr_tel << endl;
            cout << "5. Adres e-mail: " << p -> email << endl;
            cout << endl;
            cout << "___________________________________________" << endl;
            cout << "Czy na pewno chcesz usunac wyswitlony kontakt? (t/n) ";
            cin >> decyzja;
            if (decyzja == 't')
            {
                string linia_tekstu, id_str;
                char znak_temp;
                int id_plik_glowny;
                fstream plik_kontaktow, plik_tymczasowy;
                plik_kontaktow.open("plik_kontaktow.txt", ios::in);
                plik_tymczasowy.open("plik_tymczasowy.txt", ios::out);
                while(getline(plik_kontaktow, linia_tekstu))
                {
                    id_str = "";
                    int i = 0;
                    while (isdigit(linia_tekstu[i]) == true)
                    {
                        znak_temp = linia_tekstu[i];
                        id_str += znak_temp;
                        i++;
                    }
                    id_plik_glowny = atoi(id_str.c_str());
                    if (id_plik_glowny != id)
                        plik_tymczasowy << linia_tekstu <<endl;
                }
                plik_kontaktow.close();
                plik_tymczasowy.close();
                remove("plik_kontaktow.txt");
                rename("plik_tymczasowy.txt", "plik_kontaktow.txt");
                cout << endl << "Pomyslnie usunieto kontakt." << endl << endl;
            }
            else if (decyzja == 'n')
                break;
        }
    }
    if (licznik_spelnienia_warunku == 0)
        cout << "Nie istnieje kontakt o takim ID." << endl << endl;
    system ("pause");
}

void wczytaj_kontakty_z_pliku(vector <kontakt> &lista_kontaktow, dane_po_logowaniu poprawne_logowanie)
{
    string linia_tekstu_w_pliku, tekst_tymczasowy;
    int id_uzytk, licznik_kresek = 0, dlugosc;
    char znak;
    fstream plik_kontaktow;
    plik_kontaktow.open("plik_kontaktow.txt", ios::in);
    while(getline(plik_kontaktow,linia_tekstu_w_pliku))
    {
        kontakt osoba;
        dlugosc = linia_tekstu_w_pliku.length();
        for (int i = 0; i < dlugosc; i++)
        {
            znak = linia_tekstu_w_pliku[i];
            if (znak != '|')
                tekst_tymczasowy += znak;
            else
            {
                licznik_kresek++;
                switch (licznik_kresek)
                {
                case 1:
                    osoba.id = atoi(tekst_tymczasowy.c_str());
                    tekst_tymczasowy = "";
                    break;
                case 2:
                    osoba.id_uzytkownika = atoi(tekst_tymczasowy.c_str());
                    tekst_tymczasowy = "";
                    break;
                case 3:
                    osoba.imie = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 4:
                    osoba.nazwisko = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 5:
                    osoba.adres = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 6:
                    osoba.nr_tel = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 7:
                    osoba.email = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                }
            }
        }
        licznik_kresek = 0;
        id_uzytk = poprawne_logowanie.id_uzytkownika;
        if (id_uzytk == osoba.id_uzytkownika)
            lista_kontaktow.push_back(osoba);
    }
    plik_kontaktow.close ();
}

void zmien_haslo(vector <uzytkownik> &lista_uzytkownikow, dane_po_logowaniu poprawne_logowanie)
{
    system ("cls");
    string stare_haslo, nowe_haslo;
    for (vector<uzytkownik>::iterator p = lista_uzytkownikow.begin(); p != lista_uzytkownikow.end(); p++)
    {
        if (poprawne_logowanie.id_uzytkownika == p -> id)
        {
            cout << "Zmiana hasla: " <<endl;
            cout << "___________________________________________" << endl;
            cout << "Podaj stare haslo: " << endl;
            cin.sync();
            getline (cin, stare_haslo);
            if (stare_haslo == p -> haslo)
            {
                cout << "Podaj nowe haslo: " << endl;
                cin.sync();
                getline (cin, nowe_haslo);
                break;
            }
            else
            {
                cout << "Podane haslo jest niepoprawne!" << endl;
                system ("pause");
                break;
            }
        }
    }
    fstream plik_uzytkownikow;
    plik_uzytkownikow.open("plik_uzytkownikow.txt", ios::out);
    for (vector<uzytkownik>::iterator p = lista_uzytkownikow.begin(); p != lista_uzytkownikow.end(); p++)
    {
        if (poprawne_logowanie.id_uzytkownika != p -> id)
        {
            plik_uzytkownikow << p -> id << "|";
            plik_uzytkownikow << p -> nazwa << "|";
            plik_uzytkownikow << p -> haslo << "|" <<endl;
        }
        else
        {
            plik_uzytkownikow << p -> id << "|";
            plik_uzytkownikow << p -> nazwa << "|";
            plik_uzytkownikow << nowe_haslo << "|" << endl;
        }
    }
    plik_uzytkownikow.close();
    cout << endl << "Poprawnie zmieniono haslo." << endl;
    cout << "___________________________________________" << endl;
    system("pause");
}

void pokaz_menu_glowne(vector <kontakt> &lista_kontaktow, vector <uzytkownik> &lista_uzytkownikow, dane_po_logowaniu poprawne_logowanie)
{
    while(true)
    {
        lista_kontaktow.clear();
        wczytaj_kontakty_z_pliku(lista_kontaktow, poprawne_logowanie);
        int wybor_menu_glownego;
        system("cls");
        cout << "Ksiazka adresowa" << endl;
        cout << "___________________________________" << endl;
        cout << "Menu glowne: " << endl;
        cout << "1. Dodaj kontakt." << endl;
        cout << "2. Wyszukaj kontakt po imieniu. " << endl;
        cout << "3. Wyszukaj kontakt po nazwisku. " << endl;
        cout << "4. Wypisz liste wszystkich kontaktow. " << endl;
        cout << "5. Edytuj kontakt. " << endl;
        cout << "6. Usun kontakt. " << endl;
        cout << "7. Zmien haslo. " << endl;
        cout << "8. Wyloguj. " << endl;
        cout << "9. Zakoncz program. " << endl;
        cout << endl;
        cout << endl;

        cout << "Wybierz opcje i zatwierdz enterem: " << endl;

        if (!(cin >> wybor_menu_glownego))
        {
            cout << "To nie jest liczba!" << endl;
            exit(0);
        }
        cout << endl;

        if (wybor_menu_glownego == 1)
            dodaj_kontakt(lista_kontaktow, poprawne_logowanie);
        if (wybor_menu_glownego == 2)
            wyszukaj_w_kontaktach_po_imieniu(lista_kontaktow);
        if (wybor_menu_glownego == 3)
            wyszukaj_w_kontaktach_po_nazwisku(lista_kontaktow);
        if (wybor_menu_glownego == 4)
            wypisz_wszystko(lista_kontaktow);
        if (wybor_menu_glownego == 5)
            edytuj_kontakt(lista_kontaktow, poprawne_logowanie);
        if (wybor_menu_glownego == 6)
            usun_kontakt(lista_kontaktow);
        if (wybor_menu_glownego == 7)
            zmien_haslo(lista_uzytkownikow, poprawne_logowanie);
        if (wybor_menu_glownego == 8)
            break;
        if (wybor_menu_glownego == 9)
            exit (0);
    }
}

void wczytaj_uzytkownikow_z_pliku(vector <uzytkownik> &lista_uzytkownikow)
{
    fstream plik_uzytkownikow;
    string linia_tekstu_w_pliku;
    string tekst_tymczasowy;
    int licznik_kresek = 0;
    int dlugosc;
    char znak;

    plik_uzytkownikow.open("plik_uzytkownikow.txt", ios::in);

    while(getline(plik_uzytkownikow,linia_tekstu_w_pliku))
    {
        uzytkownik osoba;
        dlugosc = linia_tekstu_w_pliku.length();

        for (int i = 0; i < dlugosc; i++)
        {
            znak = linia_tekstu_w_pliku[i];
            if (znak != '|')
            {
                tekst_tymczasowy += znak;
            }
            else
            {
                licznik_kresek++;
                switch (licznik_kresek)
                {
                case 1:
                    osoba.id = atoi(tekst_tymczasowy.c_str());
                    tekst_tymczasowy = "";
                    break;
                case 2:
                    osoba.nazwa = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 3:
                    osoba.haslo = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                }
            }
        }
        licznik_kresek = 0;
        lista_uzytkownikow.push_back(osoba);
    }
    plik_uzytkownikow.close ();
}

void utworz_nowe_konto (vector <uzytkownik> &lista_uzytkownikow)
{
    int id;
    string nazwa;
    string haslo, haslo2;

    if (lista_uzytkownikow.size()==0)
    {
        id = 1;
    }
    else
    {
        vector<uzytkownik>::iterator  itr = lista_uzytkownikow.end() - 1;
        id = (itr -> id) + 1;
    }

    system("cls");

    cout << "Kreastor konta nowego uzytkownika." << endl;
    cout << "___________________________________________" << endl;
    cout << "Podaj nazwe nowego uzytkownika: ";
    cin.sync();
    getline(cin, nazwa);

    for (vector<uzytkownik>::iterator p = lista_uzytkownikow.begin(); p != lista_uzytkownikow.end(); p++)
    {
        if (nazwa == p -> nazwa)
        {
            system("cls");
            cout << "Istnieje juz uzytkownik o takiej nazwie" <<endl;
            cout << "Podaj inna nazwe uzytkownika: ";
            nazwa = "";
            p = lista_uzytkownikow.begin();
            cin.sync();
            getline(cin, nazwa);
        }
    }

    while(true)
    {
        cout << "Wpisz haslo: ";
        cin.sync();
        getline(cin, haslo);

        cout << "Potwierdz haslo: ";
        cin.sync();
        getline(cin, haslo2);
        if (haslo==haslo2)
            break;
        else
            cout << endl << "Niezgodne haslo!" <<endl;
    }

    fstream plik_uzytkownikow;
    plik_uzytkownikow.open("plik_uzytkownikow.txt", ios::out | ios::app);

    plik_uzytkownikow << id << "|";
    plik_uzytkownikow << nazwa << "|";
    plik_uzytkownikow << haslo << "|";
    plik_uzytkownikow << endl;

    plik_uzytkownikow.close();

    cout << "___________________________________________" << endl;
    cout << "Uzytkownik zapisany poprawnie!" << endl;
    system("pause");
}

void wstrzymaj_logwanie()
{
    system("cls");
    for (int i = 5; i >= 0; i--)
    {
        cout << "Mozesz ponownie wprowadzic haslo po: " << i << "s";
        Sleep(1000);
        system("cls");
    }
}

dane_po_logowaniu zaloguj_uzytkownika (vector <uzytkownik> &lista_uzytkownikow, vector <kontakt> &lista_kontaktow)
{
    dane_po_logowaniu poprawne_logowanie;
    while (true)
    {
        int liczba_spelnienia_warunku = 0;
        system("cls");
        cout << "Ekran logowania." << endl;
        cout << "___________________________________________" << endl;
        cout << "Podaj nazwe uzytkownika: ";
        cin.sync();
        string nazwa_u;
        getline(cin, nazwa_u);
        for (vector<uzytkownik>::iterator p = lista_uzytkownikow.begin(); p != lista_uzytkownikow.end(); p++)
        {
            if (p -> nazwa == nazwa_u)
            {
                poprawne_logowanie.id_uzytkownika = p -> id;
                liczba_spelnienia_warunku ++;
                for (int i = 3; i > 0; i--)
                {
                    cout << "Pozostalo prob: " << i <<endl;
                    cout << "Podaj haslo: ";
                    cin.sync();
                    string haslo_u;
                    getline(cin, haslo_u);
                    if (p -> haslo == haslo_u)
                    {
                        poprawne_logowanie.powodzenie_logowania = true;
                        break;
                    }
                    else if (i == 1)
                        wstrzymaj_logwanie();
                    else if ((i == 2) || (i == 3))
                        cout << "Niepoprawne haslo.";
                }
            }
            if (poprawne_logowanie.powodzenie_logowania == true)
                break;
        }
        if (liczba_spelnienia_warunku == 0)
        {
            cout << "Nie ma takiego uzytkownika w bazie" << endl;
            system("pause");
        }
        if (poprawne_logowanie.powodzenie_logowania == true)
            break;
    }
    return poprawne_logowanie;
}

dane_po_logowaniu pokaz_menu_logowania (vector <uzytkownik> &lista_uzytkownikow, vector <kontakt> &lista_kontaktow)
{
    int wybor_menu_logowania;
    dane_po_logowaniu poprawne_logowanie;
    while(true)
    {
        wczytaj_uzytkownikow_z_pliku(lista_uzytkownikow);
        system("cls");
        cout << "Ksiazka adresowa" << endl;
        cout << "___________________________________" << endl;
        cout << "Menu logowania: " << endl;
        cout << "1. Utworz nowe konto." << endl;
        cout << "2. Zaloguj. " << endl;
        cout << "9. Zakoncz program. " << endl;
        cout << endl;
        cout << endl;
        cout << "Wybierz opcje i zatwierdz enterem: " << endl;

        if (!(cin >> wybor_menu_logowania))
        {
            cout << "To nie jest liczba!" << endl;
            exit(0);
        }
        cout << endl;

        if (wybor_menu_logowania == 1)
            utworz_nowe_konto(lista_uzytkownikow);
        if (wybor_menu_logowania == 2)
        {
            poprawne_logowanie = zaloguj_uzytkownika(lista_uzytkownikow, lista_kontaktow);
            break;
        }
        if (wybor_menu_logowania == 9)
            exit (0);
    }
    return poprawne_logowanie;
}

int main()
{
    while(true)
    {
        dane_po_logowaniu poprawne_logowanie;
        vector <uzytkownik> lista_uzytkownikow;
        vector <kontakt> lista_kontaktow;
        poprawne_logowanie = pokaz_menu_logowania(lista_uzytkownikow, lista_kontaktow);
        if (poprawne_logowanie.powodzenie_logowania == true)
            pokaz_menu_glowne(lista_kontaktow, lista_uzytkownikow, poprawne_logowanie);
    }
    return 0;
}

/*
    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
    {
        cout << p -> id << "; " << p -> imie << "; " << p -> nazwisko << "; "<< p -> adres << "; "<< p -> nr_tel << "; "<< p -> email << endl;
    }
    system ("pause");


http://cpp0x.pl/dokumentacja/standard-C/remove/318
http://cpp0x.pl/dokumentacja/standard-C/rename/211
*/
