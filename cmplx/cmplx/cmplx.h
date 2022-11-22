#ifndef CMPLX_H
#define CMPLX_H

#include <math.h>

#define PI 3.141592
#define DEG_TO_RAD(angle) (angle*PI)/180
#define RAD_TO_DEG(angle) (180*angle)/(PI)

enum complex_format {CARTESIAN,POLAR};

class complex {
private:
	double real;
	double imaginary;
	double magnitude;
	double phase;
public:

	complex(double r, double i,complex_format type = CARTESIAN);

	double re();
	double im();
	double mag();
	double ph();

};

complex operator+(complex a, complex b);

complex operator+(complex a, double b);

complex operator+(complex a, int b);



complex operator*(complex a, complex b);

complex operator*(complex a, double b);

complex operator*(complex a, int b);

complex cpow(complex a, double b);

bool operator==(complex a, complex b);


#endif