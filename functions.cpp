#include "stdafx.h"
#include "functions.h"

namespace EyeMomentClassification
{
	double mathematicalExpectation(const std::vector<double> &Vector, const double& coof)
	{
		double M = 0.0;
		for (unsigned int i = 0; i < Vector.size(); i++)
			M += coof*Vector[i];
		return M;
	}
	double dispersion(const std::vector<double> &Vector, const double &M)
	{
		double coof = 1.0 / (Vector.size()*1.0);
		double D = 0.0;
		for (unsigned int i = 0; i < Vector.size(); i++)
			D += coof*SQRT(Vector[i] - M);
		return D;
	}
}