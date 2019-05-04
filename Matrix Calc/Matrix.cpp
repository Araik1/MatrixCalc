#include "Matrix.h"

Matrix::Matrix()
{

    setSize(1, 1);
}

Matrix::Matrix(unsigned int rows)
{
    setSize(rows, rows);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            (i == j) ? mat[i][j] = 1 : mat[i][j] = 0;
        }
    }
}

Matrix::Matrix(unsigned int rows, unsigned int columns)
{
    setSize(rows, columns);
}

Matrix::Matrix(unsigned int rows, unsigned int columns, int lower, int upper)
{
    setSize(rows, columns);

    if (lower > upper)
    {
        int temp = lower;
        lower = upper;
        upper = temp;
    }

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            mat[i][j] = rand() % (upper - lower + 1) + lower;
        }
    }
}

Matrix::Matrix(Matrix &&matrix) //присваивания
{
    setSize(matrix.rows(), matrix.columns());

    for (int i = 0; i < rows(); i++)
    {
        for (int j = 0; j < columns(); j++)
        {
            mat[i][j] = matrix.element(i, j);
        }
    }
}

Matrix::Matrix(Matrix &matrix) //копирования
{
    *this = matrix;
}

Matrix::~Matrix()
{}

unsigned int Matrix::rows() const
{
    return mat.size();
}

unsigned int Matrix::columns() const
{
    return mat[0].size();
}

float Matrix::element(unsigned int i, unsigned int j) const
{
    return mat[i][j];
}

void Matrix::setSize(unsigned int rows, unsigned int columns)
{
    mat.resize(rows);
    for (int i = 0; i < mat.size(); i++)
        mat[i].resize(columns);
}

void Matrix::setElement(unsigned int row, unsigned int column, float data)
{
    mat[row][column] = data;
}

void Matrix::setRows(size_t rows)
{
    this->mat.resize(rows);
}

void Matrix::setColumns(size_t columns)
{
    auto r = this->rows();
    for (auto i = 0; i < r; i++)
        this->mat[i].resize(columns);
}

void Matrix::transp()
{
    double tmp = 0;
    for (auto i = 0; i < this->rows(); i++)
        for (auto j = i; j < this->columns(); j++)
        {
            tmp = this->mat[i][j];
            this->mat[i][j] = this->mat[j][i];
            this->mat[j][i] = tmp;
        }
}

Matrix Matrix::minor(unsigned int row, unsigned int column)
{ 
    Matrix temp_mat(rows() - 1, columns() - 1);

    int i = 0, j = 0;

    for (int a = 0; a < rows(); a++)
    {
        if (a != row)
        {

            for (int b = 0; b < columns(); b++)
            {
                if (b != column)
                {
                    temp_mat.setElement(i, j, element(a, b));
                    j += 1;
                }
            }

            j = 0;
            i += 1;
        }
    }

    return temp_mat;
}

float Matrix::det()
{
    int det = 0;

    if (columns() == rows())
    {
        if (rows() == 1)
            det = mat[0][0];
        else
        {
            if (rows() == 2)
                det = (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
            else
            {
                int k = 1;

                for (int i = 0; i < rows(); i++)
                {
                    det = det + k * mat[i][0] * minor(i, 0).det();
                    k *= -1;
                }
            }
        }
    }
    else
    {
        throw Exception(1, "invalid matrix format");
    }

    return det;
}

void Matrix::fill(float value)
{
    for (auto i = 0; i < this->rows(); i++)
              for (auto j = 0; j < this->columns(); j++)
              {
                  this->mat[i][j] = value;
              }
}

Matrix Matrix::operator + (const Matrix &matrix)
{
    Matrix nmat;
    if ((rows() == matrix.rows()) && (columns() == matrix.columns()))
    {
        nmat.setSize(rows(), columns());

        for (int i = 0; i < rows(); i++)
        {
            for (int j = 0; j < columns(); j++)
            {
                nmat.setElement(i, j, element(i, j) + matrix.element(i, j));
            }
        }
    }
    else
    {
        throw Exception(1, "invalid matrix format");
    }


    return nmat;
}

Matrix Matrix::operator - (const Matrix &matrix)
{
    Matrix nmat;
    if ((rows() == matrix.rows()) && (columns() == matrix.columns()))
    {
        nmat.setSize(rows(), columns());

        for (int i = 0; i < rows(); i++)
        {
            for (int j = 0; j < columns(); j++)
            {
                nmat.setElement(i, j, element(i, j) - matrix.element(i, j));
            }
        }
    }
    else
    {
        throw Exception(1, "invalid matrix format");
    }


    return nmat;
}

Matrix Matrix::operator* (float n)
{
    Matrix nmat;

    nmat.setSize(rows(), columns());

    for (int i = 0; i < rows(); i++)
    {
        for (int j = 0; j < columns(); j++)
        {
            nmat.setElement(i, j, (element(i, j) * n));
        }
    }

    return nmat;
}

Matrix Matrix::operator* (const Matrix &matrix)
{
    Matrix nmat;
    if (columns() == matrix.rows())
    {
        nmat.setSize(rows(), matrix.columns());

        for (int i = 0; i < nmat.rows(); i++)
        {
            for (int j = 0; j < nmat.columns(); j++)
            {
                for (int k = 0; k < matrix.rows(); k++)
                    nmat.setElement(i, j, nmat.element(i, j) + mat[i][k] * matrix.element(k, j));
            }
        }
    }
    else
    {
        throw Exception(1, "invalid matrix format");
    }


    return nmat;
}

Matrix & Matrix::operator= (Matrix &matrix)
{
    if (this != &matrix)
    {
        mat.clear();

        setSize(matrix.rows(), matrix.columns());

        for (int i = 0; i < rows(); i++)
        {
            for (int j = 0; j < columns(); j++)
            {
                //mat[i][j] = matrix.element(i, j);
                mat[i][j] = matrix.mat[i][j];
            }
        }
    }
    else
    {
        throw Exception(1, "invalid matrix format");
    }

    return *this;
}

Matrix & Matrix::operator= (Matrix &&matrix)
{
    if (this == &matrix)
        return *this;
    else
    {
        delete[] & mat;

        setSize(matrix.rows(), matrix.columns());

        for (int i = 0; i < rows(); i++)
        {
            for (int j = 0; j < columns(); j++)
            {
                mat[i][j] = matrix.element(i, j);
            }
        }
    }
    return *this;
}

