#pragma once
#include <vector>

#include "Exception.h"

using namespace std;

class Matrix
{
private:
	vector <vector <float>> mat;

public:
	Matrix();
	Matrix(unsigned int rows);
	Matrix(unsigned int rows, unsigned int columns);
	Matrix(unsigned int rows, unsigned int columns, int lower, int upper);
	Matrix(Matrix &&matrix); //присваивания
	Matrix(Matrix &matrix); //копирования

	~Matrix();

	unsigned int rows() const;
	unsigned int columns() const;

	float element(unsigned int i, unsigned int j) const;
    void setElement(unsigned int row, unsigned int column, float data);

    void setRows(size_t rows);
    void setColumns(size_t columns);
    void setSize(unsigned int rows, unsigned int columns);


    void transp();
	Matrix minor(unsigned int row, unsigned int column);
    float det();
    void fill(float value);

	Matrix operator + (const Matrix &matrix);
	Matrix operator - (const Matrix &matrix);
	Matrix operator * (float n);
	Matrix operator * (const Matrix &matrix);
    Matrix & operator=(Matrix &matrix);
    Matrix & operator=(Matrix &&matrix);
};

