#pragma once

#include "Algorithm.h"
#include "EyeClassificationMacroses.h"

namespace EyeMomentClassification
{
	class I_VT :
		public BaseAlgorithm
	{
	private:
		double thresholdSpeed;
	public:
		ALGORITHMCLASSDLL_API I_VT(pPosition positions, const unsigned int &SmoothingNumber, const double &ThresholdSpeed);
		ALGORITHMCLASSDLL_API ~I_VT();
		ALGORITHMCLASSDLL_API virtual void classification();
	};
}