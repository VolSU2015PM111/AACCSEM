#include "stdafx.h"
#include "I_DT.h"

namespace EyeMomentClassification
{

	I_DT::I_DT(pPosition positions, const unsigned int &SmoothingNumber, const unsigned int &Steps, const double &StepDispersion, const unsigned int &minDSteps) :
		BaseAlgorithm(positions, SmoothingNumber),
		steps(Steps),
		stepDispersion(StepDispersion),
		minDsteps(minDSteps)
	{
	}

	I_DT::~I_DT()
	{
	}
	void I_DT::classification()
	{
		priorListClassification.clear();
		dispersion(0);
		Merge();
	}
	void I_DT::dispersion(const unsigned int &start)
	{
		unsigned int n = min(steps, Positions->size() - start);
		std::vector<double> X = Positions->OX(), Y = Positions->OY();
		if (n <= minDsteps)
		{
			for (unsigned int i = 0; i < n + 1; i++)
			{
				priorListClassification.push_back(eyeMomentClassCell{ start + i, start + i, fixation });
			}
			return;
		}
		double MinX = X[start], MinY = Y[start], MaxX = X[start], MaxY = Y[start];
		double D;
		for (unsigned int i = 1; i < n; i++)
		{
			if (MinX>X[start + i])MinX = X[start + i];
			if (MaxX<X[start + i])MaxX = X[start + i];
			if (MinY>Y[start + i])MinY = Y[start + i];
			if (MaxY<Y[start + i])MaxY = Y[start + i];
		}
		D = MaxX - MinX + MaxY - MinY;
		if (D >= stepDispersion)
		{
			priorListClassification.push_back(eyeMomentClassCell{ start, start,saccade  });
			dispersion(start + 1);
		}
		else
		{
			for (unsigned int i = 0; i < n; i++)
			{
				priorListClassification.push_back(eyeMomentClassCell{ start + i, start + i, fixation });
			}
			dispersion(start + n);
		}
		
	}
	unsigned int I_DT::size()
	{
		return priorListClassification.size()-1;
	}
}