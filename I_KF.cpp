#include "stdafx.h"
#include "I_KF.h"

namespace EyeMomentClassification
{
	I_KF::I_KF(pPosition positions, const unsigned int &SmoothingNumber, const double &SigmaEtta, const double &SigmaPsi, double(*U)(const double& x), double(*W)(const double& y)) :BaseAlgorithm(positions, SmoothingNumber),
		SQRTEtta(SQRT(SigmaEtta)),
		SQRTpsi(SQRT(SigmaPsi)),
		u(U), w(W),
		smoothVector(positions),
		started(false)
	{
	}


	I_KF::~I_KF()
	{
	}

	void I_KF::classification()
	{
		double disperseOX, MathExpOX;
		double disperseOY, MathExpOY;
		double X2;
		std::vector<double> OX = Positions->OX();
		std::vector<double> OY = Positions->OY();
		std::vector<double> speed = Positions->speedArray();
		smoothVector[0] = Positions->at(0);
		Eopt = SQRTEtta;					
		for (unsigned int i = 1; i < Positions->size(); i++)
		{
			Eopt = (SQRTEtta*(Eopt + SQRTpsi)) / (SQRTEtta + Eopt + SQRTpsi);
			K = Eopt / SQRTEtta;			
			smoothVector[i].OX = u(smoothVector[i - 1].OX)*(1.0 - K) + K*Positions->at(i).OX;
			smoothVector[i].OY = w(smoothVector[i - 1].OY)*(1.0 - K) + K*Positions->at(i).OY;
		}
		
		MathExpOX = mathematicalExpectation(OX, 1/Positions->TimeBetweenMeasurements());
		MathExpOY = mathematicalExpectation(OY, 1/Positions->TimeBetweenMeasurements());

		disperseOX = dispersion(OX, MathExpOX);
		disperseOY = dispersion(OY, MathExpOY);
		
		X2 = x2(smoothVector.speedArray(), speed, (disperseOX+disperseOY)*0.5);

		priorListClassification.clear();
		for (unsigned int i = 0; i < speed.size(); i++)
			priorListClassification.push_back(eyeMomentClassCell{ i, i, (speed[i] > X2) ? saccade : fixation });
		Merge();
	}
	double I_KF::x2(const std::vector<double> &Thetta_, const const std::vector<double> &Thetta, const double &disperse)
	{
		double X2 = 0;
		double d = 1 / disperse;
		for (int i = 0; i < Thetta_.size() ; i++)
		{
			X2 += SQRT(Thetta_[i] - Thetta[i])*d;
		}
		return X2;
	}
}