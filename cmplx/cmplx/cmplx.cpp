// cmplx.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "cmplx.h"

/*   M E T H O D S   */

complex::complex(float r, float i, complex_format type) {
	if (type == CARTESIAN) {
		//cartesian format a + jb
		real = r;
		imaginary = i;
		magnitude = sqrt(pow(r, 2) + pow(i, 2));
		if ((r > 0) && (i >= 0)) {
			phase = atanf(i / r);
		}
		else if ((r <= 0) && (i > 0)) {
			phase = DEG_TO_RAD(90) + atanf(-r / i);
		}
		else if ((r < 0) && (i <= 0)) {
			phase = DEG_TO_RAD(180) + atanf(i / r);
		}
		else if ((r >= 0) && (i < 0)) {
			phase = DEG_TO_RAD(270) + atanf(-r / i);
		}
		else {
			phase = 0;
		}
	}
	else {
		//polar format A/_angle 
		magnitude = r;
		phase = i;
		real = r * cos(i);
		imaginary = r * sin(i);
	}
}

float complex::re() {
	return real;
}
float complex::im() {
	return imaginary;
}
float complex::mag() {
	return magnitude;
}	  
float complex::ph() {
	return phase;
}

/*  O P E R A T O R S  */

complex operator+(complex a, complex b) {
	return complex{ a.re() + b.re(), a.im() + b.im(), CARTESIAN };
}

complex operator*(complex a, complex b) {
	return complex{ a.mag() * b.mag(), a.ph() + b.ph(), POLAR };
}

