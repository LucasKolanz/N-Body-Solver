#include <vector>
#ifndef NUMERICS_H
#define NUMERICS_H

enum class Quantity { Velocity, Position };
enum class Direction { x, y, z };

const double AU_TO_M = 149597870691;
const double DAY_TO_SEC = 86400;
const double EM_TO_SM = 333030;
const double AUPERDAY_TO_MPERSEC = 149597870691/86400;
const double KM_TO_M = 1000;

class numerics
{
public:
	numerics();
	void init(int bodies_, std::vector<double> mass_);
	void leapfrog(double ***initial_cond);
	void set_cental_force(bool set);
	void update_dt(double ***initial_cond);
	double get_dt();
	double magnitude(double xx, double yy, double zz);
	
	int vel;
	int pos;
	int x;
	int y;
	int z;
private:
	double previous_angmom;
	bool central_force;
	double G;
	double dt;
	int bodies;
	std::vector<double> mass;
};

#endif