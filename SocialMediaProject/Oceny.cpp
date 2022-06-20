#include <iostream>
#include "Oceny.h"
#include "Komentarze.h"
#include <fstream>
#include <string>

using namespace std;

void Oceny::WczytajOceny(vector<Oceny>& oceny, vector<int>numery_postow)
{
	string linijka;
	int numer_linijki=1, numerPosta = 0;
	Oceny wczyt_oceny;
	ifstream pliktekstowy;
	oceny.clear();
	for(int i=0;i<numery_postow.size();i++)
	{
		wczyt_oceny.pozytywna_ocena = 0;
		wczyt_oceny.negatywna_ocena = 0;
		oceny.push_back(wczyt_oceny);
	}
	pliktekstowy.open("uz_oceny.txt", ios::in);
	while (getline(pliktekstowy, linijka))
	{
		if (numer_linijki == 1)
		{
			wczyt_oceny.pozytywna_ocena = stoi(linijka);
		}
		else if (numer_linijki == 2)
		{
			wczyt_oceny.negatywna_ocena = stoi(linijka);
			oceny[numerPosta].pozytywna_ocena = wczyt_oceny.pozytywna_ocena;
			oceny[numerPosta].negatywna_ocena = wczyt_oceny.negatywna_ocena;
			numer_linijki = 0;
			numerPosta++;
		}
		numer_linijki++;
	}
	pliktekstowy.clear();
	pliktekstowy.close();
}
void Oceny::NowaOcena(vector<Oceny>& oceny, Posty wybrany_post)
{
	string wybor_ocena;
	string linijka;
	Oceny ocenka;
	Oceny ocena_push;
	int numer_linijki = 1;
	bool zmienna_tymcz = true;
	system("cls");
	cout << "Jaka ocene chcialbys dodac postowi?" << endl << "Jesli pozytywna, wpisz 'pozytywna', a jesli negatywna, to wpisz 'negatywna'";
	while (zmienna_tymcz)
	{
		cout << "Co robimy?: "; 
				cin >> wybor_ocena;
				if (wybor_ocena == "pozytywna")
				{
					oceny[wybrany_post.id_posta-1].pozytywna_ocena += 1;
					zmienna_tymcz = false;
				}
				else if (wybor_ocena == "negatywna")
				{
					oceny[wybrany_post.id_posta-1].negatywna_ocena += 1;
					zmienna_tymcz = false;
				}
				else
				{
					cout << "Wpisano zle slowo!" << endl;
				}
				if (zmienna_tymcz == false)
				{
					ofstream pliktekstowy;
					pliktekstowy.open("uz_oceny.txt");
					for (int i = 0; i < oceny.size(); i++)
					{
						pliktekstowy << oceny[i].pozytywna_ocena << endl << oceny[i].negatywna_ocena << endl;
					}
					pliktekstowy.close();
				}
	}
}
