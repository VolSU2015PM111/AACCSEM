#pragma once

#include "Algorithm.h"
#include "EyeClassificationMacroses.h"
#include "functions.h"

namespace EyeMomentClassification
{
	class I_KF :
		public BaseAlgorithm
	{
	private:
		double Eopt;
		double SQRTEtta;	//получаем дсперсию замеров
		double SQRTpsi;	//получаем дсперсию предсказания
		double K;
		bool started;
		Position smoothVector;
		double(*u)(const double& x);
		double(*w)(const double& y);
		double x2(const std::vector<double> &Tetta_, const const std::vector<double> &Tetta, const double &disperse);
	public:
		ALGORITHMCLASSDLL_API I_KF(pPosition positions, const unsigned int &SmoothingNumber, const double &SigmaEtta, const double &SigmaPsi, double(*U)(const double& x), double(*W)(const double& y));
		ALGORITHMCLASSDLL_API ~I_KF();
		ALGORITHMCLASSDLL_API virtual void classification();
	};

}