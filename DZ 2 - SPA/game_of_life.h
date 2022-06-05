#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int cols = 40;
	static const unsigned int rows = 20;
	bool gen[rows][cols];
	bool _next_gen[rows][cols];
	bool random_num();
	bool cell_occupied(int i, int j);
	void init();
	bool lifeDeath(int i, int j);
	bool birth(int i, int j);

public:
	game_of_life();
	void next_gen();
	void draw();
	int r_num(int min, int max);

};