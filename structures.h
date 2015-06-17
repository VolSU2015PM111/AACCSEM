#pragma once
#include <vector>
#include "constantes.h"
#include "EyeClassificationMacroses.h"

namespace EyeMomentClassification
{
	

	struct eyeMomentClassCell
	{
		int startindex;
		int endindex;
		eyeMomentsClasses state;
		bool operator==(const int &i) const { return startindex <= i && endindex >= i; }
	};
	typedef std::vector<eyeMomentClassCell> eyeMomentClassList;
	typedef std::pair<int, int> Pairintint;
	typedef std::pair<Pairintint, double> Threeintintdouble;

	

	struct EyeMomentPosition
	{
		double OX;
		double OY;

		double distance(const EyeMomentPosition& secondPos)
		{
			return sqrt((OX - secondPos.OX)*(OX - secondPos.OX) + (OY - secondPos.OY)*(OY - secondPos.OY));
		}
	};
	struct StateProbility									//вероятность состояний
	{
		double Prob[NClasses];								//вероятность наступления событий
		double &operator[](const int&i)
		{
			return Prob[i];
		}
	};
}