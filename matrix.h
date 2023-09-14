#include "number.h"

class Matrix
{
private:
	int Rows;
	int Cols;
	number** FloatData;

public:
	Matrix(int Row = 1, int Col = 1);
	~Matrix(void);
	void Display();
	void MinMax(int Row);
	void Fill();
	void Fill2();
	void Transport();
	double FindDet();
	double Findrang();
	void Triangle(number** mat);
	int Rank();
};

