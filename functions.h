#include <vector>
#include "EyeClassificationMacroses.h"

namespace EyeMomentClassification
{
	double mathematicalExpectation(const std::vector<double> &Vector, const double& coof);
	double dispersion(const std::vector<double> &Vector, const double &M);
}