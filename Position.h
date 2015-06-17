#pragma once
#include <vector>
#include "Algorithm.h"
#include "EyeClassificationMacroses.h"

namespace EyeMomentClassification
{
	typedef class BaseAlgorithm* uAlgorithm;
	typedef class BaseAlgorithm& pAlgorithm;
	typedef struct EyeMomentPosition EyePosition;
	class Position :
		public std::vector<EyePosition>
	{
	private:
		double timeBetweenMeasurements;
	public:
		ALGORITHMCLASSDLL_API Position(const int &n, const double &TimeBetweenMeasurements);
		ALGORITHMCLASSDLL_API Position(const Position &position);
		ALGORITHMCLASSDLL_API ~Position();
		ALGORITHMCLASSDLL_API void push_back(const EyePosition &value);
		ALGORITHMCLASSDLL_API std::vector<double> speedArray();
		ALGORITHMCLASSDLL_API std::vector<double> OX();
		ALGORITHMCLASSDLL_API std::vector<double> OY();
		ALGORITHMCLASSDLL_API double speed(const unsigned int &i);
		ALGORITHMCLASSDLL_API const double &TimeBetweenMeasurements();
	};
}
