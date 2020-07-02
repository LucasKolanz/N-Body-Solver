#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "data.h"
#include "numerics.h"

data::data(double init[][2][3], int bodies_)
{

	total_time = 100*365; //all time in days
	current_iteration = 0;
	current_time = 0;
	central_force = false;
	bodies = bodies_;
	// double ***temp_data = new double**[bodies];
	double ***init_cond = new double**[bodies];
	for (int i = 0; i < bodies; i++)
	{
		init_cond[i] = new double*[2];
		for (int j = 0; j < 2; j++)
		{
			init_cond[i][j] = new double[3];
			for (int k = 0; k < 3; k++)
			{
				init_cond[i][j][k] = init[i][j][k];
			}
		}
	}

	datas.push_back(init_cond);

	//mass in Solar Mass
	//starting with Earth Mass for planets
	mass.push_back(1);//sun
	mass.push_back(0.055*EM_TO_SM);//mercury
	mass.push_back(0.815*EM_TO_SM);//venus
	mass.push_back(1*EM_TO_SM);//earth
	mass.push_back(0.107*EM_TO_SM);//mars
	// mass.push_back(317.8*EM_TO_SM);//jupiter
	// mass.push_back(95.16*EM_TO_SM);//saturn
	// mass.push_back(14.54*EM_TO_SM);//uranus
	// mass.push_back(17.15*EM_TO_SM);//neptune
	n.init(bodies,mass);

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
			myfile<<"("<<(*it)[i][n.pos][n.x]<<", ";
			myfile<<(*it)[i][n.pos][n.y]<<", ";
			myfile<<(*it)[i][n.pos][n.z]<<")"<<std::endl;
		}
		c++;
		it++;
	}
	
	myfile.close();

}

void data::play()
{
	while (current_time < total_time)
	{
		iterate();
	}
	std::cout<<n.get_dt()<<std::endl;
}

void data::iterate()
{
	std::vector<double***>::iterator it = --datas.end();
	double ***temp_data = new double**[bodies];
	//initializes a double*** to save the new data
	for (int i = 0; i < bodies; i++)
	{
		temp_data[i] = new double*[2];
		for (int j = 0; j < 2; j++)
		{
			temp_data[i][j] = new double[3];
			for (int k = 0; k < 3; k++)
			{
				temp_data[i][j][k] = (*it)[i][j][k];
			}
		}
	}
	//iterate data
	n.leapfrog(temp_data);
	//update time
	current_time += n.get_dt();
	//add data field to vector
	datas.push_back(temp_data);
	//iterate the current iteration
	current_iteration++;
}

void data::set_cental_force(bool set)
{
	if (set != central_force)
	{
		central_force = set;
		n.set_cental_force(set);
	}
}

//datas[iteration][body][acc/vel/pos][x,y,z]
void data::printData(double ***pm)
{
	for (int i = 0; i < bodies; i++)
	{
		std::cout<<"\tbody: "<<i<<std::endl;
		std::cout<<"\t\tveloc: ";
		std::cout<<"HERE"<<std::endl;
		std::cout<<"("<<pm[i][n.vel][n.x]<<", ";
		std::cout<<pm[i][n.vel][n.y]<<", ";
		std::cout<<pm[i][n.vel][n.z]<<")"<<std::endl;

		std::cout<<"\t\tposit: ";
		std::cout<<"("<<pm[i][n.pos][n.x]<<", ";
		std::cout<<pm[i][n.pos][n.y]<<", ";
		std::cout<<pm[i][n.pos][n.z]<<")"<<std::endl;
	}
}

void data::printData(int num)
{
	std::vector<double***>::iterator it = datas.begin();
	int c = 0;
	if (num != -1)	
	{
		while(c < num)
		{
			std::cout<<"========================================"<<std::endl;
			std::cout<<"iteration: "<<c<<std::endl;
			for (int i = 0; i < bodies; i++)
			{
				std::cout<<"\tbody: "<<i<<std::endl;
				std::cout<<"\t\tveloc: ";
				std::cout<<"("<<(*it)[i][n.vel][n.x]<<", ";
				std::cout<<(*it)[i][n.vel][n.y]<<", ";
				std::cout<<(*it)[i][n.vel][n.z]<<")"<<std::endl;

				std::cout<<"\t\tposit: ";
				std::cout<<"("<<(*it)[i][n.pos][n.x]<<", ";
				std::cout<<(*it)[i][n.pos][n.y]<<", ";
				std::cout<<(*it)[i][n.pos][n.z]<<")"<<std::endl;
			}
			c++;
			it++;
		}
	}
	else
	{
		while(it != datas.end())
		{
			std::cout<<"========================================"<<std::endl;
			std::cout<<"iteration: "<<c<<std::endl;
			for (int i = 0; i < bodies; i++)
			{
				std::cout<<"\tbody: "<<i<<std::endl;
				std::cout<<"\t\tveloc: ";
				std::cout<<"("<<(*it)[i][n.vel][n.x]<<", ";
				std::cout<<(*it)[i][n.vel][n.y]<<", ";
				std::cout<<(*it)[i][n.vel][n.z]<<")"<<std::endl;

				std::cout<<"\t\tposit: ";
				std::cout<<"("<<(*it)[i][n.pos][n.x]<<", ";
				std::cout<<(*it)[i][n.pos][n.y]<<", ";
				std::cout<<(*it)[i][n.pos][n.z]<<")"<<std::endl;
			}
			c++;
			it++;
		}
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
			for (int j = 0; j < 2; j++)
			{

				delete [] (*it)[i][j];
			}
			delete [] (*it)[i];
		}
		delete [] (*it);
		it++;
	}
}