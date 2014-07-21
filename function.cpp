/*
 * function.cpp
 *
 *  Created on: 24.06.2014
 *      Author: Андраник
 */

#include "function.h"
#include <math.h>
double fun(double x, double x_fix, int i){
	switch(i){
	case 0:
		return  pow(x, 2) + cos(x_fix + 1.23 * x);
		break;
	case 1:
		return  pow(x_fix, 2) + cos(x + 1.23 * x_fix);
		break;
	}
}
double function(double* x){
	return  x[1] * x[1] + cos(x[0] + 1.23 * x[1]);
}
double scan(double* x, int i){
	double epsilon = 0.001, step = 50 * epsilon, x0 = 0;
	switch(i){
	case 0:
		x0 = x[1];
		break;
	case 1:
		x0 = x[0];
		break;
	}
	while((fabs(step) > epsilon) || (fun(x0 + step, x[i], i) < fun(x0, x[i], i))){
		x0 += step;
		if(fun(x0 + step, x[i], i) > fun(x0, x[i], i))
			step /=-2;
	}
	return x0;
}
