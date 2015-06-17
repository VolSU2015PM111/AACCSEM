#pragma once
#include "Algorithm.h"
#include "EyeClassificationMacroses.h"
#include "functions.h"
#include "viterbyPatch.h"
#include "Matrix.h"

namespace EyeMomentClassification
{
	class I_HMM :
		public BaseAlgorithm
	{
	private:
		StateProbility startProbability;						//сначала вероятности равны
		double thresholdSpeed;
		double emissionProbability[NStates][NClasses] ;					//[i][j]вероятность наступления события j, при состоянии i
		Matrix transposedTransitionMatrix;
	public:
		ALGORITHMCLASSDLL_API I_HMM(pPosition positions, const unsigned int &SmoothingNumber, const StateProbility &StartProbability, double TransposedTransitionMatrixSTART[NClasses][NClasses], double EmissionProbability[NStates][NClasses], const double& ThresholdSpeed);
		ALGORITHMCLASSDLL_API ~I_HMM();
		ALGORITHMCLASSDLL_API virtual void classification();
	};
}