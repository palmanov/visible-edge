#include <iostream>
#include "../include/algCG.h"

using namespace algCG;

int main()
{
	//
	// set the coordinate values for each vertex of the shape
	//
	vertex* V = new vertex[8];
	V[0].X = 2.0; V[0].Y = 0.0; V[0].Z = 2.0; // A1
	V[1].X = 0.0; V[1].Y = 0.0; V[1].Z = 2.0; // B1
	V[2].X = 0.0; V[2].Y = 2.0; V[2].Z = 2.0; // C1
	V[3].X = 2.0; V[3].Y = 2.0; V[3].Z = 2.0; // D1
	V[4].X = 2.0; V[4].Y = 0.0; V[4].Z = 0.0; // A2
	V[5].X = 0.0; V[5].Y = 0.0; V[5].Z = 0.0; // B2
	V[6].X = 0.0; V[6].Y = 2.0; V[6].Z = 0.0; // C2
	V[7].X = 2.0; V[7].Y = 2.0; V[7].Z = 0.0; // D2
	//
	// barycenter determination
	//
	barycenter W;
	for (int counter = 0; counter < 8; ++counter)
	{
		W.X += V[counter].X;
		W.Y += V[counter].Y;
		W.Z += V[counter].Z;
	}
	W.X /= 8;
	W.Y /= 8;
	W.Z /= 8;
	//
	// set the coordinates of the observation point
	//
	view_point P;
	P.X = 6;
	P.Y = 6;
	P.Z = 6;
	//
	// call the function of determining the visibility of the face
	//
	if (Roberts_alg(V[0], V[1], V[2], P, W))
		std::cout << "Hide" << std::endl;
	else std::cout << "Show" << std::endl;

	system("pause");
	return 0;
}