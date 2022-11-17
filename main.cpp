#include <iostream>
#include <vector>
#include <sstream>
#include <regex>


int main() {
    std::vector<double> FirstVector, SecondVector;
    std::string TextLineOne;
    std::string TextLineTwo;
    getline(std::cin, TextLineOne);
    double num;
    std::istringstream LineStream(TextLineOne);
    std::regex rx("(([-]?([0-9]+[\\.])?([0-9]+))([“ “])?)(([“ “][-]?([0-9]+[\\.])?([0-9]+))([“ “])?)*");
    while (!std::regex_match(TextLineOne, rx)) {
        std::cout << "error\n";
        LineStream.clear();
        getline(std::cin, TextLineOne);
        LineStream.str(TextLineOne);
        }
    while (LineStream >> num) {
        FirstVector.push_back(num);
    }
    LineStream.clear();
    getline(std::cin, TextLineTwo);
    LineStream.str(TextLineTwo);
    while (!std::regex_match(TextLineTwo, rx)) {
        std::cout << "error\n";
        LineStream.clear();
        getline(std::cin, TextLineTwo);
        LineStream.str(TextLineTwo);
    }
    while (LineStream >> num) {
        SecondVector.push_back(num);
    }
    for (int i = 0; i < FirstVector.size(); i++)
        std::cout << FirstVector.at(i) << ' ';

    for (int i = 0; i < SecondVector.size(); i++)
        std::cout << SecondVector.at(i) << ' ';

    return 0;


}

