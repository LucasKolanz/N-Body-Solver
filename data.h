#ifndef DATA_H
#define DATA_H

#include <vector>

enum class Quantity { Acceleration, Velocity, Position };
enum class Direction { x, y, z };

class data
{
public:
	data(double init[][3][3], int bodies_);
	~data();
	//init[body][acc/vel/pos][x,y,z]
	void printData();
	void play();
	void write_datas();
private:
	void iterate();

	int acc;
	int vel;
	int pos;
	int x;
	int y;
	int z;
	std::vector<double***> datas;
	std::vector<double> mass; //masses in kg
	//datas[iteration][body][acc/vel/pos][x,y,z]
	int bodies;
	int runs;
	int current_iteration;
	double G;
	double dt;
};

#endif