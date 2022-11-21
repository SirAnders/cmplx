#ifndef CMPLX_H
#define CMPLX_H

#include <math.h>

#define PI 3.141592
#define DEG_TO_RAD(angle) (angle*PI)/180
#define RAD_TO_DEG(angle) (180*angle)/(PI)

enum complex_format {CARTESIAN,POLAR};

class complex {
private:
	float real;
	float imaginary;
	float magnitude;
	float phase;
public:

	complex(float r, float i,complex_format type = CARTESIAN);

	float re();
	float im();
	float mag();
	float ph();

};

complex operator+(complex a, complex b);

complex operator*(complex a, complex b);

#endif