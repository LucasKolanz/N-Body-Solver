#include <iostream>
#include <fstream>
#include <cmath>
#include "numerics.h"
#include "data.h"

#define OFFSET 0//1.519153500020739E+08//4.476613e12

double offset(double x)
{
	return OFFSET + x;
}

int main(int argc, char const *argv[])
{
	double vel_x;
	double vel_y;
	double vel_z;
	double pos_x;
	double pos_y;
	double pos_z;
	double radius;
	double au_to_m = 149597870691;
	double day_to_sec = 86400;
	double km_to_m = 1000;
	double auperday_mpersec = au_to_m/day_to_sec;
	int bodies = 2;
	int i,j;
	double ai[bodies][3];
	double vi[bodies][3];
	double xi[bodies][3];
	double init[bodies][3][3];

	//sun
	//input distance in astronomical units (au)
	//input speed as au/day
	ai[0][0] = 0;
	ai[0][1] = 0;
	ai[0][2] = 0;
	vi[0][0] = 0;
	vi[0][1] = 0;
	vi[0][2] = 0;
	xi[0][0] = 0;
	xi[0][1] = 0;
	xi[0][2] = 0;

	// //mercury
	// vel_x = 1.450098838504057E-02;
	// vel_y = -1.827392737866101E-02;
	// vel_z = -2.823480785896841E-03;
	// pos_x = -3.124921389426347E-01;
	// pos_y = -3.231017308099852E-01;
	// pos_z = 2.264004677880896E-03;
	// radius = 4.495010467958139E-01;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// // ai[1][0] = pow(vel_x,2)/radius;
	// // ai[1][1] = pow(vel_x,2)/radius;
	// // ai[1][2] = pow(vel_x,2)/radius;
	// ai[1][0] = 0;
	// ai[1][1] = 0;
	// ai[1][2] = 0;
	// vi[1][0] = vel_x;
	// vi[1][1] = vel_y;
	// vi[1][2] = vel_z;
	// xi[1][0] = pos_x;
	// xi[1][1] = pos_y;
	// xi[1][2] = pos_z;

	// //venus
	// vel_x =  2.005150325251360E-02;
	// vel_y = -1.338183192105111E-03;
	// vel_z = -1.175477383638605E-03;
	// pos_x = -4.531869011211467E-02;
	// pos_y = -7.253165832792150E-01;
	// pos_z = -7.337816726564671E-03;
	// radius = 7.267680325988649E-01;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// // ai[2][0] = pow(vel_x,2)/radius;
	// // ai[2][1] = pow(vel_x,2)/radius;
	// // ai[2][2] = pow(vel_x,2)/radius;
	// ai[2][0] = 0;
	// ai[2][1] = 0;
	// ai[2][2] = 0;
	// vi[2][0] = vel_x;
	// vi[2][1] = vel_y;
	// vi[2][2] = vel_z;
	// xi[2][0] = pos_x;
	// xi[2][1] = pos_y;
	// xi[2][2] = pos_z;

	//earth
	// vel_x = 1.671964880246573E-02;
	// vel_y = -2.696563942942344E-03;
	// vel_z = 3.499545652652556E-07;
	// pos_x = -1.550257085548271E-01;
	// pos_y = -1.003588459006916E+00;
	// pos_z = 4.967984437823963E-05;
	// radius = 1.015491392298767E+00;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	vel_x = 2.894935022801710E+01;
	vel_y = -4.668984074890867E+00;
	vel_z = 6.059312245998427E-04;
	pos_x = -2.319151590356091E+07;
	pos_y = -1.501346965265288E+08;
	pos_z = 7.431998935692012E+03;
	radius = 1.519153500020739E+08;
	vel_x = vel_x*km_to_m;
	vel_y = vel_y*km_to_m;
	vel_z = vel_z*km_to_m;
	pos_x = pos_x*km_to_m;
	pos_y = pos_y*km_to_m;
	pos_z = pos_z*km_to_m;
	radius = radius*km_to_m;
	// ai[3][0] = pow(vel_x,2)/radius;
	// ai[3][1] = pow(vel_x,2)/radius;
	// ai[3][2] = pow(vel_x,2)/radius;
	// ai[3][0] = 0;
	// ai[3][1] = 0;
	// ai[3][2] = 0;
	// vi[3][0] = vel_x;
	// vi[3][1] = vel_y;
	// vi[3][2] = vel_z;
	// xi[3][0] = pos_x;
	// xi[3][1] = pos_y;
	// xi[3][2] = pos_z;

	ai[1][0] = 0;
	ai[1][1] = 0;
	ai[1][2] = 0;
	vi[1][0] = vel_x;
	vi[1][1] = vel_y;
	vi[1][2] = vel_z;
	xi[1][0] = pos_x;
	xi[1][1] = pos_y;
	xi[1][2] = pos_z;

	// std::cout<<"acc: ("<<ai[1][0]<<", "<<ai[1][1]<<", "<<ai[1][2]<<")"<<std::endl;
	// std::cout<<"vel: ("<<vi[1][0]<<", "<<vi[1][1]<<", "<<vi[1][2]<<")"<<std::endl;
	// std::cout<<"pos: ("<<xi[1][0]<<", "<<xi[1][1]<<", "<<xi[1][2]<<")"<<std::endl;

	// //mars
	// vel_x = 1.224571787006004E-02;
	// vel_y = 8.853276243753566E-03;
	// vel_z = -1.149047792967216E-04;
	// pos_x = 7.656049322021028E-01;
	// pos_y = -1.172049785802159E+00;
	// pos_z = -4.334114585942423E-02;
	// radius = 1.400617744973796E+00;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// ai[4][0] = pow(vel_x,2)/radius;
	// ai[4][1] = pow(vel_x,2)/radius;
	// ai[4][2] = pow(vel_x,2)/radius;
	// vi[4][0] = vel_x;
	// vi[4][1] = vel_y;
	// vi[4][2] = vel_z;
	// xi[4][0] = pos_x;
	// xi[4][1] = pos_y;
	// xi[4][2] = pos_z;

	// //jupiter
	// vel_x = 7.037611366618768E-03;
	// vel_y = 2.856954462047065E-03;
	// vel_z = -1.693039791075531E-04;
	// pos_x = 1.710479118687038E+00;
	// pos_y = -4.876479343950519E+00;
	// pos_z = -1.801532969637167E-02;
	// radius = 5.167795870537510E+00;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// // ai[5][0] = pow(vel_x,2)/radius;
	// // ai[5][1] = pow(vel_x,2)/radius;
	// // ai[5][2] = pow(vel_x,2)/radius;
	// ai[5][0] = 0;
	// ai[5][1] = 0;
	// ai[5][2] = 0;
	// vi[5][0] = vel_x;
	// vi[5][1] = vel_y;
	// vi[5][2] = vel_z;
	// xi[5][0] = pos_x;
	// xi[5][1] = pos_y;
	// xi[5][2] = pos_z;

	// //saturn
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
	// // ai[6][0] = pow(vel_x,2)/radius;
	// // ai[6][1] = pow(vel_x,2)/radius;
	// // ai[6][2] = pow(vel_x,2)/radius;
	// ai[6][0] = 0;
	// ai[6][1] = 0;
	// ai[6][2] = 0;
	// vi[6][0] = vel_x;
	// vi[6][1] = vel_y;
	// vi[6][2] = vel_z;
	// xi[6][0] = pos_x;
	// xi[6][1] = pos_y;
	// xi[6][2] = pos_z;

	// //uranus
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
	// // ai[7][0] = pow(vel_x,2)/radius;
	// // ai[7][1] = pow(vel_x,2)/radius;
	// // ai[7][2] = pow(vel_x,2)/radius;
	// ai[7][0] = 0;
	// ai[7][1] = 0;
	// ai[7][2] = 0;
	// vi[7][0] = vel_x;
	// vi[7][1] = vel_y;
	// vi[7][2] = vel_z;
	// xi[7][0] = pos_x;
	// xi[7][1] = pos_y;
	// xi[7][2] = pos_z;

	// //neptune
	// vel_x = 6.020858054847442E-04;
	// vel_y = 3.100842483536389E-03;
	// vel_z = -7.799193902035271E-05;
	// pos_x = 2.934520587108444E+01;
	// pos_y = -5.862792939590141E+00;
	// pos_z = -5.556420990247191E-01;
	// radius = 2.993028878596138E+01;
	// vel_x = vel_x*auperday_mpersec;
	// vel_y = vel_y*auperday_mpersec;
	// vel_z = vel_z*auperday_mpersec;
	// pos_x = pos_x*au_to_m;
	// pos_y = pos_y*au_to_m;
	// pos_z = pos_z*au_to_m;
	// radius = radius*au_to_m;
	// // ai[8][0] = pow(vel_x,2)/radius;
	// // ai[8][1] = pow(vel_x,2)/radius;
	// // ai[8][2] = pow(vel_x,2)/radius;
	// ai[8][0] = 0;
	// ai[8][1] = 0;
	// ai[8][2] = 0;
	// vi[8][0] = vel_x;
	// vi[8][1] = vel_y;
	// vi[8][2] = vel_z;
	// xi[8][0] = pos_x;
	// xi[8][1] = pos_y;
	// xi[8][2] = pos_z;

	for (i = 0; i < bodies; i++)
	{
		for (j = 0; j < 3; j++)
		{
			init[i][0][j] = ai[i][j];
			init[i][1][j] = vi[i][j];
			init[i][2][j] = offset(xi[i][j]);
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

	n.play();

	n.write_datas();

	n.printData();


	return 0;
}