#include <iostream>
#include <fstream>
#include "numerics.h"
#include "data.h"

int main(int argc, char const *argv[])
{

	double init[3][3][3] = {{{0,0,0},
						     {0,0,0},
							 {0,0,0}},
						
							{{0,0,0},
							 {0,0,0},
							 {0,5000,0}},
						
							{{0,0,0},
							 {0,0,0},
							 {5000,5000,5000}}};
	//init[body][acc/vel/pos][x,y,z]


	data n(init,3);

	n.play();

	n.write_datas();

	n.printData();


	return 0;
}