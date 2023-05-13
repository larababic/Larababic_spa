#include <iostream>
#include <windows.h>
#include <sstream>
#include "game_of_life.h"

using namespace std;

int main() {

	game_of_life g;

	while (true)
	{
		cout << g.iscrtaj() << endl;
		g.sljedeca_generacija();
		Sleep(200);
	}


	return 0;
}