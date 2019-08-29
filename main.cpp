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

int pokaz_id_ostatniego_rekordu()
{
    string linia_tekstu;
    string ostatnia_linia_tekstu;
    string id_str;
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
    ostatnia_linia_tekstu = linia_tekstu;
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

void dodaj_kontakt (vector <kontakt> lista_kontaktow)
{
    int id;
    string imie;
    string nazwisko;
    string adres;
    string nr_tel;
    string email;
    string id_uzytkownika;

    if (lista_kontaktow.size()==0)
        id = 1;
    else
    {
        id = pokaz_id_ostatniego_rekordu() + 1;
    }

    fstream plik_zalogowany_uzytkownik;
    plik_zalogowany_uzytkownik.open("zalogowany_uzytkownik.txt", ios::in);
    if(plik_zalogowany_uzytkownik.good()==false) cout<<"Nie mozna otworzyc pliku!";
    getline(plik_zalogowany_uzytkownik, id_uzytkownika);
    plik_zalogowany_uzytkownik.close();

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

    plik_kontaktow << id << "|";
    plik_kontaktow << id_uzytkownika << "|";
    plik_kontaktow << imie << "|";
    plik_kontaktow << nazwisko << "|";
    plik_kontaktow << adres << "|";
    plik_kontaktow << nr_tel<< "|";
    plik_kontaktow << email << "|" << endl;

    plik_kontaktow.close();

    cout << "___________________________________________" << endl;
    cout << "Kontakt dodany!" << endl;
    system("pause");
}

void wyszukaj_w_kontaktach (vector <kontakt> lista_kontaktow)
{
    int wybor_przy_wyszukiwaniu;
    string poszukiwana_fraza;
    system ("cls");
    cout << "1. Wyszukuj po imieniu" << endl;
    cout << "2. Wyszukuj po nazwisku" << endl;
    cout << "____________________________________" << endl;
    cout << "Wybierz opcje i zatwierdz enterem: ";
    cin >> wybor_przy_wyszukiwaniu;

    if (wybor_przy_wyszukiwaniu == 1)
    {
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
        {
            cout << "Nie istnieje taki kontakt." << endl;
        }
        else
        {
            cout << endl;
            cout << "________________________________________________________________" << endl;
            cout << "Znaleziono " << licznik_spelnienia_warunku << " rekordow." << endl;
        }

        system("pause");
    }

    if (wybor_przy_wyszukiwaniu == 2)
    {
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
        {
            cout << "Nie istnieje taki kontakt." << endl;
        }
        else
        {
            cout << endl;
            cout << "________________________________________________________________" << endl;
            cout << "Znaleziono " << licznik_spelnienia_warunku << " rekordow." << endl;
        }

        system("pause");
    }
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

void edytuj_kontakt ( vector <kontakt> lista_kontaktow)
{
    system ("cls");
    int id;
    int wybor_danej;
    string imie, nazwisko, adres, telefon, email;
    int licznik_spelnienia_warunku = 0;

    cout << "Podaj ID kontaktu, ktory chcesz edytowac: ";
    cin >> id;
    cout << "___________________________________________" << endl;

    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
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
            cout << "Wybierz dana, ktora ma zostac zmieniona: ";
            cin >> wybor_danej;

            switch (wybor_danej)
            {
            case 1:
                cout << "Podaj nowe imie: ";
                cin >> imie;
                p -> imie = imie;
                break;
            case 2:
                cout << "Podaj nowe nazwisko: ";
                cin >> nazwisko;
                p -> nazwisko = nazwisko;
                break;
            case 3:
                cout << "Podaj nowy adres: ";
                cin >> adres;
                p -> adres = adres;
                break;
            case 4:
                cout << "Podaj nowy numer telefonu: ";
                cin >> telefon;
                p -> nr_tel = telefon;
                break;
            case 5:
                cout << "Podaj nowy adres email: ";
                cin >> email;
                p -> email = email;
                break;
            }
        }
    }

    if (licznik_spelnienia_warunku == 0)
        cout << "Nie istnieje kontakt o takim ID." <<endl;
    else
    {
        fstream plik_kontaktow;
        plik_kontaktow.open("plik_kontaktow.txt", ios::out);
        for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
        {
            plik_kontaktow << p -> id << "|";
            plik_kontaktow << p -> imie << "|";
            plik_kontaktow << p -> nazwisko << "|";
            plik_kontaktow << p -> adres << "|";
            plik_kontaktow << p -> nr_tel<< "|";
            plik_kontaktow << p -> email << "|" << endl;
        }
    }
    system ("pause");
}

void usun_kontakt ( vector <kontakt> lista_kontaktow)
{
    system ("cls");
    int id;
    int wybor_danej;
    char decyzja;
    int numer_linii = 0;
    int licznik_spelnienia_warunku = 0;

    cout << "Podaj ID kontaktu, ktory chcesz usunac: ";
    cin >> id;
    cout << "___________________________________________" << endl;

    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); ++p)
    {
        numer_linii++;
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
            cout << "Czy na pewno chcesz usunac wyswitlony kontatkt? (t/n) ";
            cin >> decyzja;

            if (decyzja == 't')
            {
                if (numer_linii == lista_kontaktow.size())
                {
                    p = lista_kontaktow.begin();
                    lista_kontaktow.pop_back();
                }
                else
                    lista_kontaktow.erase(lista_kontaktow.begin() + (numer_linii - 1));
            }

            else if (decyzja == 'n')
                break;
        }
    }
    if (licznik_spelnienia_warunku == 0)
        cout << "Nie istnieje kontakt o takim ID." <<endl;
    else
    {
        fstream plik_kontaktow;
        plik_kontaktow.open("plik_kontaktow.txt", ios::out);
        for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); ++p)
        {
            plik_kontaktow << p -> id << "|";
            plik_kontaktow << p -> imie << "|";
            plik_kontaktow << p -> nazwisko << "|";
            plik_kontaktow << p -> adres << "|";
            plik_kontaktow << p -> nr_tel<< "|";
            plik_kontaktow << p -> email << "|" << endl;
        }
    }
    system ("pause");
}

