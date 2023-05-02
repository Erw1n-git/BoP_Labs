#include <iostream>
#include <string.h>

#include "Fraction.h"

#ifndef MATRIX_TEMPLATE_H
#define MATRIX_TEMPLATE_H

template <typename T>
class Matrix{

    template <typename U>
    friend std::istream& operator>>(std::istream& in, Matrix<U>& matrix);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, Matrix<U>& matrix);

    private:
        unsigned int rows;
        unsigned int columns;
        T** data;

    public:
        class OutOfBounds{
            int index;
            public:
                OutOfBounds(int i) : index(i) {}
                int getIndex() const {return index;}
        };

        class InvalidArgument{
            std::string err_message;
            public:
                InvalidArgument(std::string msg) : err_message(msg) {}
                std::string getMessage() const { return err_message; }
        };

        class MatrixOperationException{
            std::string err_message;
            public:
                MatrixOperationException(std::string msg) : err_message(msg) {}
                std::string getMessage() const { return err_message; }
        };

        Matrix(unsigned int rows, unsigned int columns);
        Matrix(Matrix& matrix);
        ~Matrix();

        unsigned int getRows() const;
        unsigned int getColumns() const;


        class RowProxy{
            private:
                int* data;
                unsigned int cols;

            public:
                RowProxy(int* data, unsigned int cols) {this->data = data; this->cols = cols;}
                int& operator[](unsigned int col) 
                {
                    if (col < 0 || col >= cols) 
                    {
                        throw OutOfBounds(col);
                    }
                    
                    return data[col];
                }
        };
        RowProxy operator[](unsigned int row) const 
        {
            if (row < 0 || row >= rows) 
            {
                throw OutOfBounds(row);
            }
            return RowProxy(data[row], columns);
        }

        Matrix<T> operator+(const Matrix& matrix) const;
        Matrix<T> operator-(const Matrix& matrix) const;
        Matrix<T> operator*(const Matrix& matrix) const;

};

#endif