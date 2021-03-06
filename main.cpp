#include <iostream>
#include <fstream>
#include <cmath>
#include "numerics.h"
#include "data.h"

int main(int argc, char const *argv[])
{
	double vel_x;
	double vel_y;
	double vel_z;
	double pos_x;
	double pos_y;
	double pos_z;

	int bodies = 5;
	int i,j;
	//double ai[bodies][3];
	double vi[bodies][3];
	double xi[bodies][3];
	double init[bodies][2][3];

	//sun
	i = 0;
	//input distance in astronomical units (au)
	//input speed as au/day
	// ai[i][0] = 0;
	// ai[i][1] = 0;
	// ai[i][2] = 0;
	vi[i][0] = 0;
	vi[i][1] = 0;
	vi[i][2] = 0;
	xi[i][0] = 0;
	xi[i][1] = 0;
	xi[i][2] = 0;

	//mercury
	i++;
	vel_x = 1.450098838504057E-02;
	vel_y = -1.827392737866101E-02;
	vel_z = -2.823480785896841E-03;
	pos_x = -3.124921389426347E-01;
	pos_y = -3.231017308099852E-01;
	pos_z = 2.264004677880896E-03;
	// radius = 4.495010467958139E-01;

	vi[i][0] = vel_x;
	vi[i][1] = vel_y;
	vi[i][2] = vel_z;
	xi[i][0] = pos_x;
	xi[i][1] = pos_y;
	// xi[i][2] = pos_z;

	//venus
	i++;
	vel_x =  2.005150325251360E-02;
	vel_y = -1.338183192105111E-03;
	vel_z = -1.175477383638605E-03;
	pos_x = -4.531869011211467E-02;
	pos_y = -7.253165832792150E-01;
	pos_z = -7.337816726564671E-03;
	// radius = 7.267680325988649E-01;

	vi[i][0] = vel_x;
	vi[i][1] = vel_y;
	vi[i][2] = vel_z;
	xi[i][0] = pos_x;
	xi[i][1] = pos_y;
	xi[i][2] = pos_z;

	//earth
	i++;
	vel_x = 1.671964880246573E-02;
	vel_y = -2.696563942942344E-03;
	vel_z = 3.499545652652556E-07;
	pos_x = -1.550257085548271E-01;
	pos_y = -1.003588459006916E+00;
	pos_z = 4.967984437823963E-05;
	// radius = 1.015491392298767E+00;

	vi[i][0] = vel_x;
	vi[i][1] = vel_y;
	vi[i][2] = vel_z;
	xi[i][0] = pos_x;
	xi[i][1] = pos_y;
	xi[i][2] = pos_z;

	// std::cout<<"acc: ("<<ai[1][0]<<", "<<ai[1][1]<<", "<<ai[1][2]<<")"<<std::endl;
	// std::cout<<"vel: ("<<vi[1][0]<<", "<<vi[1][1]<<", "<<vi[1][2]<<")"<<std::endl;
	// std::cout<<"pos: ("<<xi[1][0]<<", "<<xi[1][1]<<", "<<xi[1][2]<<")"<<std::endl;

	//mars
	i++;
	vel_x = 1.224571787006004E-02;
	vel_y = 8.853276243753566E-03;
	vel_z = -1.149047792967216E-04;
	pos_x = 7.656049322021028E-01;
	pos_y = -1.172049785802159E+00;
	pos_z = -4.334114585942423E-02;
	// radius = 1.400617744973796E+00;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// // ai[i][0] = 0;
	// // ai[i][1] = 0;
	// // ai[i][2] = 0;
	vi[i][0] = vel_x;
	vi[i][1] = vel_y;
	vi[i][2] = vel_z;
	xi[i][0] = pos_x;
	xi[i][1] = pos_y;
	xi[i][2] = pos_z;

	// //jupiter
	// i++;
	// vel_x = 7.037611366618768E-03;
	// vel_y = 2.856954462047065E-03;
	// vel_z = -1.693039791075531E-04;
	// pos_x = 1.710479118687038E+00;
	// pos_y = -4.876479343950519E+00;
	// pos_z = -1.801532969637167E-02;
	// // radius = 5.167795870537510E+00;
	// // vel_x = vel_x*auperday_mpersec;
	// // vel_y = vel_y*auperday_mpersec;
	// // vel_z = vel_z*auperday_mpersec;
	// // pos_x = pos_x*au_to_m;
	// // pos_y = pos_y*au_to_m;
	// // pos_z = pos_z*au_to_m;
	// // radius = radius*au_to_m;
	// vi[i][0] = vel_x;
	// vi[i][1] = vel_y;
	// vi[i][2] = vel_z;
	// xi[i][0] = pos_x;
	// xi[i][1] = pos_y;
	// xi[i][2] = pos_z;

	// //saturn
	// i++;
	// vel_x = 4.660833672965436E-03;
	// vel_y = 2.535827026110950E-03;
	// vel_z = -2.296255933767816E-04;
	// pos_x = 4.574047748292517E+00;
	// pos_y = -8.910379134359962E+00;
	// pos_z = -2.714155779463191E-02;
	// radius = 1.001586270801756E+01;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// ai[i][0] = 0;
	// ai[i][1] = 0;
	// ai[i][2] = 0;
	// vi[i][0] = vel_x;
	// vi[i][1] = vel_y;
	// vi[i][2] = vel_z;
	// xi[i][0] = pos_x;
	// xi[i][1] = pos_y;
	// xi[i][2] = pos_z;

	// //uranus
	// i++;
	// vel_x = -2.380000642410224E-03;
	// vel_y = 2.967412286201140E-03;
	// vel_z = 4.190342137343341E-05;
	// pos_x = 1.584565831457336E+01;
	// pos_y = 1.186850271611982E+01;
	// pos_z = -1.611705227327084E-01;
	// radius = 1.979828831192609E+01;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// ai[i][0] = 0;
	// ai[i][1] = 0;
	// ai[i][2] = 0;
	// vi[i][0] = vel_x;
	// vi[i][1] = vel_y;
	// vi[i][2] = vel_z;
	// xi[i][0] = pos_x;
	// xi[i][1] = pos_y;
	// xi[i][2] = pos_z;

	// //neptune
	// i++;
	// vel_x = 6.020858054847442E-04;
	// vel_y = 3.100842483536389E-03;
	// vel_z = -7.799193902035271E-05;
	// pos_x = 2.934520587108444E+01;
	// pos_y = -5.862792939590141E+00;
	// pos_z = -5.556420990247191E-01;
	// // radius = 2.993028878596138E+01;
	
	// vi[i][0] = vel_x;
	// vi[i][1] = vel_y;
	// vi[i][2] = vel_z;
	// xi[i][0] = pos_x;
	// xi[i][1] = pos_y;
	// xi[i][2] = pos_z;


	for (i = 0; i < bodies; i++)
	{
		for (j = 0; j < 3; j++)
		{
			init[i][0][j] = vi[i][j];
			init[i][1][j] = xi[i][j];
		}
	}
	//std::cout<<init[0][2][0]<<", "<<init[0][2][1]<<", "<<init[0][2][2]<<std::endl;

	// init[bodies][3][3] = {
	// 	{{{ai[0][0]},{ai[0][1]},{ai[0][2]}},
	// 	 {{vi[0][0]},{vi[0][1]},{vi[0][2]}},
	// 	 {{xi[0][0]},{xi[0][1]},{xi[0][2]}}},

	// 	{{{ai[1][0]},{ai[1][1]},{ai[1][2]}},
	// 	 {{vi[1][0]},{vi[1][1]},{vi[1][2]}},
	// 	 {{xi[1][0]},{xi[1][1]},{xi[1][2]}}},

	// 	{{{ai[2][0]},{ai[2][1]},{ai[2][2]}},
	// 	 {{vi[2][0]},{vi[2][1]},{vi[2][2]}},
	// 	 {{xi[2][0]},{xi[2][1]},{xi[2][2]}}},

	// 	{{{ai[3][0]},{ai[3][1]},{ai[3][2]}},
	// 	 {{vi[3][0]},{vi[3][1]},{vi[3][2]}},
	// 	 {{xi[3][0]},{xi[3][1]},{xi[3][2]}}},

	// 	{{{ai[4][0]},{ai[4][1]},{ai[4][2]}},
	// 	 {{vi[4][0]},{vi[4][1]},{vi[4][2]}},
	// 	 {{xi[4][0]},{xi[4][1]},{xi[4][2]}}},

	// 	{{{ai[5][0]},{ai[5][1]},{ai[5][2]}},
	// 	 {{vi[5][0]},{vi[5][1]},{vi[5][2]}},
	// 	 {{xi[5][0]},{xi[5][1]},{xi[5][2]}}},

	// 	{{{ai[6][0]},{ai[6][1]},{ai[6][2]}},
	// 	 {{vi[6][0]},{vi[6][1]},{vi[6][2]}},
	// 	 {{xi[6][0]},{xi[6][1]},{xi[6][2]}}},

	// 	{{{ai[7][0]},{ai[7][1]},{ai[7][2]}},
	// 	 {{vi[7][0]},{vi[7][1]},{vi[7][2]}},
	// 	 {{xi[7][0]},{xi[7][1]},{xi[7][2]}}},

	// 	{{{ai[8][0]},{ai[8][1]},{ai[8][2]}},
	// 	 {{vi[8][0]},{vi[8][1]},{vi[8][2]}},
	// 	 {{xi[8][0]},{xi[8][1]},{xi[8][2]}}}};
	

	// 4 body stable orbit
	//						{{{0,0,0},
	// 					     {0,a,a/10},
	// 						 {offset(OFFSET),offset(0),offset(0)}},
						
	// 						{{0,0,0},
	// 						 {0,-a,-a/10},
	// 						 {offset(-OFFSET),offset(0),offset(0)}},

	// 						{{0,0,0},
	// 						 {-a,0,-a/10},
	// 						 {offset(0),offset(OFFSET),offset(0)}},

	// 						 {{0,0,0},
	// 						 {a,0,a/10},
	// 						 {offset(0),offset(-OFFSET),offset(0)}}};

	//init[body][acc/vel/pos][x,y,z]

	data n(init,bodies);
	n.set_cental_force(true);
	n.play();
	n.write_datas();
	//n.printData(5);


	return 0;
}