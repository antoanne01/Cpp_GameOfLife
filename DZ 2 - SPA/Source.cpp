#include <iostream>
#include <string>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;

	bool flag;
	do {
		the_game.draw();
		the_game.next_gen();

		cout << endl;
		cout << "Again (0/1): ";
		cin >> flag;

	} while (flag);

	return 0;
}