#include <iostream>
#include <vector>
#include <string>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix{

    friend std::istream& operator>>(std::istream& in, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

    private:
        std::vector<std::vector<int>> data;

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
        unsigned int getRows() const;
        unsigned int getColumns() const;

        std::vector<int>& operator[](unsigned int row);
        const std::vector<int>& operator[](unsigned int row) const;

        Matrix operator+(const Matrix& matrix) const;
        Matrix operator-(const Matrix& matrix) const;
        Matrix operator*(const Matrix& matrix) const;
};

#endif