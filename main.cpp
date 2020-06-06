#include <iostream>
//#include </home/lucas/Desktop/3body/jsoncpp/include/json/value.h>
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
							 {0,30,0}},
						
							{{0,0,0},
							 {0,0,0},
							 {30,30,30}}};
	//init[body][acc/vel/pos][x,y,z]


	data n(init,3);

	n.play();

	n.write_datas();

	//n.printData();


	return 0;
}