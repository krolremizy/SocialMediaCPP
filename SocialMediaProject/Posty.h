#pragma once
#include "User.h"
#include <vector>
class Posty
	: public User
{
public:

	std::string m_post;
	int id_posta;
	
	/**
	 * @brief 
	 * 
	 * 
	 * @param posty 
	 * @param user 
	 * @return 
	*/
	Posty NowyPost(std::vector<Posty>posty, User user);

	/**
	 * @brief 
	 * 
	 * 
	 * @param posty 
	 * @param numery_postow 
	 * @return 
	*/
	Posty WyswietlPosty(std::vector<Posty>& posty, std::vector<int>& numery_postow);

	/**
	 * @brief 
	 * 
	 * 
	 * @param numery_postow 
	 * @param posty 
	 * @return 
	*/
	Posty WyborPostaInformacje(std::vector<int>numery_postow, std::vector<Posty>posty);

	/**
	 * @brief 
	 * 
	 * 
	 * @param posty 
	*/
	void WczytajPosty(std::vector<Posty>& posty);
};
