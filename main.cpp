#include <iostream>
#include <regex>
#include "Distance.h"

int PrecisionNum(double d) {
    if (d == (int) d) {
        return 1;
    } else return 16;
}

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
    if (FirstVector.size() != SecondVector.size()) {
        std::cout << "the vectors are non equivalent";
        return 0;
    }
    double EuclideanNum, ManhattanNum, ChebyshevNum, CanberraNum, MinkowskiNum;
    EuclideanNum = Euclidean(FirstVector, SecondVector);
    ManhattanNum = Manhattan(FirstVector, SecondVector);
    ChebyshevNum = Chebyshev(FirstVector, SecondVector);
    CanberraNum = Canberra(FirstVector, SecondVector);
    MinkowskiNum = Minkowski(FirstVector, SecondVector, 2);
    std::fixed(std::cout);
    std::cout.precision(PrecisionNum(EuclideanNum));
    std::cout << EuclideanNum << std::endl;
    std::cout.precision(PrecisionNum(ManhattanNum));
    std::cout << ManhattanNum << std::endl;
    std::cout.precision(PrecisionNum(ChebyshevNum));
    std::cout << ChebyshevNum << std::endl;
    std::cout.precision(PrecisionNum(CanberraNum));
    std::cout << CanberraNum << std::endl;
    std::cout.precision(PrecisionNum(MinkowskiNum));
    std::cout << MinkowskiNum << std::endl;
    return 0;

}

