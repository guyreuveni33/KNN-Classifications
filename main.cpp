#include <iostream>
#include <sstream>
#include <regex>
#include "Distance.h"

int PrecisionNum(double d) {
    if (d == (int) d) {
        return 1;
    } else return 16;
}

int numCheck(std::string s) {
    int i, flag = 0, flag2 = 0;
    if (!isdigit(s.at(0)) && (s.at(0) != 45)) {
        return 0;
    }
    for (i = 0; i < s.size(); i++) {
        if ((s.at(0) == 45) && (s.size() > 1) && flag2 == 0) {
            flag2 = 1;
            continue;
        }
        if (!(isdigit(s.at(i)))) {
            if (s.at(i) == 46) {
                if (i == s.size() - 1) {
                    return 0;
                }
                flag++;
                continue;
            }
            return 0;
        }
        if (flag >= 2) {
            return 0;
        }
    }
    return 1;
}

int StringValidation(std::string TextLine) {
    int i;
    if (TextLine.empty()) {
        std::cout << "N";
        return 0;

    }
    if (TextLine.at(0) >= 1 && TextLine.at(0) <= 32) {
        std::cout << "0E";
        return 0;
    }
    for (i = 1; i < TextLine.size(); i++) {
        if (TextLine.at(i) >= 1 && TextLine.at(i) <= 31) {
            std::cout << "Werror";
            return 0;
        }
        if (TextLine.at(i - 1) == 32 && TextLine.at(i) == 32) {
            std::cout << "error";
            return 0;
        }
    }
    return 1;
}

int main() {
    std::vector<double> FirstVector, SecondVector;
    std::string TextLineOne;
    std::string TextLineTwo;
    getline(std::cin, TextLineOne);
    if (!StringValidation(TextLineOne))
        return 0;
    std::istringstream LineStream(TextLineOne);
    std::string s;
    while (LineStream >> s) {
        if (!numCheck(s)) {
            std::cout << "error2";
            return 0;
        }
        try {
            double d = stod(s);
            FirstVector.push_back(d);
        }
        catch (std::exception &e) {
            std::cout << "errorEEEEE";
            return 0;
        }
    }
    LineStream.clear();
    getline(std::cin, TextLineTwo);
    if (!StringValidation(TextLineTwo))
        return 0;
    LineStream.str(TextLineTwo);
    std::string s2;
    while (LineStream >> s2) {
        if (!numCheck(s2)) {
            std::cout << "error2";
            return 0;
        }
        try {
            double d2 = stod(s2);
            SecondVector.push_back(d2);
        }
        catch (std::exception &e2) {
            std::cout << "errorEEEEE";
            return 0;

        }
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

