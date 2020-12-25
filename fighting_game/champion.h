#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
class champion {
private:
	string name;
	int health = 0; int max_health = 0;
	int base_damage = 0;
	int armor = 0;
#pragma region setters_getters_checkers_showers
	//SETTERS

	void	set_max_health	(int new_max_hp);
	void	set_base_damage	(int new_base_damage);
	void	set_armor		(int new_armor);

	//GETTERS

	int		get_max_health()	const;
	int		get_base_damage()	const;

	//AUTOMATIC ACTIONS

	bool	Select_Attack(champion& enemy);

	//ABILITIES/POWERS
	void	Basic_attack(champion& enemy);
	void	Self_heal(int i);

#pragma endregion
public:
	champion(const string& name, int health, int base_damage, int armor);
	champion();

	void	set_health(int new_hp);
	void	set_name(string new_name);

	int		get_health()		const;
	const string& get_name() const;

	void	Check_health();
	bool	Check_is_Dead();

	void	Play_Round(champion& enemy, bool& round);

	string	Make_Fighter_Header(const champion& enemy);
	string	Make_Action_Header(const champion& enemy);
	void	show_name()const;
	void	show_health()const;
	string	show_all()const;

};


