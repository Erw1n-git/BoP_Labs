#include <iostream>
#include <map>
#include <set>

int main() 
{
    std::map<int, int> countMap;
    std::set<int> exclusionSet = {5, 10, 15};
    int num;

    std::cout << "Enter numbers: ";
    while (std::cin >> num) 
    {
        if (exclusionSet.find(num) != exclusionSet.end()) 
        {
            std::cout << "Number " << num << " is in the exclusion list!" << std::endl;
            continue;
        }
        countMap[num]++;
    }

    std::cout << "\nCounts of each number: " << std::endl;
    for (auto& pair : countMap) 
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}