#include "champion.h"

using namespace std;
#pragma region setters_getters_checkers_showers
void	champion::Set_health(int new_hp)
{
	health = new_hp;

	Check_health();
}
//SETTERS
void	champion::Set_max_health(int new_max_hp)
{
	max_health = new_max_hp;
}
void	champion::Set_base_damage(int new_base_damage)
{
	base_damage = new_base_damage;
}
void	champion::Set_armor(int new_armor)
{
	armor = new_armor;
}

//GETTERS
int		champion::Get_health()		const  { return health;		}
void	champion::Set_name(string new_name){ name = new_name;	}
int		champion::Get_max_health()	const  { return max_health; }
int		champion::Get_base_damage()	const  { return base_damage;}
string	champion::Get_name()		const  { return name;		}


//CHECKERS
void	champion::Check_health()
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
bool	champion::Check_is_Dead()
{
	if (Get_health() == 0) return 1; // if health is 0, return false (not alive)
	return 0;
}
//SHOWERS
string	champion::Show_Fight_Intro (const champion& enemy)
{return name + " fights " + enemy.name;}
string	champion::Show_Round_Header(const champion& enemy)
{
	cout << endl << name << " picks an action against " << enemy.name << endl;
	return name + " picks an action against " + enemy.name;
}
void	champion::Show_name()		const
{
	cout << "name: " << name << endl;
}
void	champion::Show_health()		const
{
	cout << name << " health: " << health << "\\" << max_health << endl;
}
string	champion::Show_all()		const
{
	return Get_name()+ "'s Health: " + to_string(Get_health()) + "/" + to_string( Get_max_health());
}
#pragma endregion
//AUTOMATIC ACTIONS
void	champion::Play_Round(champion& enemy, bool& round)
{
	//CONSOLE					//WINDOW
	Show_Round_Header(enemy);	
	bool x = Select_Attack(enemy);
	if (x) round = !round;
}
bool	champion::Select_Attack(champion& enemy)
{
	cout << endl
		<< "1: Basic Attack" << endl
		<< "2: " << endl
		<< "3: " << endl
		<< "4: Self heal" << endl
		<< "5: Show implicit stats" << endl;
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
void	champion::Basic_attack(champion& enemy)
{
	enemy.Set_health(enemy.health - base_damage);
	cout << name << " dealt " << base_damage << " to " << enemy.name << endl;
};
void	champion::Self_heal(int i)
{
	cout << name << " healed for " << i << " health.";
	Set_health(health + i);
}


	champion::champion(string& name, int health, int base_damage, int armor)
	{
		this->name = name;
		this->health = health;
		this->base_damage = base_damage;
		this->armor = armor;
		max_health = health;
	}
	champion::champion()
	{
	}
