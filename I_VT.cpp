#include "stdafx.h"
#include "I_VT.h"

namespace EyeMomentClassification
{
	I_VT::I_VT(pPosition positions, const unsigned int &SmoothingNumber, const double &ThresholdSpeed) :BaseAlgorithm(positions, SmoothingNumber), thresholdSpeed (ThresholdSpeed)
	{
	}


	I_VT::~I_VT()
	{
	}
	void I_VT::classification()
	{
		priorListClassification.clear();
		std::vector<double> SpeedArray = Positions->speedArray();
		for (unsigned int i = 0; i < SpeedArray.size(); i++)
			priorListClassification.push_back(eyeMomentClassCell{ i, i, SpeedArray[i] < thresholdSpeed ? fixation : saccade });
		Merge();
	}
}
