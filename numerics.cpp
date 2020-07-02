#include <iostream>
#include <cmath>
#include <vector>
#include "numerics.h"

numerics::numerics()
{
	central_force = false;
	previous_angmom = -1;
	dt = 1;// starting time step in days
	G = 6.67408e-11;//units m^3kg^-1s^-2
	G *= pow(DAY_TO_SEC,2)*((EM_TO_SM)*5.9722e24)/pow(AU_TO_M,3); //units au^3 Msol-1 day^-2
	vel = (int)Quantity::Velocity;
	pos = (int)Quantity::Position;
	x = (int)Direction::x;
	y = (int)Direction::y;
	z = (int)Direction::z;
}

void numerics::init(int bodies_, std::vector<double> mass_)
{
	bodies = bodies_;
	mass = mass_;
}

void numerics::set_cental_force(bool set)
{
	if (set != central_force)
	{
		central_force = set;
	}
}

void numerics::leapfrog(double ***initial_cond)
{
	double acci;
	//distance between two bodies
	double r;
	//distance between two bodies same component
	double x_vec;
	double y_vec;
	double z_vec;
	//magnitude of force (Gm/r^3)
	double mag;
	//iterate through bodies
	for (int i = 0; i < bodies; i++)
	{
		if (central_force && i == 0)
		{
			i++;
		}
		// accx0 = initial_cond[i][acc][x];
		// accy0 = initial_cond[i][acc][y];
		// accz0 = initial_cond[i][acc][z];
		// velx0 = initial_cond[i][vel][x];
		// vely0 = initial_cond[i][vel][y];
		// velz0 = initial_cond[i][vel][z];
		// posx0 = initial_cond[i][pos][x];
		// posy0 = initial_cond[i][pos][y];
		// posz0 = initial_cond[i][pos][z];

		mag = 0;

		x_vec = 0;
		y_vec = 0;
		z_vec = 0;

		//iterate through other bodies (to sum other bodies
		//contributions to r, in F=Gmm/r^3 r_vec)
		for (int j = 0; j < bodies; j++)
		{
			if (central_force)
			{
				j = 0;
			}
			//skip if looking at same body
			//skip if central_force and second body is not the sun
			r = 0;
			if ((i != j))
			{
				//determine value of r
				for (int m = 0; m < 3; m++) 
				{
					r += pow((initial_cond[i][pos][m] - initial_cond[j][pos][m]),2);
				}

				mag += mass[j] / pow(r,3/2);

				x_vec += (initial_cond[j][pos][x] - initial_cond[i][pos][x]);
				y_vec += (initial_cond[j][pos][y] - initial_cond[i][pos][y]);
				z_vec += (initial_cond[j][pos][z] - initial_cond[i][pos][z]);
			}
			if (central_force)
			{
				break;
			}
		}
		//go through coordinates and update values
		mag *= G;
		for(int k = 0; k < 3; k++)
		{
			if (k == 0)
			{
				acci = mag*x_vec;
			}
			else if (k == 1)
			{
				acci = mag*y_vec;
			}
			else
			{
				acci = mag*z_vec;
			} 
			initial_cond[i][vel][k] += acci*dt;
			initial_cond[i][pos][k] += initial_cond[i][vel][k]*dt;
		}
	}
	update_dt(initial_cond);
}

double numerics::magnitude(double xx, double yy, double zz)
{
	return sqrt(pow(xx,2)+pow(yy,2)+pow(zz,2));
}

void numerics::update_dt(double ***initial_cond)
{
	double current_angmom = 0;
	//double temp = 0;
	for (int i = 0; i < bodies; i++)
	{
		current_angmom += mass[i]*magnitude(initial_cond[i][vel][x],initial_cond[i][vel][y],initial_cond[i][vel][z])*magnitude(initial_cond[i][pos][x],initial_cond[i][pos][y],initial_cond[i][pos][z]);
	}
	if (previous_angmom != -1)
	{
		//temp = (current_angmom*previous_angmom)/(current_angmom+previous_angmoms);
		//std::cout<<"ang mom: "<<current_angmom<<" "<<previous_angmom<<std::endl;
		if (abs(current_angmom - previous_angmom) < 0.00001)
		{
			//std::cout<<"HERE"<<std::endl;
			dt += dt * 0.01;
		}
		else
		{
			dt -= dt * 0.10;
		}
	}
	//std::cout<<"Dt: "<<dt<<std::endl;
	previous_angmom = current_angmom;
}

double numerics::get_dt()
{
	return dt;
}