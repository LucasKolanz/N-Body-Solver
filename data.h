#ifndef DATA_H
#define DATA_H

#include <vector>
#include "numerics.h"

class data
{
public:
	data(double init[][2][3], int bodies_);
	~data();
	//init[body][acc/vel/pos][x,y,z]
	void printData(double ***pm);
	void printData(int num);
	void play();
	void write_datas();
	void set_cental_force(bool set);
private:
	void iterate();
	numerics n;
	bool central_force;
	double total_time;
	double current_time;
	int vel;
	int pos;
	int x;
	int y;
	int z;
	std::vector<double***> datas;
	std::vector<double> mass; //masses in kg
	//datas[iteration][body][vel/pos][x,y,z]
	int bodies;
	int runs;
	int current_iteration;
	double G;
	double dt;
};

#endif