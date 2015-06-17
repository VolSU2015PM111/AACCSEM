#pragma once
#include "Algorithm.h"

namespace EyeMomentClassification
{

	class I_DT :
		public BaseAlgorithm
	{
	private:
		unsigned int steps;
		double stepDispersion;
		unsigned int minDsteps;
		void dispersion(const unsigned int &n);
	public:
		ALGORITHMCLASSDLL_API I_DT(pPosition positions, const unsigned int &SmoothingNumber, const unsigned int &Steps, const double &StepDispersion, const unsigned int &minDSteps);
		ALGORITHMCLASSDLL_API ~I_DT();
		ALGORITHMCLASSDLL_API virtual void classification();
		ALGORITHMCLASSDLL_API virtual unsigned int size();
	};

}