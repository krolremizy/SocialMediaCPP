#pragma once
#include "Posty.h"
#include <vector>

class Oceny
	: public Posty
{
public:

	int id_oceny, pozytywna_ocena, negatywna_ocena;

	/**
	 * @brief 
	 * 
	 * 
	 * @param oceny 
	 * @param wybrany_post 
	*/
	void NowaOcena(std::vector<Oceny>& oceny, Posty wybrany_post);

	/**
	 * @brief 
	 * 
	 * 
	 * @param oceny 
	 * @param numery_postow 
	*/
	void WczytajOceny(std::vector<Oceny>& oceny, std::vector<int>numery_postow);
};

