#include "stdafx.h"
#include "I_MST.h"
#include "adjacencyMatrix.h"


namespace EyeMomentClassification
{

	I_MST::I_MST(pPosition positions, const unsigned int &SmoothingNumber, const double &TresholdDistance) :
		BaseAlgorithm(positions, SmoothingNumber),
		tresholdDistance(TresholdDistance)
	{
	}


	I_MST::~I_MST()
	{
	}
	void I_MST::classification()
	{
		adjacencyMatrix Matrix(Positions->OX(), Positions->OY());
		bool *StatePoint = new bool[Positions->size()];
		std::vector<int> Tree;
		std::vector<Pairintint> path;
		double mindistance;
		Pairintint candidate;
		double tmp;

		for (int i = 1; i < Positions->size(); i++)
			StatePoint[i] = true;

		Tree.push_back(0);								//��� ������� ����� ����� �������, ��� ��� �������� � �����
		StatePoint[0] = false;

		for (unsigned int i = 0; i < Positions->size() - 1; i++)					//���� � ������ �� ����� ��������� ��� �������
		{
			candidate = Pairintint(0, 0);
			mindistance = 100000;

			for (int j = 0; j < Tree.size(); j++)		//��� ������ ������� �� ������
			{
				for (unsigned int k = 0; k < Positions->size(); k++)
				if (StatePoint[k])					//������ �� ���������� �������
				{
					if (Matrix(Tree[j], k) < mindistance)
					{
						mindistance = Matrix(Tree[j], k);
						candidate = Pairintint(Tree[j], k);
						if (mindistance < 0)
							tmp = mindistance;
					}
				}
			}

			path.push_back(candidate);					//��������� ������ ���������
			Tree.push_back(candidate.second);			//��������� ������� � ������
			StatePoint[candidate.second] = false;		//�������� ������� ��� �� ���������
		}

		delete[] StatePoint;							//������ ���������

		priorListClassification.clear();
		for (unsigned int i = 0; i < Positions->size(); i++)
			priorListClassification.push_back(eyeMomentClassCell{ i, i, fixation });
		for (int i = 0; i < path.size(); i++)
		{
			if (Matrix(path[i].first, path[i].second) >= tresholdDistance)
			{
				priorListClassification[path[i].first].state = saccade;
				priorListClassification[path[i].second].state = saccade;
			}

		}
		Merge();
	}
}