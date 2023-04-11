#include "main.h"

int main(int argc, char** argv)
{
    Matrix matrix1(2, 3);
    Matrix matrix2(3, 2);
    try
    {
        matrix1[0][0] = 1;
        matrix1[0][1] = -4;
        matrix1[0][2] = 32;
        matrix1[1][0] = -54;
        matrix1[1][1] = 0;
        matrix1[1][2] = 6;

        matrix2[0][0] = 4;
        matrix2[0][1] = -64;
        matrix2[1][0] = 32;
        matrix2[1][1] = -54;
        matrix2[2][0] = 9;
        matrix2[2][1] = 26;
    }
    catch(Matrix::OutOfBounds& e)
    {
        std::cerr << "[Error] Wrong index: " << e.getIndex() << '\n';
    }
    
    unsigned int rows = 0, cols = 0;
    std::cout << "Enter matrix size(rows, columns): ";
    std::cin >> rows >> cols;

    Matrix matrix3(rows, cols);
    std::cout << "\nEnter the matrix values: " << std::endl;
    std::cin >> matrix3;

    try
    {
        std::cout << "\nMatrix sum: " << std::endl;
        Matrix sum_result = matrix1 + matrix3;
        std::cout << sum_result;

        std::cout << "\nMatrix diff: " << std::endl;
        Matrix diff_result = matrix1 - matrix3;
        std::cout << diff_result;

        std::cout << "\nMatrix mult: " << std::endl;
        Matrix mult_result = matrix1 * matrix2;
        std::cout << mult_result;
    }
    catch(Matrix::MatrixOperationException& e)
    {
        std::cerr << "[Error] " << e.getMessage() << '\n';
    }

    std::cout << "\nCalling individualTask for matrix3..." << std::endl;
    individualTask(matrix3);
    std::cout << matrix3;
    return 0;
}

void individualTask(Matrix& matrix)
{
    for (size_t i = 0; i < matrix.getRows(); i++)
    {
        for (size_t j = 0; j < matrix.getColumns(); j++)
        {
            if(int(matrix[i][j]) < 0 && matrix[i][j] % 2 != 0)
            {
                matrix[i][j] *= 2;
            }
        } 
    }
}