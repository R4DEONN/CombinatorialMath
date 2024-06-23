#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<int>> Matrix;

inline Matrix GetKirchhoffMatrix(const Matrix& adjMatrix)
{
	int n = adjMatrix.size();
	Matrix kirchhoff(n, std::vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		int degree = 0;
		for (int j = 0; j < n; ++j) {
			if (adjMatrix[i][j] != 0) {
				degree++;
				kirchhoff[i][j] = -adjMatrix[i][j];
			}
		}
		kirchhoff[i][i] = degree;
	}

	return kirchhoff;
}


inline int Determinant(Matrix matrix, int n)
{
	int det = 1;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			while (matrix[j][i] != 0)
			{
				int t = matrix[i][i] / matrix[j][i];
				for (size_t k = i; k < n; k++)
				{
					matrix[i][k] -= t * matrix[j][k];
				}
				for (size_t k = i; k < n; k++)
				{
					std::swap(matrix[i][k], matrix[j][k]);
				}
				det = -det;
			}
		}
		det *= matrix[i][i];
	}

	return det;
}

inline int CountSpanningTrees(const std::vector<std::vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	Matrix kirchhoff = GetKirchhoffMatrix(adjMatrix);

	Matrix submatrix(n - 1, std::vector<int>(n - 1));
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			submatrix[i - 1][j - 1] = kirchhoff[i][j];
		}
	}

	return Determinant(submatrix, n - 1);
}
