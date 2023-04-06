#include <iostream>
#include <cmath>
#include <fstream>

// Creating LinkedList
struct Link
{
    int data;
    Link *next;
};

// Reading the file and writing elements to LinkedList
void readFile(Link* &head, std::ifstream &inputFile)
{
    if (!inputFile)
    {
        std::cout << "Unable to open file" << std::endl;
        inputFile.close();
        return;
    }

    int value;
    while (inputFile >> value)
    {
        Link* link = new Link;
        link->data = value;
        link->next = head;
        head = link;
    }

    inputFile.close();
}

// Creating and filling a 2D array using LinkedList
void createAndFillArray(int** &arr, Link* head, int &m, const int n)
{

    int count = 0;
    const Link* link = head;
    while (link != 0)
    {
        count++;
        link = link->next;
    }

    // Calculating the number of rows based on the number of values and the number of columns
    m = std::ceil(static_cast<double>(count) / n);

    arr = new int*[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    // Filling the array with values from the linked list
    link = head;
    int i = 0, j = 0;
    while (link != 0)
    {
        arr[i][j] = link->data;
        link = link->next;
        j++;

        if (j == n)
        {
            j = 0;
            i++;
        }
    }

    // Filling any remaining elements in the last row with 0
    if(j != 0)
    {
        while (j < n)
        {
            arr[i][j] = 0;
            j++;
        }
    }
} 

// Writing int** array into the output file
void writeFile(std::ofstream &outputFile, int** arr, int cols, int rows)
{
    outputFile << "Step1 array elements are: " << "\n";
    for (int i = cols - 1; i >= 0; i--)
    {
        for (int j = rows - 1; j >= 0; j--)
        {
            outputFile << arr[i][j] << " ";
        }
        outputFile << "\n";
    }
}

// Writing double* array into the output file
void writeFile(std::ofstream &outputFile, double* arr, int size)
{
    outputFile << "Step2 array elements are: " << "\n";
    for (int i = size - 1; i >= 0; i--)
    {
        outputFile << arr[i] << " ";
    }
    outputFile << "\n";
}

// Deleting LinkedList from memory
void deleteList(Link** head)
{
    Link* link = *head;
    Link* next;
    while (link != NULL) {
        next = link->next;
        delete link;
        link = next;
    }
    *head = NULL;
}

// Deleting double* array from memory
void deleteArray(double* arr)
{
    delete[] arr;
}

// Deleting int** array from memory
void deleteArray(int** arr, int rows)
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void step1(int** &arr, const int m, const int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i][j] < 0) && (arr[i][j] % 2 != 0))
            {
                arr[i][j] *= 2;
            }
        }
    }
}

void step2(int** &arr, const int m, const int n, double outArr[])
{
    int elCount = 0;

    for (int i = 0; i < m; i++)
    {
        double logsum = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > 0)
            {
                logsum += std::log10(arr[i][j]);
            }
        }

        outArr[elCount] = logsum;
        elCount++;
    }
}

int main()
{
    const int n = 3;
    int m = 0;
    int **array2D = 0;
    double *array = 0;

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    Link* head = 0;

    std::cout << "** Reading and filling an array from file..." << std::endl;
    readFile(head, inputFile);
    createAndFillArray(array2D, head, m, n);
    array = new double[m];

    deleteList(&head);

    std::cout << "** Completing step1..." << std::endl;
    step1(array2D, m, n);
    std::cout << "** Completing step2..." << std::endl;
    step2(array2D, m, n, array);

    std::cout << "** Writing arrays to file..." << std::endl;
    writeFile(outputFile, array2D, m, n);
    writeFile(outputFile, array, m);

    std::cout << "** Cleaning allocated memory..." << std::endl;
    deleteArray(array);
    deleteArray(array2D, m);

    std::cout << "\nFinished." << std::endl;

    return 0;
}