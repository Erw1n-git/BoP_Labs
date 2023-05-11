#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns)
{
    if (rows <= 0 || columns <= 0) throw InvalidArgument("Invalid matrix size!");
    data.resize(rows, std::vector<int>(columns, 0));
}

// ==== GETTERS ====
unsigned int Matrix::getRows() const
{
    return data.size();
}

unsigned int Matrix::getColumns() const
{
    return data[0].size();
}

// ==== OPERATORS ====
std::vector<int>& Matrix::operator[](unsigned int row)
{
    if (row >= getRows()) 
    {
        throw OutOfBounds(row);
    }
    return data[row];
}

const std::vector<int>& Matrix::operator[](unsigned int row) const
{
    if (row >= getRows()) 
    {
        throw OutOfBounds(row);
    }
    return data[row];
}

std::istream& operator>>(std::istream& in, Matrix& matrix)
{
    for (size_t i = 0; i < matrix.getRows(); i++)
    {
        for (size_t j = 0; j < matrix.getColumns(); j++)
        {
            std::cout << "matrix[" << i << "][" << j << "]: ";
            if (!(in >> matrix[i][j]))
            {
                throw Matrix::MatrixOperationException("Invalid input");
            }
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
    for (size_t i = 0; i < matrix.getRows(); i++)
    {
        for (size_t j = 0; j < matrix.getColumns(); j++)
        {
            out << matrix[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

Matrix Matrix::operator+(const Matrix& matrix) const
{
    if (getRows() != matrix.getRows() || getColumns() != matrix.getColumns())
    {
        throw MatrixOperationException("Matrices are not the same size!");
    }

    Matrix result(getRows(), getColumns());
    for (size_t i = 0; i < getRows(); i++)
    {
        for (size_t j = 0; j < getColumns(); j++)
        {
            result[i][j] = data[i][j] + matrix[i][j];
        }
        
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& matrix) const
{
    if (getRows() != matrix.getRows() || getColumns() != matrix.getColumns())
    {
        throw MatrixOperationException("Matrices are not the same size!");
    }

    Matrix result(getRows(), getColumns());
    for (size_t i = 0; i < getRows(); i++)
    {
        for (size_t j = 0; j < getColumns(); j++)
        {
            result[i][j] = data[i][j] - matrix[i][j];
        }
        
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
    if (getColumns() != matrix.getRows())
    {
        throw MatrixOperationException("The number of columns of the first matrix should match the number of rows of the second matrix!");
    }

    Matrix result(getRows(), matrix.getColumns());
    for (size_t i = 0; i < getRows(); ++i)
    {
        for (size_t j = 0; j < matrix.getColumns(); ++j)
        {
            int sum = 0;
            for (size_t k = 0; k < getColumns(); ++k)
            {
                sum += data[i][k] * matrix[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}
