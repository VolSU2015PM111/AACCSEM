#include "stdafx.h"
#include "Algorithm.h"

namespace EyeMomentClassification
{
	BaseAlgorithm::BaseAlgorithm(pPosition positions, const unsigned int &SmoothingNumber) :Positions(&positions)
	{
		smoothingNumber = SmoothingNumber;
	}
	BaseAlgorithm::~BaseAlgorithm()
	{
	}
	eyeMomentsClasses BaseAlgorithm::operator[](const int &i) const
	{
		return std::find(ListClassification.begin(), ListClassification.end(), i)->state;
	}
	unsigned int BaseAlgorithm::size()
	{
		return priorListClassification.size();
	}
	void BaseAlgorithm::Merge()
	{
		eyeMomentClassList::iterator tmpIterator;
		eyeMomentClassCell cell;
		ListClassification.clear();
		for (eyeMomentClassList::iterator i = priorListClassification.begin(); i != priorListClassification.end(); ++i)
		{
			cell = *i;
			tmpIterator = i;
			while (++tmpIterator != priorListClassification.end()&&(tmpIterator)->state == cell.state)
			{
				cell.endindex = tmpIterator->endindex;
				++i;
			}
			ListClassification.push_back(cell);
		}
		for (eyeMomentClassList::iterator i = ListClassification.begin(); i != ListClassification.end(); ++i)
		{
			tmpIterator = i;
			while (++tmpIterator != ListClassification.end() && ((tmpIterator)->state == i->state || tmpIterator->endindex - tmpIterator->startindex<smoothingNumber))
			{
				i->endindex = tmpIterator->endindex;
				ListClassification.erase(tmpIterator);
				tmpIterator = i;
			}
		}
	}
}