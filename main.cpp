#include <iostream>
#include <fstream>
#include "numerics.h"
#include "data.h"

#define OFFSET 5e5

double offset(double x)
{
	return OFFSET + x;
}

int main(int argc, char const *argv[])
{
	double vel_x;
	double vel_y;
	double vel_z;
	double radius;
	int bodies = 9;
	double init[bodies][3][3] = {
		//sun
		vel_x = -8.074327841694941E-06;
		vel_y = -3.725217511481164E-06;
		vel_z = 2.325448967848458E-07;
		pos_x = -5.137169516793444E-03;
		pos_y = 6.983299855954004E-03;
		pos_z = 6.057462903046038E-05;
		radius = 8.669524601044811E-03;
		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},

		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},

		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},
	
		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},

		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},

		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},

		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},

		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},

		{{{pow(vel_x,2)/radius},{pow(vel_y,2)/radius},{pow(vel_z,2)/radius}},
		 {{vel_x},{vel_y},{vel_z}},
		 {{offset(pos_x)},{offset(pos_y)},{offset(pos_z)}}},
	};

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

	//n.printData();


	return 0;
}