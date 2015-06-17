#pragma once
#include <algorithm>
#include "Position.h"
#include "structures.h"
#include "EyeClassificationMacroses.h"


namespace EyeMomentClassification
{
	typedef class Position* uPosition;
	typedef class Position& pPosition;
	class BaseAlgorithm
	{
	protected:
		eyeMomentClassList ListClassification;
		eyeMomentClassList priorListClassification;
		uPosition Positions;
		unsigned int smoothingNumber;
		void Merge();
		BaseAlgorithm(pPosition positions, const unsigned int &SmoothingNumber);
	public:
		ALGORITHMCLASSDLL_API ~BaseAlgorithm();
		ALGORITHMCLASSDLL_API virtual void classification()=0;
		ALGORITHMCLASSDLL_API eyeMomentsClasses operator[](const int &i) const;
		ALGORITHMCLASSDLL_API virtual unsigned int size();
	};
}
