#include <iostream>
#include <fstream>
#include "Komentarze.h"
#include "Oceny.h"

using namespace std;


Komentarze Komentarze::NowyKomentarz(vector<User>uzytkownicy, Posty wybrany_post, vector<int>numer_komentarze, User user)
{
	string tresc_komentarza;
	char publikacja;
	Komentarze nowy_komentarz;
	
		system("cls");
		
		cout << "Skomentuj post (pamietaj, zeby konczyl sie kropka '.'!): ";
		getline(cin, tresc_komentarza, '.');
		cout << tresc_komentarza<<endl<<endl<<"Czy chcesz go opublikowac?" << endl << "Jesli tak, kliknij litere 't', jesli nie, to inna" << endl;
		cin >> publikacja;
		if (publikacja == 't')
		{
			fstream pliktekstowy;
			pliktekstowy.open("uz_komentarze.txt", ios::app);
			pliktekstowy << wybrany_post.id_posta << endl << user.m_name << endl << user.m_surname << tresc_komentarza << endl;
			pliktekstowy.close();
			nowy_komentarz.komentarz = tresc_komentarza;
			numer_komentarze.push_back(wybrany_post.id_posta);
			cout << "Komentarz zostal opublikowany!";
		}
		else cout << "Komentarz nie zostal opublikowany"<<endl;
	return nowy_komentarz;
}
void Komentarze::WczytajKomentarze(vector<Komentarze>&komentarze, vector<int>&numer_komentarze)
{
	string linijka;
	int numer_linijki=1;
	Komentarze wczyt_komentarze;

	fstream pliktekstowy;
	pliktekstowy.open("uz_komentarze.txt");
	while (getline(pliktekstowy, linijka))
	{
		if (numer_linijki == 1)
		{
			wczyt_komentarze.id_komentarza = stoi(linijka);
			numer_komentarze.push_back(wczyt_komentarze.id_komentarza);
		}
		else if (numer_linijki == 2) wczyt_komentarze.m_name = linijka;
		else if (numer_linijki == 3) wczyt_komentarze.m_surname = linijka;
		else if (numer_linijki == 4)
		{
			wczyt_komentarze.komentarz = linijka;
			numer_linijki = 0;
			komentarze.push_back(wczyt_komentarze);
		}
		numer_linijki++;
	}
}



