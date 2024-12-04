#include <algorithm>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main() {

    std::ifstream inputFile("./input.txt");

    if (!inputFile){
        std::cerr << "error: cant open file" << std::endl;
        return 1;
    } 

    std::vector<int> firstID, secondID, diff;

    int val1, val2;

    while (inputFile >> val1 >> val2) {
        firstID.push_back(val1);
        secondID.push_back(val2);
    }

    inputFile.close();

    std::unordered_map<int, int> histogram;
    for(int num : secondID) {
        histogram[num]++;
    }

    int sum = 0;
    for (int value : firstID) {
        sum += value * histogram[value];
    }


    std::cout << "Final Summation: " << sum << std::endl; 

    return 0;
}