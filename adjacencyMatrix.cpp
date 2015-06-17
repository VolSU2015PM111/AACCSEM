#include "stdafx.h"
#include "adjacencyMatrix.h"

namespace EyeMomentClassification
{
	adjacencyMatrix::adjacencyMatrix(const std::vector<double> &X, const std::vector<double> &Y)
	{
		Npoints = X.size() - 1;
		distance = new double*[Npoints];
		double k;
		for (int i = 1; i < X.size(); i++)
		{
			distance[i - 1] = new double[i];
			for (int j = 0; j < i; j++)
			{
				k = sqrt((X[j] - X[i])*(X[j] - X[i]) + (Y[j] - Y[i])*(Y[j] - Y[i]));
				distance[i - 1][j] = k;
			}
		}
	}
	adjacencyMatrix::adjacencyMatrix(const adjacencyMatrix& AM)
	{
		Npoints = AM.Npoints;
		distance = new double*[Npoints];
		for (int i = 0; i < Npoints; i++)
		{
			distance[i] = new double[i + 1];
			memcpy(distance[i], AM.distance[i], i * sizeof(double));
		}
	}


	adjacencyMatrix::~adjacencyMatrix()
	{
		for (int i = 0; i < Npoints; i++)
		{
			delete[] distance[i];
		}
		delete[]distance;
	}
	const double &adjacencyMatrix::operator()(const int& I, const int& J)
	{
		double k;
		int j = (I < J ? I : J);
		int i = (I < J ? J : I);
		if (i == j)
			return 0;
		i -= 1;
		return distance[i][j];
	}
}