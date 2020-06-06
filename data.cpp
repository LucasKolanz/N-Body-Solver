#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "data.h"

data::data(double init[3][3][3], int bodies_)
{
	G = 6.67408e-11;
	dt = 0.005;
	runs = 1000;
	acc = (int)Quantity::Acceleration;
	vel = (int)Quantity::Velocity;
	pos = (int)Quantity::Position;
	x = (int)Direction::x;
	y = (int)Direction::y;
	z = (int)Direction::z;
	bodies = bodies_;
	double ***temp_data = new double**[3];
	for (int i = 0; i < 3; i++)
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

	double m = 6e20;
	mass.push_back(m);
	mass.push_back(m);
	mass.push_back(m);
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
	double ***temp_data = new double**[3];
	for (int i = 0; i < 3; i++)
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

	for (int k = 0; k < 3; k++)
	{

		for (int i = 0; i < bodies; i++)
		{
	//std::cout<<(*it)[0][0][0]<<std::endl;
			// accx0 = (*it)[i][acc][x];
			// accy0 = (*it)[i][acc][y];
			// accz0 = (*it)[i][acc][z];
			// velx0 = (*it)[i][vel][x];
			// vely0 = (*it)[i][vel][y];
			// velz0 = (*it)[i][vel][z];
			// posx0 = (*it)[i][pos][x];
			// posy0 = (*it)[i][pos][y];
			// posz0 = (*it)[i][pos][z];
			acci = 0;
			veli = 0;
			posi = 0;
			for (int j = 0; j < bodies; j++)
			{
				if (i == j)
				{
					continue;
				}
				
				// std::cout<<(*it)[i][pos][k]<<" ";
				// std::cout<<(*it)[j][pos][k]<<std::endl;

				if (pow(((*it)[i][pos][k] - (*it)[j][pos][k]),2) != 0)
				{
					if ((*it)[i][pos][k] - (*it)[j][pos][k] > 0)
					{
						acci -= mass[j]/(pow(((*it)[i][pos][k] - (*it)[j][pos][k]),2));
					}
					else
					{
						acci += mass[j]/(pow(((*it)[i][pos][k] - (*it)[j][pos][k]),2));	
					}
				}
				// std::cout<<(*it)[i][acc][k] - (*it)[j][acc][k]<<std::endl;
			}
			//std::cout<<G<<std::endl;
			acci *= G;
			// std::cout<<"acci: "<<acci<<std::endl;
			veli = acci*dt + (*it)[i][vel][k];
			
			// if (true)
			// {
			// 	std::cout<<"veli: "<<(*it)[i][vel][k]<<std::endl;
			// }
			
			//std::cout<<(*it)[i][vel][0]<<" "<<(*it)[i][vel][1]<<" "<<(*it)[i][vel][2]<<std::endl;
			//posi = acci*pow(dt,2)/2 + (*it)[i][vel][k]*dt + (*it)[i][pos][k];
			//posi = acci*pow(dt,2)/2 + veli*dt + (*it)[i][pos][k];
			posi = veli*dt + (*it)[i][pos][k];
			// if (k == 2)
			// {
			// 	acci = 0;
			// 	veli = 0;
			// 	posi = 0;
			// }
			temp_data[i][acc][k] = acci;
			temp_data[i][vel][k] = veli;
			temp_data[i][pos][k] = posi;

		}
	}
	datas.push_back(temp_data);
	// printData();
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

			// std::cout<<"\t\tposit: ";
			// std::cout<<"("<<(*it)[i][pos][x]<<", ";
			// std::cout<<(*it)[i][pos][y]<<", ";
			// std::cout<<(*it)[i][pos][z]<<")"<<std::endl;
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