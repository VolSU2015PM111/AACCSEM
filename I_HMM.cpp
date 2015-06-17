#include "stdafx.h"
#include "I_HMM.h"

namespace EyeMomentClassification
{

	I_HMM::I_HMM(pPosition positions, const unsigned int &SmoothingNumber, const StateProbility &StartProbability, double TransposedTransitionMatrixSTART[NClasses][NClasses], double EmissionProbability[NStates][NClasses], const double& ThresholdSpeed) :
		BaseAlgorithm(positions, SmoothingNumber),
		startProbability(StartProbability),
		transposedTransitionMatrix(&(TransposedTransitionMatrixSTART[0][0]), NClasses, NClasses, true),
		thresholdSpeed (ThresholdSpeed)
	{
		for (int i = 0; i < NStates; i++)
		for (int j = 0; j < NClasses; j++)
			emissionProbability[i][j] = EmissionProbability[i][j];
	}


	I_HMM::~I_HMM()
	{
	}
	void I_HMM::classification()
	{
		StateProbility P;
		double tmpprobility;
		int tmpstate;
		std::vector<double> Speed = Positions->speedArray();
		std::vector<eyeMomentsHidenStates> observation(Speed.size());
		for (unsigned int i = 0; i < Speed.size(); i++)
			observation[i] = Speed[i] < thresholdSpeed ? slow : fast;
		for (int i = 0; i < NClasses; i++)
			P[i] = emissionProbability[observation[0]][i] * startProbability[i];
		viterbyPatch VPath(Speed.size(), P);
		viterbyPatch VPathTmp(VPath);
		for (unsigned int i = 1; i < observation.size(); i++)
		{
			for (int j = 0; j < NClasses; j++)
			{
				P[j] = 0;
				tmpstate = 0;
				for (int k = 0; k < NClasses; k++)
				{
					tmpprobility = VPath.Probability(i - 1)[k] * transposedTransitionMatrix(k, j)*emissionProbability[observation[i]][j];
					if (tmpprobility>P[j])
					{
						P[j] = tmpprobility;								//сохраняем лучшее состояние
						tmpstate = k;										//состояние на котором достигается лутшее состояние
					}
				}
				VPathTmp.push((eyeMomentsClasses)j, VPath, (eyeMomentsClasses)tmpstate);
			}
			VPath = VPathTmp;
			VPath.Probability(i) = P;
		}
		priorListClassification.clear();
		for (unsigned int i = 0; i < observation.size(); i++)
			priorListClassification.push_back(eyeMomentClassCell{ i, i, VPath((eyeMomentsClasses)tmpstate, i) });
		Merge();
	}
}