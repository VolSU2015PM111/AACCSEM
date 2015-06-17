#pragma once
#include "structures.h"

namespace EyeMomentClassification
{
	class Matrix											//матрица,"легко транспонируемая"
	{
	private:
		bool transport;
		double *matrix;
		int Columns, Rows;
	public:
		Matrix(const double *Matrix = NULL, int R = 0, int C = 0, bool t = false);
		double &operator()(int i, int j);
		void Transport(const bool& t);
		const bool &Transport();
		void SetParams(const double *Matrix = NULL, int R = 0, int C = 0, bool t = false);
	};
}

