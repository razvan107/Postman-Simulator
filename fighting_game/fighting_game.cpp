#include <stdlib.h>
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

class champ {
	string name;
	int health; int max_health;
	int base_damage;
	int armor;
#pragma region setters_getters_checkers_showers
	void	Set_health(int new_hp)
	{
		health = new_hp;

		Check_health();
	}
	//SETTERS
	void	Set_max_health(int new_max_hp)
	{
		max_health = new_max_hp;
	}
	void	Set_base_damage(int new_base_damage)
	{
		base_damage = new_base_damage;
	}
	void	Set_armor(int new_armor)
	{
		armor = new_armor;
	}

	//GETTERS
	int		Get_health()		const{return health;}
	int		Get_max_health()	const{return max_health;}
	int		Get_base_damage()	const{return base_damage;}



	//CHECKERS
	void	Check_health()
	{
		if (health <= 0)
		{
			health = 0;
		}
		else if (health >= max_health)
		{
			health = max_health;
		}
	}
	bool	Check_is_Dead()
	{
		if (Get_health() == 0) return 1; // if health is 0, return false (not alive)
		return 0;
	}
	//SHOWERS
	void	Show_Fight_Intro(const champ& enemy)
	{
		cout << name << " fights " << enemy.name << endl << "____________________________________________"  <<"\n" << endl << endl;
		
	}
	void	Show_Round_Header(const champ& enemy)
	{
		cout  <<endl <<  name<< " picks an action against "<< enemy.name <<  endl;
	}
	void	Show_name()const
	{
		cout << "name: " << name << endl;
	}
	void	Show_health()const
	{
		cout << name << " health: " << health << "\\" << max_health << endl;
	}
	void	Show_all()const
	{
		cout << name << " Health: " << Get_health() << "/" << Get_max_health();
		
	}
	//AUTOMATIC ACTIONS
	void	Play_Round(champ& enemy,bool& round)
	{
		Show_Round_Header(enemy);
		bool x = Select_Attack(enemy);
		if (x) round = !round;
	}
	bool	Select_Attack(champ& enemy)
	{
		cout << endl 
		<<"1: Basic Attack" << endl
		<<"2: " << endl
		<<"3: " << endl
		<<"4: Self heal" << endl
		<<"5: Show implicit stats" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Basic_attack(enemy);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			Self_heal(1);
			break;
		case 5:
			Show_all();
			cout << endl;
			enemy.Show_all();
			return 1; //1 = flip the bool to keep round intact
		}
		return 0;
	}

	//ABILITIES/POWERS
	void	Basic_attack(champ& enemy)
	{
		enemy.Set_health(enemy.health - base_damage);
		cout << name << " dealt " << base_damage << " to " << enemy.name << endl;
	};
	void	Self_heal(int i)
	{
		cout << name << " healed for " << i << " health.";
		Set_health(health + i);
	}
	
#pragma endregion
public:
	champ(const string& name, int health, int base_damage, int armor)
	{
		this->name = name;
		this->health = health;
		this->base_damage = base_damage;
		this->armor = armor;
		max_health = health;

	}
	string	Get_name() const
	{
		return name;
	}
	bool Fight(champ& enemy)
	{
		bool round = 1;
		bool roundCount = 1;
		Show_Fight_Intro(enemy);
		wait(1);
		while (true)
		{
			if (round) Play_Round(enemy, round); //chose who actions
			else enemy.Play_Round(*this, round);
			

			wait(2);
			system("CLS");

			Show_all();		enemy.Show_all();



			if (Check_is_Dead()) return 1;		//anyone dead?
			else if (enemy.Check_is_Dead()) return 0;
			round = !round; roundCount++;
		}				
	}
};

int main()
{//			name hp dmg armor
	champ ashe("Ashe", 2000, 100, 22);
	champ darius("Darius", 2000, 100, 22);

	if (ashe.Fight(darius)) cout <<endl <<  ashe.Get_name()<< "wins";
					   else cout << endl << darius.Get_name() << " wins"; 
}