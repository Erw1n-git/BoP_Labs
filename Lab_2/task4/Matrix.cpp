#include "Matrix.h"

// ====== CONSTRUCTORS/DESTRUCTORS ======
Matrix::Matrix(unsigned int rows, unsigned int columns)
{
    if (rows <= 0 || columns <= 0) throw InvalidArgument("Invalid matrix size!");
    this->rows = rows;
    this->columns = columns;

    data = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = new int[columns];
        for (size_t j = 0; j < columns; j++)
        {
            data[i][j] = 0;
        }
        
    }
}

Matrix::Matrix(Matrix& matrix)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete data[i];
    }
    delete[] data;

    rows = matrix.rows;
    columns = matrix.columns;

    data = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = new int[columns];
        for (size_t j = 0; j < columns; j++)
        {
            data[i][j] = matrix.data[i][j];
        }
    }
}

Matrix::~Matrix()
{
    if (data != nullptr)
    {
        for (size_t i = 0; i < rows; i++)
        {
            delete data[i];
        }    
        delete[] data;
    }
}

// ====== GETTERS ======
unsigned int Matrix::getRows() const
{
    return rows;
}

unsigned int Matrix::getColumns() const
{
    return columns;
}

// ====== OPERATORS ======
std::istream& operator>>(std::istream& in, Matrix& matrix)
{
    for (size_t i = 0; i < matrix.rows; i++)
    {
        for (size_t j = 0; j < matrix.columns; j++)
        {
            std::cout << "matrix[" << i << "][" << j << "]: ";
            if (!(in >> matrix.data[i][j]))
            {
                throw Matrix::MatrixOperationException("Invalid input");
            }
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Matrix& matrix)
{
    for (size_t i = 0; i < matrix.rows; i++)
    {
        for (size_t j = 0; j < matrix.columns; j++)
        {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

Matrix Matrix::operator+(const Matrix& matrix) const
{
    if (rows != matrix.rows || columns != matrix.columns)
    {
        throw MatrixOperationException("Matrices are not the same size!");
    }

    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            result[i][j] = data[i][j] + matrix.data[i][j];
        }
        
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& matrix) const
{
    if (rows != matrix.rows || columns != matrix.columns)
    {
        throw MatrixOperationException("Matrices are not the same size!");
    }

    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            result[i][j] = data[i][j] - matrix.data[i][j];
        }
        
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
    if (columns != matrix.rows)
    {
        throw MatrixOperationException("The number of columns of the first matrix should match the number of rows of the second matrix!");
    }

    Matrix result(rows, matrix.columns);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < matrix.columns; ++j)
        {
            int sum = 0;
            for (size_t k = 0; k < columns; ++k)
            {
                sum += data[i][k] * matrix.data[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;    
}