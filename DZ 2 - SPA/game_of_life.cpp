#include "game_of_life.h"
#include <ctime>


int game_of_life::r_num(int min, int max) {

	return rand() % (max - min + 1) + min;
}

bool game_of_life::random_num()
{
	if (r_num(1, 4) == 2)
		return true;
	else
		return false;
}

bool game_of_life::cell_occupied(int i, int j)
{
	if (this->gen[i][j] == true)
		return true;
	else
		return false;
}

void game_of_life::init()
{
	int level;

	do {

		level = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (random_num()) {
					this->gen[i][j] = 1;
					level++;
				}
				else {
					this->gen[i][j] = 0;
				}
			}
		}

	} while (!(level == ((rows * cols) / 4)));

}

bool game_of_life::lifeDeath(int i, int j)
{
	int counter = 0;
	if ((i - 1) >= 0 && (j - 1) >= 0) {
		if (this->gen[i - 1][j - 1] == 1)
			counter++;
	}
	if ((i - 1) >= 0) {
		if (this->gen[i - 1][j] == 1)
			counter++;
	}
	if ((i - 1) >= 0 && (j + 1) < cols) {
		if (this->gen[i - 1][j + 1] == 1)
			counter++;
	}
	if ((j - 1) >= 0) {
		if (this->gen[i][j - 1] == 1)
			counter++;
	}
	if ((j + 1) < cols) {
		if (this->gen[i][j + 1] == 1)
			counter++;
	}
	if ((i + 1) < rows && (j - 1) >= 0) {
		if (this->gen[i + 1][j - 1] == 1)
			counter++;
	}
	if ((i + 1) < rows) {
		if (this->gen[i + 1][j] == 1)
			counter++;
	}
	if ((i + 1) < rows && (j + 1) < cols) {
		if (this->gen[i + 1][j + 1] == 1)
			counter++;
	}

	if (counter == 2 || counter == 3)
		return true;
	else
		return false;
}

bool game_of_life::birth(int i, int j)
{
	int counter = 0;
	if ((i - 1) >= 0 && (j - 1) >= 0) {
		if (this->gen[i - 1][j - 1] == 1) {
			counter++;
		}
	}
	if ((i - 1) >= 0) {
		if (this->gen[i - 1][j] == 1)
			counter++;
	}
	if ((i - 1) >= 0 && (j + 1) < cols) {
		if (this->gen[i - 1][j + 1] == 1)
			counter++;
	}
	if ((j - 1) >= 0) {
		if (this->gen[i][j - 1] == 1)
			counter++;
	}
	if ((j + 1) < cols) {
		if (this->gen[i][j + 1] == 1)
			counter++;
	}
	if ((i + 1) < rows && (j - 1) >= 0) {
		if (this->gen[i + 1][j - 1] == 1)
			counter++;
	}
	if ((i + 1) < rows) {
		if (this->gen[i + 1][j] == 1)
			counter++;

	}
	if ((i + 1) < rows && (j + 1) < cols) {
		if (this->gen[i + 1][j + 1] == 1)
			counter++;
	}

	if (counter == 3) {
		return true;
	}
	else {
		return false;
	}
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	init();
}

void game_of_life::next_gen()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (cell_occupied(i, j)) {
				if (lifeDeath(i, j)) {
					this->_next_gen[i][j] = this->gen[i][j];
				}
				else {
					this->_next_gen[i][j] = 0;
				}
			}
			else {
				if (birth(i, j)) {
					this->_next_gen[i][j] = 1;
				}
				else {
					this->_next_gen[i][j] = this->gen[i][j];
				}
			}
		}
	}
}

void game_of_life::draw()
{
	next_gen();

	for (int i = 0; i < rows; i++) {
		cout << endl;
		for (int j = 0; j < cols; j++) {
			if (this->gen[i][j]) {
				cout << "*";
			}
			else {
				cout << "-";
			}
			this->gen[i][j] = this->_next_gen[i][j];
		}
	}
}