#include "VectorCreation.h"
#include "Distance.h"
#include <iostream>
#include <sstream>

int PrecisionNum(double d) {
    if (d == (int) d) {
        return 1;
    } else return 16;
}

int NumCheck(std::string s) {
    int i, flag = 0, flag2 = 0;
    // This is checking if the first character is a digit or a minus sign.
    if (!isdigit(s.at(0)) && (s.at(0) != 45)) {
        return 0;
    }
    // This is checking if the string is a number.
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
    // This is checking if the string is empty.
    if (TextLine.empty()) {
        return 0;
    }
    // This is checking if the first character is a space.
    if (TextLine.at(0) >= 1 && TextLine.at(0) <= 32) {
        return 0;
    }
    // This is checking if there are two spaces in a row.
    for (i = 1; i < TextLine.size(); i++) {
        if (TextLine.at(i) >= 1 && TextLine.at(i) <= 31) {
            return 0;
        }
        if (TextLine.at(i - 1) == 32 && TextLine.at(i) == 32) {
            return 0;
        }
    }
    return 1;
}

int InsertToVector(std::vector<double> &vector) {
    std::string TextLine;
    getline(std::cin, TextLine);
    // This is checking if the string is empty.
    if (!StringValidation(TextLine))
        return 0;
    std::istringstream LineStream(TextLine);
    std::string s;
    /* This is checking if the string is a number. */
    while (LineStream >> s) {
        if (!NumCheck(s)) {
            return 0;
        }
        try {
            double d = stod(s);
            vector.push_back(d);
        }
        catch (std::exception &e) {
            return 0;
        }
    }
    LineStream.clear();
    return 1;
}

int CalculateDistance(std::vector<double> &FirstVector, std::vector<double> &SecondVector) {
    /* This is checking if the vectors are the same size. */
    if (FirstVector.size() != SecondVector.size()) {
        std::cout << "the vectors are non equivalent";
        return 0;
    }
    double EuclideanNum, ManhattanNum, ChebyshevNum, CanberraNum, MinkowskiNum;
    //calculating all the algorithms
    EuclideanNum = Euclidean(FirstVector, SecondVector);
    ManhattanNum = Manhattan(FirstVector, SecondVector);
    ChebyshevNum = Chebyshev(FirstVector, SecondVector);
    CanberraNum = Canberra(FirstVector, SecondVector);
    MinkowskiNum = Minkowski(FirstVector, SecondVector, 2);
    //printing all the results
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
    return 1;
}