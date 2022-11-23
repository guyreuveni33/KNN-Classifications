#include "VectorCreation.h"
#include "Distance.h"
#include <iostream>
#include <sstream>

int precisionNum(double d) {
    if (d == (int) d) {
        return 1;
    } else return 16;
}

int numCheck(std::string s) {
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

int stringValidation(std::string textLine) {
    int i;
    // This is checking if the string is empty.
    if (textLine.empty()) {
        return 0;
    }
    // This is checking if the first character is a space.
    if (textLine.at(0) >= 1 && textLine.at(0) <= 32) {
        return 0;
    }
    // This is checking if there are two spaces in a row.
    for (i = 1; i < textLine.size(); i++) {
        if (textLine.at(i) >= 1 && textLine.at(i) <= 31) {
            return 0;
        }
        if (textLine.at(i - 1) == 32 && textLine.at(i) == 32) {
            return 0;
        }
    }
    return 1;
}

int insertToVector(std::vector<double> &vector) {
    std::string textLine;
    getline(std::cin, textLine);
    // This is checking if the string is empty.
    if (!stringValidation(textLine))
        return 0;
    std::istringstream lineStream(textLine);
    std::string s;
    // This is checking if the string is a number.
    while (lineStream >> s) {
        if (!numCheck(s)) {
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
    lineStream.clear();
    return 1;
}

int calculateDistance(std::vector<double> &firstVector, std::vector<double> &secondVector) {
    // This is checking if the vectors are the same size.
    if (firstVector.size() != secondVector.size()) {
        std::cout << "the vectors are not of the same size";
        return 0;
    }
    double euclideanNum, manhattanNum, chebyshevNum, canberraNum, minkowskiNum;
    //calculating all the algorithms
    euclideanNum = euclidean(firstVector, secondVector);
    manhattanNum = manhattan(firstVector, secondVector);
    chebyshevNum = chebyshev(firstVector, secondVector);
    canberraNum = canberra(firstVector, secondVector);
    minkowskiNum = minkowski(firstVector, secondVector, 2);
    //printing all the results
    std::fixed(std::cout);
    std::cout.precision(precisionNum(euclideanNum));
    std::cout << euclideanNum << std::endl;
    std::cout.precision(precisionNum(manhattanNum));
    std::cout << manhattanNum << std::endl;
    std::cout.precision(precisionNum(chebyshevNum));
    std::cout << chebyshevNum << std::endl;
    std::cout.precision(precisionNum(canberraNum));
    std::cout << canberraNum << std::endl;
    std::cout.precision(precisionNum(minkowskiNum));
    std::cout << minkowskiNum << std::endl;
    return 1;
}