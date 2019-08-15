#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>

using namespace std;

struct kontakt
{
    int id;
    string imie;
    string nazwisko;
    string adres;
    string nr_tel;
    string email;
};

void dodaj_kontakt (vector <kontakt> lista_kontaktow)
{
    int id;
    string imie;
    string nazwisko;
    string adres;
    string nr_tel;
    string email;

    if (lista_kontaktow.size()==0)
    {
        id = 1;
    }
    else
    {
        vector<kontakt>::iterator  itr = lista_kontaktow.end()-1;
        id = (itr -> id) + 1;
    }

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
    fstream plik_kontaktow;
    string linia_tekstu_w_pliku;
    string tekst_tymczasowy;
    int licznik_kresek = 0;
    int dlugosc;
    char znak;

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
                    osoba.imie = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 3:
                    osoba.nazwisko = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 4:
                    osoba.adres = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 5:
                    osoba.nr_tel = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                case 6:
                    osoba.email = tekst_tymczasowy;
                    tekst_tymczasowy = "";
                    break;
                }
            }
        }
        licznik_kresek = 0;
        lista_kontaktow.push_back(osoba);
    }
    plik_kontaktow.close ();
}

int main()
{
    while(true)
    {
        vector <kontakt> lista_kontaktow;
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
    return 0;
}
/*
    for (vector<kontakt>::iterator p = lista_kontaktow.begin(); p != lista_kontaktow.end(); p++)
    {
        cout << p -> id << "; " << p -> imie << "; " << p -> nazwisko << "; "<< p -> adres << "; "<< p -> nr_tel << "; "<< p -> email << endl;
    }
    system ("pause");
    */
