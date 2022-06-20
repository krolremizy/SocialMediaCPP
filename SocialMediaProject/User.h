#pragma once
#include <string>
#include <vector>

class User
{
public:
	std::string m_name, m_surname, m_login;

	User Rejestracja(std::vector<User>uzytkownicy);

	User Logowanie(std::vector<User>uzytkownicy);

	void czytajpliktekstowy(std::vector<User>& uzytkownicy);
};

