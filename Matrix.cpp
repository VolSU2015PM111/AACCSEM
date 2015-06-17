#include "stdafx.h"
#include "Matrix.h"

namespace EyeMomentClassification
{
	Matrix::Matrix(const double *Matrix, int R, int C, bool t)
	{
		SetParams(Matrix, R, C, t);
	}

	double &Matrix::operator()(int i, int j)
	{
		int k;
		if (transport)
		{
			k = i;
			i = j;
			j = k;
		}
		return *(matrix + i*Columns + j);
	}
	void Matrix::Transport(const bool &t)
	{
		transport = t;
	}
	const bool &Matrix::Transport()
	{
		return transport;
	}
	void Matrix::SetParams(const double *Matrix, int R, int C, bool t)
	{
		transport = t;
		matrix = new double[C*R];
		Columns = C;
		Rows = R;
		for (int i = 0; i < C*R; i++)
			matrix[i] = Matrix[i];
	}
}
