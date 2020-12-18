#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Header.h"
#ifndef Champ_h
#define Champ_h
class Champ
{
	string name;
	int health; int max_health;
	int base_damage;
	int armor;

	void	Set_health(int new_hp);
	void	Set_max_health(int new_max_hp);
	void	Set_base_damage(int new_base_damage);
	void	Set_armor(int new_armor);

	int		Get_health()const;
	int		Get_max_health()const;
	int		Get_base_damage()const;

	bool	Check_is_Dead();
	void	Check_health();

	void	Show_Fight_Intro(const Champ& enemy);
	void	Show_Fight_Intro(const Champ& enemy);
	void	Show_Round_Header(const Champ& enemy);
	void	Show_name()const;
	void	Show_health()const;
	void	Show_all()const;

	void	Play_Round(Champ& enemy, bool& round);
	bool	Select_Attack(Champ& enemy);
	void	Basic_attack(Champ& enemy);
	void	Self_heal(int i);
public:
	Champ(const string& name, int health, int base_damage, int armor);
	//string	Get_name() const;
	bool Fight(Champ& enemy);



};
#endif