#include <iostream>
#include "number.h"
#include "matrix.h"
using namespace std;

Matrix::Matrix(int Row, int Col) {
	Rows = Row;        // присвоим внутренним переменным переданные параметры
	Cols = Col;

	FloatData = new number * [Rows];

	for (int j = 0; j < Rows; j++) {
		FloatData[j] = new number[Cols];
		for (int i = 0; i < Cols; i++) {
			FloatData[j][i] = 0.0;
		}
	}
	return;
};

Matrix::~Matrix() {
	for (int j = 0; j < Rows; j++) {
		delete FloatData[j];
	}
	delete[] FloatData;
};

void Matrix::Fill() {
	cout << "\nКакого размера будет матрица ? ";
	cin >> Rows;
	Cols = Rows;

	delete FloatData;
	FloatData = new number * [Rows];
	for (int j = 0; j < Rows; j++) {
		FloatData[j] = new number[Cols];
		for (int i = 0; i < Cols; i++) {
			FloatData[j][i] = rand() % 20;
		}
	}
	return;
}

void Matrix::Fill2() {
	cout << "\nКакого размера будет матрица ? ";
	cin >> Rows;
	Cols = Rows;

	delete FloatData;
	FloatData = new number * [Rows];
	for (int j = 0; j < Rows; j++) {
		FloatData[j] = new number[Cols];
		for (int i = 0; i < Cols; i++) {
			cout << "\nРяд " << j + 1 << " Столбец " << i + 1 << " = ";
			cin >> FloatData[j][i];
			
		}
	}
	return;
}



void Matrix::Transport() {
	int t;
	for (int i = 0; i < Rows; i++) {
		for (int j = i; j < Cols; j++) {
			t = FloatData[i][j];
			FloatData[i][j] = FloatData[j][i];
			FloatData[j][i] = t;
		}
	}
}

void Matrix::Display() {
	cout << "\n";
	for (int j = 0; j < Rows; j++) {
		for (int i = 0; i < Cols; i++) {
			cout << FloatData[j][i] << "\t";
		}
		cout << "\n";
	}
	return;
}

double Matrix::FindDet() {
	number** helpMat = new number * [Rows];
	number det = 1;
	for (int i = 0; i < Rows; i++)
		helpMat[i] = new number[Rows];
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Rows; j++)
			helpMat[i][j] = FloatData[i][j];
	Triangle(helpMat);
	for (int i = 0; i < Rows; i++) {
		if (helpMat[i][i])
			det *= helpMat[i][i];
		else {
			det = 0;
			break;
		}
	}
	for (int i = 0; i < Rows; i++)
		delete[] helpMat[i];
	delete[] helpMat;
	return det;
}

void Matrix::Triangle(number** mat) {
	for (int i = 0; i < Rows - 1; i++) {
		if (!mat[i][i])
			for (int j = i + 1; j < Rows; j++)
				if (mat[j][i]) {
					swap(mat[i], mat[j]);
					break;
				}
		if (mat[i][i]) {
			number temp;
			for (int j = i + 1; j < Rows; j++) {
				temp = mat[j][i] / mat[i][i];
				for (int k = i; k < Rows; k++)
					mat[j][k] -= mat[i][k] * temp;
			}
		}
	}
}

int Matrix::Rank() {
	number** helpMat = new number * [Rows];
	int rank = 0;
	for (int i = 0; i < Rows; i++)
		helpMat[i] = new number[Rows];
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Rows; j++)
			helpMat[i][j] = FloatData[i][j];
	Triangle(helpMat);
	for (int i = 0; i < Rows; i++)
		if (helpMat[i][i])
			rank++;
	for (int i = 0; i < Rows; i++)
		delete[] helpMat[i];
	delete[] helpMat;
	return rank;
}