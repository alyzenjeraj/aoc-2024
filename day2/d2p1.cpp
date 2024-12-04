#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {

    std::ifstream inputFile("./input.txt");

    if (!inputFile){
        std::cerr << "error: cant open file" << std::endl;
        return 1;
    } 

    std::vector<std::vector<int>> reports;

    std::string line;

    while(std::getline(inputFile, line)){
        std::istringstream lineStream(line);

        std::vector<int> report;
        int level;

        while (lineStream >> level) {
            report.push_back(level);
        }
        reports.push_back(report);
    }

    int safe_reports = 0;


    for(std::vector<int> report : reports) {

        int inc = 0;
        bool is_safe = false;

        for (size_t i = 1; i < report.size(); i++) {
            int diff = report[i] - report[i-1];
            
            if (abs(diff) > 3 or abs(diff) < 1) {
                is_safe = false;
                break;
            }
            

            if (inc == 0) {
                if (diff > 0) {
                    inc = 1;
                } else {
                    inc = -1;
                }
            } else {
                if ((diff/inc) != abs(diff)) {
                    is_safe = false;
                    break;
                }
            }


            
            is_safe = true;



        }

        if (is_safe)
            safe_reports++;
        

    }

    std::cout << "Final Sum of Safe Reports: " << safe_reports << std::endl;



    return 0;
}