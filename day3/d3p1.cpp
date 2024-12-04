#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

int main() {

    std::ifstream inputFile("./input.txt");

    if (!inputFile){
        std::cerr << "error: cant open file" << std::endl;
        return 1;
    } 

    

    char ch;

    std::vector<char> mult;

    while(inputFile >> std::noskipws >> ch) {
        if (ch == 'm' && mult.empty()) {
            mult.push_back(ch);
        } else if(ch == 'u' && mult == std::vector<char>{'m'}) {
            mult.push_back(ch);
        } else if(ch == 'l' && mult == std::vector<char>{'m', 'u'}) {
            mult.push_back(ch);
        } else if(ch == '(' && mult == std::vector<char>{'m', 'u', 'l'}) {
            mult.push_back(ch);
        } else if (std::isdigit(ch)) {
            // Haven't read in a number yet
            if (mult == std::vector<char>{'m', 'u', 'l', '('}) {

            }
        }
        
    }

    



    return 0;
}