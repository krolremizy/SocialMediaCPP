#include <iostream>
#include "User.h"
#include <Windows.h>
#include <fstream>


using namespace std;

User User::Rejestracja(vector<User>uzytkownicy)
{
	User uzytkownik;

	system("cls");
	cout << "===REJESTRACJA===" << endl << endl;
	cout << "Witamy w rejestracji!" << endl;
	cout << "Najpierw prosimy o podanie swojego imienia: ";
	cin >> uzytkownik.m_name;
	cout << endl << "Teraz nazwisko: ";
	cin >> uzytkownik.m_surname;
	cout << endl << "Na koniec prosimy o login. Prosze go zapamietac! Login: ";
	cin >> uzytkownik.m_login;

	fstream pliktekstowy;
	pliktekstowy.open("uzytkownicy.txt", ios::app);
	pliktekstowy << uzytkownik.m_name << endl << uzytkownik.m_surname << endl << uzytkownik.m_login << endl;
	pliktekstowy.close();

	uzytkownicy.push_back(uzytkownik);

	return uzytkownik;
}
User User::Logowanie(vector<User>uzytkownicy)
{
	User zalogowany;
	string login_input;
	bool zmienna_tymcz = true;
	int numer;
	
	system("cls");
	cout << "===LOGOWANIE===" << endl << endl;
	cout << "Witamy w logowaniu!" << endl;
	while (zmienna_tymcz)
	{
		cout << "Prosze podac swoj login: ";
		cin >> login_input;
		for (int i = 0; i < uzytkownicy.size(); i++)
		{
			if (login_input == uzytkownicy[i].m_login)
			{
				zmienna_tymcz = false;
				numer = i;
			}
		}
		if (zmienna_tymcz == false)
		{
			zalogowany.m_name = uzytkownicy[numer].m_name;
			zalogowany.m_surname = uzytkownicy[numer].m_surname;
		}
		else cout << "Przepraszamy,  ale nie istnieje uzytkownik o podanym loginie"<<endl;
	}
	return zalogowany;
}

void User::czytajpliktekstowy(vector<User>& uzytkownicy)
{
	int numer_linijki = 1;
	User uzytkownik_2;
	string linijka;
	fstream pliktekstowy;
	pliktekstowy.open("uzytkownicy.txt");

	while (getline(pliktekstowy, linijka))
	{
		if (numer_linijki == 1) uzytkownik_2.m_name = linijka;
		else if (numer_linijki == 2) uzytkownik_2.m_surname = linijka;
		else if (numer_linijki == 3)
		{
			uzytkownik_2.m_login = linijka;
			numer_linijki = 0;
			uzytkownicy.push_back(uzytkownik_2);
		}
		numer_linijki++;
	}	
}

