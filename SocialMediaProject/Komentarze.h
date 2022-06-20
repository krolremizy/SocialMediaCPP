#pragma once
#include "Posty.h"
#include "Oceny.h"
#include "User.h"
#include <vector>

class Komentarze
	: public Posty
{
public:

	std::string komentarz;
	int id_komentarza;

	/**
	 * @brief 
	 * 
	 * 
	 * @param uzytkownicy 
	 * @param wybrany_post 
	 * @param numer_komentarze 
	 * @param user 
	 * @return 
	*/
	Komentarze NowyKomentarz(std::vector<User>uzytkownicy, Posty wybrany_post, std::vector<int>numer_komentarze, User user);

	/**
	 * @brief 
	 * 
	 * 
	 * @param komentarze 
	 * @param numer_komentarze 
	*/
	void WczytajKomentarze(std::vector<Komentarze>&komentarze, std::vector<int>&numer_komentarze);
};