void wczytaj_kontakty_z_pliku(vector <kontakt> &lista_kontaktow)
{
    string linia_tekstu_w_pliku;
    string tekst_tymczasowy;
    string id_uzytkownika;
    int id_uzytkownika_int;
    int licznik_kresek = 0;
    int dlugosc;
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

        fstream plik_zalogowany_uzytkownik;
        plik_zalogowany_uzytkownik.open("zalogowany_uzytkownik.txt", ios::in);
        if(plik_zalogowany_uzytkownik.good()==false) cout<<"Nie mozna otworzyc pliku!";
        getline(plik_zalogowany_uzytkownik, id_uzytkownika);
        plik_zalogowany_uzytkownik.close();

        id_uzytkownika_int = atoi(id_uzytkownika.c_str());

        if (id_uzytkownika_int == osoba.id_uzytkownika)
        lista_kontaktow.push_back(osoba);
    }
    plik_kontaktow.close ();
}

void pokaz_menu_glowne(vector <kontakt> &lista_kontaktow)
{
    while(true)
    {
        lista_kontaktow.clear();
        wczytaj_kontakty_z_pliku(lista_kontaktow);
        int wybor_menu_glownego;
        system("cls");
        cout << "Ksiazka adresowa" << endl;
        cout << "___________________________________" << endl;
        cout << "Menu glowne: " << endl;
        cout << "1. Dodaj kontakt." << endl;
        cout << "2. Wyszukaj kontakt. " << endl;
        cout << "3. Wypisz liste wszystkich kontaktow. " << endl;
        cout << "4. Edytuj kontakt. " << endl;
        cout << "5. Usun kontakt. " << endl;
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
            dodaj_kontakt(lista_kontaktow);
        if (wybor_menu_glownego == 2)
            wyszukaj_w_kontaktach(lista_kontaktow);
        if (wybor_menu_glownego == 3)
            wypisz_wszystko(lista_kontaktow);
        if (wybor_menu_glownego == 4)
            edytuj_kontakt(lista_kontaktow);
        if (wybor_menu_glownego == 5)
            usun_kontakt(lista_kontaktow);
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

void zaloguj_uzytkownika(vector <uzytkownik> &lista_uzytkownikow, vector <kontakt> &lista_kontaktow)
{
    string nazwa_u;
    string haslo_u;
    int liczba_spelnienia_warunku = 0;
    system("cls");
    cout << "Ekran logowania." << endl;
    cout << "___________________________________________" << endl;
    cout << "Podaj nazwe uzytkownika: ";
    cin.sync();
    getline(cin, nazwa_u);

    for (vector<uzytkownik>::iterator p = lista_uzytkownikow.begin(); p != lista_uzytkownikow.end(); p++)
    {
        if (p -> nazwa == nazwa_u)
        {
            liczba_spelnienia_warunku ++;
            for (int i = 3; i > 0; i--)
            {
                cout << "Pozostalo prob: " << i <<endl;
                cout << "Podaj haslo: ";
                cin.sync();
                getline(cin, haslo_u);

                if (p -> haslo == haslo_u)
                {
                fstream plik_zalogowany_uzytkownik;
                plik_zalogowany_uzytkownik.open("zalogowany_uzytkownik.txt",ios::out);
                plik_zalogowany_uzytkownik << p -> id;
                plik_zalogowany_uzytkownik.close();
                pokaz_menu_glowne(lista_kontaktow);
                }
                else
                {
                    cout << "Niepoprawne haslo.";
                }
            }
            system("cls");
            for (int i = 5; i >=0; i--)
            {
                cout << "Ponowne logowanie mozliwe za: " << i << "s";
                Sleep(1000);
                system("cls");
            }
            break;
        }
    }
    if (liczba_spelnienia_warunku == 0)
    {
    cout << "Nie ma takiego uzytkownika w bazie" << endl;
    system("pause");
    }
}

void pokaz_menu_logowania(vector <uzytkownik> &lista_uzytkownikow, vector <kontakt> &lista_kontaktow)
{
    int wybor_menu_logowania;

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
        {
            utworz_nowe_konto(lista_uzytkownikow);
        }
        if (wybor_menu_logowania == 2)
        {
            zaloguj_uzytkownika(lista_uzytkownikow, lista_kontaktow);
        }
        if (wybor_menu_logowania == 9)
        {
            exit (0);
        }
    }
}

int main()
{
    vector <uzytkownik> lista_uzytkownikow;
    vector <kontakt> lista_kontaktow;
    pokaz_menu_logowania(lista_uzytkownikow, lista_kontaktow);

    return 0;
}


/*
    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
    {
        cout << p -> id << "; " << p -> imie << "; " << p -> nazwisko << "; "<< p -> adres << "; "<< p -> nr_tel << "; "<< p -> email << endl;
    }
    system ("pause");
*/

/*
http://cpp0x.pl/dokumentacja/standard-C/remove/318
http://cpp0x.pl/dokumentacja/standard-C/rename/211
*/
