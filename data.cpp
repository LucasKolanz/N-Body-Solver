#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "data.h"

data::data(double init[][3][3], int bodies_)
{

	// G = 6.67408e-11;//units m^3kg^-1s^-2
	G = 4.36408e-22;
	dt = 3600*24;
	runs = 5000;
	current_iteration = 0;
	acc = (int)Quantity::Acceleration;
	vel = (int)Quantity::Velocity;
	pos = (int)Quantity::Position;
	x = (int)Direction::x;
	y = (int)Direction::y;
	z = (int)Direction::z;
	bodies = bodies_;
	double ***temp_data = new double**[bodies];
	for (int i = 0; i < bodies; i++)
	{
		temp_data[i] = new double*[3];
		for (int j = 0; j < 3; j++)
		{
			temp_data[i][j] = new double[3];
			for (int k = 0; k < 3; k++)
			{
				temp_data[i][j][k] = init[i][j][k];
			}
		}
	}

	datas.push_back(temp_data);

	//mass in kg
	mass.push_back(1988500e24);//sun
	mass.push_back(5.97219e24);//earth
	// mass.push_back(3.302e23);//mercury
	// mass.push_back(48.685e23);//venus
	// mass.push_back(6.4171e23);//mars
	// mass.push_back(1898.13e24);//jupiter
	// mass.push_back(5.6834e26);//saturn
	// mass.push_back(86.813e24);//uranus
	// mass.push_back(102.412e24);//neptune

	// double m = 6e15;
	// for (int i = 0; i < bodies; i++)
	// {
	// 	mass.push_back(m);	
	// }
}

void data::write_datas()
{
	std::vector<double***>::iterator it = datas.begin();
	int c = 0;

	std::ofstream myfile;
	myfile.open("write_data.txt");

	
	while(it != datas.end())
	{
		myfile<<"iteration: "<<c<<std::endl;
		for (int i = 0; i < bodies; i++)
		{
			myfile<<"\tbody: "<<i<<std::endl;
			myfile<<"("<<(*it)[i][pos][x]<<", ";
			myfile<<(*it)[i][pos][y]<<", ";
			myfile<<(*it)[i][pos][z]<<")"<<std::endl;
		}
		c++;
		it++;
	}
	
	myfile.close();

}

void data::play()
{
	int c = 0; 
	while (c < runs-1)
	{
		iterate();
		c++;
	}
}

void data::iterate()
{

	std::vector<double***>::iterator it = --datas.end();
	double ***temp_data = new double**[bodies];
	//initializes a double*** to save the new data
	for (int i = 0; i < bodies; i++)
	{
		temp_data[i] = new double*[3];
		for (int j = 0; j < 3; j++)
		{
			temp_data[i][j] = new double[3];
			for (int k = 0; k < 3; k++)
			{
				temp_data[i][j][k] = 0;
			}
		}
	}

	double acci;
	double veli;
	double posi;
	//distance between two bodies
	double r;
	//distance between two bodies same component
	double r_vec;
	//magnitude of force (Gm/r^3)
	double mag;
	
	//iterate through bodies
	for (int i = 0; i < bodies; i++)
	{
		// accx0 = (*it)[i][acc][x];
		// accy0 = (*it)[i][acc][y];
		// accz0 = (*it)[i][acc][z];
		// velx0 = (*it)[i][vel][x];
		// vely0 = (*it)[i][vel][y];
		// velz0 = (*it)[i][vel][z];
		// posx0 = (*it)[i][pos][x];
		// posy0 = (*it)[i][pos][y];
		// posz0 = (*it)[i][pos][z];

		//initial conditions (last iteration's value)

		//is there an initail force? (impulse)
		if (current_iteration != 0)
		{
			acci = 0;
		}
		else
		{
			acci = 0;//(*it)[i][acc][k];
		}

		//iterate through other bodies (to sum other bodies
		//contributions to r, in F=Gmm/r^2)
		for (int j = 0; j < bodies; j++)
		{
			//skip if looking at same body
			if (i != j)
			{
				r = 0;
				//determine value of r
				for (int m = 0; m < 3; m++) 
				{
					r += pow(((*it)[i][pos][m] - (*it)[j][pos][m]),2);
				}

				mag = G * mass[j] / pow(r,3/2);

				//Iterate through x,y,z values
				for (int k = 0; k < 3; k++)
				{
					//check if distance between two bodies same 
					//components of position is zero (no force 
					//in this direction)
					if (((*it)[i][pos][k] - (*it)[j][pos][k]) != 0)
					{
						//set value of r_vec
						r_vec = ((*it)[j][pos][k] - (*it)[i][pos][k]);

						acci = mag*r_vec;
						
					}
					veli = (*it)[i][vel][k];
					posi = (*it)[i][pos][k];
					//find new velocity
					veli += acci*dt;
					//find new position
					posi += veli*dt;
					//update new data field with new data
					temp_data[i][acc][k] = acci;
					temp_data[i][vel][k] = veli;
					temp_data[i][pos][k] = posi;
				}
			}
		}
	}
	//add data field to vector
	datas.push_back(temp_data);
	//iterate the current iteration
	current_iteration++;
}

//datas[iteration][body][acc/vel/pos][x,y,z]
void data::printData()
{
	std::vector<double***>::iterator it = datas.begin();
	int c = 0;
	
	while(it != datas.end())
	{
		std::cout<<"========================================"<<std::endl;
		std::cout<<"iteration: "<<c<<std::endl;
		for (int i = 0; i < bodies; i++)
		{
			std::cout<<"\tbody: "<<i<<std::endl;
			// std::cout<<"\t\taccel: ";
			// std::cout<<"("<<(*it)[i][acc][x]<<", ";
			// std::cout<<(*it)[i][acc][y]<<", ";
			// std::cout<<(*it)[i][acc][z]<<")"<<std::endl;

			std::cout<<"\t\tveloc: ";
			std::cout<<"("<<(*it)[i][vel][x]<<", ";
			std::cout<<(*it)[i][vel][y]<<", ";
			std::cout<<(*it)[i][vel][z]<<")"<<std::endl;

			std::cout<<"\t\tposit: ";
			std::cout<<"("<<(*it)[i][pos][x]<<", ";
			std::cout<<(*it)[i][pos][y]<<", ";
			std::cout<<(*it)[i][pos][z]<<")"<<std::endl;
		}
		c++;
		it++;
	}
	std::cout<<"========================================"<<std::endl;
}

data::~data()
{
	std::vector<double***>::iterator it = datas.begin();
	while(it != datas.end())
	{
		for (int i = 0; i < bodies; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				delete [] (*it)[i][j];
			}
			delete [] (*it)[i];
		}
		delete [] (*it);
		it++;
	}
}