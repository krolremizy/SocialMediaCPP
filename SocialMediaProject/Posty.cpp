#include <iostream>
#include <windows.h>
#include <string>
#include "Posty.h"
#include <fstream>

using namespace std;

Posty Posty::NowyPost(vector<Posty>posty, User user)
{
	string tresc_posta;
	char publikacja;
	Posty nowy_post;
	system("cls");
	cout << "Co ci chodzi po glowie? Napisz swoj post!" << endl << "Pamietaj, ze musi sie on konczyc znakiem kropka '.'" << endl << endl;
	getline(cin, tresc_posta, '.');
	system("cls");
	cout << tresc_posta << endl << endl << "Czy chcesz opublikowac tego posta?" << endl << "Jesli tak, kliknij litere 't', jesli nie, to inna" << endl;
	cin >> publikacja;
	
	if (publikacja == 't')
	{
		fstream pliktekstowy;
		pliktekstowy.open("uz_posty.txt", ios::app);
		pliktekstowy << user.m_name << endl << user.m_surname << tresc_posta << endl;
		pliktekstowy.close();
		cout << endl << "Post zostal opublikowany!";
		nowy_post.m_name = user.m_name;
		nowy_post.m_surname = user.m_surname;
		nowy_post.m_post = tresc_posta;
		posty.push_back(nowy_post);
	}
	else
	{
		cout << "Post nie zostal opublikowany";
	}
	return nowy_post;
}
void Posty::WczytajPosty(vector<Posty>& posty)
{
	string linijka;
	int numer_linijki = 1;
	Posty wczyt_posty;

	fstream pliktekstowy;
	pliktekstowy.open("uz_posty.txt");
	while (getline(pliktekstowy, linijka))
	{
		if (numer_linijki == 1)
		{
			wczyt_posty.m_name = linijka;
		}
		else if (numer_linijki == 2)
		{
			wczyt_posty.m_surname = linijka;
		}
		else if (numer_linijki == 3)
		{
			wczyt_posty.m_post = linijka;
			numer_linijki = 0;
			posty.push_back(wczyt_posty);
		}
		numer_linijki++;
	}
}
Posty Posty::WyswietlPosty(vector<Posty>&posty,vector<int>&numery_postow)
{
	string linijka;
	int numer_linijki = 1;
	Posty wczyt_posty;
	Posty tresc_posta;

	for (int i = 0; i < posty.size(); i++)
	{
		id_posta = i;
		cout <<'['<<id_posta+1<<']'<<" "<< posty[i].m_name << " " <<posty[i].m_surname << endl << posty[i].m_post << endl;
		tresc_posta.m_post = posty[i].m_post;
		numery_postow.push_back(id_posta+1);
	}
	return tresc_posta;
}
Posty Posty::WyborPostaInformacje(vector<int>numery_postow, vector<Posty>posty)
{
	int wybor_posta;
	bool zmienna_tymcz = true;
	int numer_i = 0;
	int numer_k = 0;
	Posty wybrany_post;
	cout << "Na temat ktorego posta chcialbys wyswietlic wiecej informacji?" << endl;;
	while (zmienna_tymcz)
	{
		cout << "Numer posta: ";
		cin >> wybor_posta;
		if (wybor_posta > numery_postow.size())
		{
			cout << "Nie ma posta o takim numerze" << endl;
		}
		else zmienna_tymcz = false;
	}
	if (zmienna_tymcz == false)
	{
		for (int i = 0; i < posty.size(); i++)
		{
			if (wybor_posta ==numery_postow[i])
			{
				numer_i = i;
			}
		}
		system("cls");
		cout << "[" << numery_postow[numer_i] << "] " << posty[numer_i].m_name << " " << posty[numer_i].m_surname << endl << posty[numer_i].m_post << endl << endl;

	}
	wybrany_post.id_posta = numery_postow[numer_i];
	return wybrany_post;
}
