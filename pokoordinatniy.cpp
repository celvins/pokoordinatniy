//============================================================================
// Name        : pokoordinatniy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include "function.h"
using namespace std;
//
//Структура файла: epsilon n x[i]...x[n - 1]
//
int main() {
	FILE *file;
	file = fopen("config.txt", "r");
	double  epsilon = 0;
	int index_fix = 0, i = 0, n = 0;
	fscanf(file, "%lf %d", &epsilon, &n);
	double* x = new double[n];
	double* f = new double[n];
	for(i = 0; i < n; i++)
		fscanf(file, "%lf", &x[i]);
	do{
		for (i = 0; i < n; i++){
			for(index_fix = 0; index_fix < n; index_fix++){
				if(i != index_fix){
					x[i] = scan(x, index_fix);
					f[i] = function(x);
					printf("%5lf \n", function(x));
				}
			}
		}
	}while(fabs(f[0] - f[1]) > epsilon);
	printf("%5lf\n", function(x));
	fclose(file);
	delete []x;
	delete []f;
	return 0;
}
