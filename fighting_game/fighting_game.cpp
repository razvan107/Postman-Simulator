#include "champion.h"
#include "Header.h"
using namespace std; 

int main()
{//			name hp dmg armor
	champion ashe("Ashe", 2000, 100, 22);
	champion darius("Darius", 2000, 100, 22);

	if (ashe.Fight(darius)) cout <<endl <<  ashe.Get_name()<< "wins";
					   else cout << endl << darius.Get_name() << " wins"; 
}