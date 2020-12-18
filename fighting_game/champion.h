#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
class champion {
private:
	string name;
	int health; int max_health;
	int base_damage;
	int armor;
#pragma region setters_getters_checkers_showers
	//SETTERS
	void	Set_health		(int new_hp);
	void	Set_max_health	(int new_max_hp);
	void	Set_base_damage	(int new_base_damage);
	void	Set_armor		(int new_armor);

	//GETTERS
	int		Get_health()		const;
	int		Get_max_health()	const;
	int		Get_base_damage()	const;



	//CHECKERS

	//SHOWERS

	//AUTOMATIC ACTIONS

	bool	Select_Attack(champion& enemy);

	//ABILITIES/POWERS
	void	Basic_attack(champion& enemy);
	void	Self_heal(int i);

#pragma endregion
public:
	void	Check_health();
	bool	Check_is_Dead();

	void	Play_Round(champion& enemy, bool& round);

	void	Show_Fight_Intro(const champion& enemy);
	void	Show_Round_Header(const champion& enemy);
	void	Show_name()const;
	void	Show_health()const;
	void	Show_all()const;

	champion(const string& name, int health, int base_damage, int armor);
	string	Get_name() const;
};


