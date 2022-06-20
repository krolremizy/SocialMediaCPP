#include <iostream>
#include "User.h"
#include "Posty.h"
#include "Komentarze.h"
#include "Oceny.h"
#include <vector>
#include "funkcje.h"
#include <Windows.h>

using namespace std;

vector<User>uzytkownicy;
vector<Posty>posty;
vector<int>numery_postow;
vector<int>numer_komentarze;
vector<Komentarze>komentarze;
vector<Oceny>oceny;



int main()
{

	User user;
	Posty post;
	Posty wybrany_post;
	Komentarze komentarz;
	Oceny ocena;
	bool wybor_logowanie = true, wybor_infoposty = true;
	string wybor1, wybor_menu, wybor2;

	user.czytajpliktekstowy(uzytkownicy); 
	post.WczytajPosty(posty);
	komentarz.WczytajKomentarze(komentarze, numer_komentarze);

	SocialMediaNapis();
	cout << endl << endl << "Witaj w programie Social Media, umozliwiajacym tworzenie uzytkownikow, dodawanie postow, komentowanie oraz ich ocenianie" << endl << endl;
	while (wybor_logowanie)
	{ 
		cout << "Instrukcja:" << endl << "##################################################" << endl << "- Aby zarejestrowac nowego uzytkownika, wpisz '1'." << endl << "- Aby sie zalogowac na istniejace konto, wpisz '2'." << endl << "- Aby opuscic program, wpisz '3'." << endl;
		cout << "##################################################" << endl;
		cout << "Co wybierasz?" << endl;
		cin >> wybor1;
		Sleep(1000);		
		
		if (wybor1 == "1")
		{
			uzytkownicy.push_back(user.Rejestracja(uzytkownicy));
			cout << endl << "Uzytkownik zarejestrowany!" << endl << endl;
			Chloszczysc(1000);
		}
		else if (wybor1 == "2")
		{
			user = user.Logowanie(uzytkownicy);
			wybor_logowanie = false;
		}
		else if (wybor1 == "3")
		{
			return 0;
		}
		else
		{
			cout << endl << "Wpisano zly numer!";
			Chloszczysc(1000);
		}	
	}
	system("cls");
	menuglowne:
	cout << endl << "Witaj " << user.m_name << " " << user.m_surname << endl << endl;

	cout << "===POSTY===" << endl << endl;
	posty.clear();
	post.WczytajPosty(posty);
	post.WyswietlPosty(posty, numery_postow);
	ocena.WczytajOceny(oceny, numery_postow);
	numer_komentarze.clear();
	komentarze.clear();
	komentarz.WczytajKomentarze(komentarze, numer_komentarze);
	ocena.WczytajOceny(oceny, numery_postow);
	cout << endl << "##################################################" << endl << endl;
	wybor_infoposty = true;
	while (wybor_infoposty)
	{
		cout << "Co chcesz teraz zrobic?" << endl << endl << "##################################################" << endl << endl << "INSTRUKCJA" << endl << endl;
		cout << "- Aby wyswietlic wiecej informacji o ktoryms poscie, wpisz '1'." << endl << "- Aby dodac nowy post, wpisz '2'." << endl;
		cout  << "- Aby opuscic program, wpisz '3'." << endl << endl << "##################################################" << endl << endl;
		cin >> wybor_menu;
		if (wybor_menu == "1")
		{
			goto menu_case1;
		}
		else if (wybor_menu == "2")
		{
			post.NowyPost(posty, user);
			Chloszczysc(1000);
			goto menuglowne;
		}
		else if (wybor_menu == "3")
		{
			return 0;
		}
		else
		{
			cout << "Wpisano zly numer!" << endl;
			Chloszczysc(1000);
			goto menuglowne;
		}

		menu_case1:
		wybrany_post = post.WyborPostaInformacje(numery_postow, posty);
		cout << "Oceny pozytywne: [" << oceny[wybrany_post.id_posta - 1].pozytywna_ocena << "]" << " Oceny negatywne: [" << oceny[wybrany_post.id_posta - 1].negatywna_ocena << "]" << endl << endl;
		cout << "===SEKCJA KOMENTARZY===" << endl << endl;
		int numer_k = 0;
		for (int k = 0; k < numer_komentarze.size(); k++)
		{
			if (wybrany_post.id_posta == numer_komentarze[k])
			{
				numer_k = k;

				cout << "[" << numer_komentarze[numer_k] << "] " << komentarze[numer_k].m_name << " " << komentarze[numer_k].m_surname << " pisze:" << endl << komentarze[numer_k].komentarz << endl << endl;
			}
		}
		cout << endl << "##################################################" << endl << endl << "Mozesz dodac nowy komentarz lub ocene" << endl << endl << "===INSTRUKCJA===" << endl << endl;
		cout << "- Aby skomentowac post, wpisz '1'." << endl << "- Aby ocenic post, wpisz '2'." << endl << "-Aby wrocic do menu glownego, wpisz '3'." << endl;
		cout << "Co wybierasz?" << endl;
		cin >> wybor2;
		Sleep(1000);
		if (wybor2 == "1")
		{
			komentarz.NowyKomentarz(uzytkownicy, wybrany_post, numer_komentarze, user);
			system("cls");
		}
		else if (wybor2 == "2")
		{
			ocena.NowaOcena(oceny, wybrany_post);
			system("cls");
		}
		else if (wybor2 == "3")
		{
			wybor_infoposty = false;
			goto menuglowne;
		}
		else
		{
			cout << "Wpisano zly numer!" << endl;
		}
	}
}
