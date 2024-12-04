#include <algorithm>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {

    std::ifstream inputFile("./day1.txt");

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

    std::sort(firstID.begin(), firstID.end());
    std::sort(secondID.begin(), secondID.end());

    int sum = 0;
    for (size_t i = 0; i < firstID.size(); i++) {
        diff.push_back(abs(firstID[i] - secondID[i]));
        std::cout << diff[i] << std::endl;
        sum += diff[i];
    }


    std::cout << "Final Summation: " << sum << std::endl; 

    return 0;
}