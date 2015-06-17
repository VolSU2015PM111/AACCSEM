#pragma once
#include "Algorithm.h"

namespace EyeMomentClassification
{

	class I_MST :
		public BaseAlgorithm
	{
	private:
		double tresholdDistance;
	public:
		ALGORITHMCLASSDLL_API I_MST(pPosition positions, const unsigned int &SmoothingNumber, const double &tresholdDistance);
		ALGORITHMCLASSDLL_API ~I_MST();
		ALGORITHMCLASSDLL_API virtual void classification();
	};

}