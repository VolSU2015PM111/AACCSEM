#pragma once
#include "constantes.h"
#include <cmath>
#include <vector>

namespace EyeMomentClassification
{
	class adjacencyMatrix
	{
	private:
		double** distance;					//������� ����� ���
		int Npoints;						//�� ������� ����� ����� �������
	public:
		adjacencyMatrix(const std::vector<double> &X,const std::vector<double> &Y);
		adjacencyMatrix(const adjacencyMatrix& AM);
		~adjacencyMatrix();

		const double &operator()(const int& i, const int& j);
	};
}