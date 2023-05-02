#include <iostream>

int sum = 10;
class SumOfIntegers {
private:
    int data;
    static int sum;

public:
    SumOfIntegers(int value) : data(value) {
        ::sum += data;
    }

    int getData() const {
        return data;
    }

    static int getSum() {
        return ::sum;
    }
};

int SumOfIntegers::sum = 0;

int main() {
    SumOfIntegers a(5);
    SumOfIntegers b(10);
    SumOfIntegers c(15);

    std::cout << "Sum of integers: " << SumOfIntegers::getSum() << std::endl;

    return 0;
}