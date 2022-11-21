#include <iostream>
#include <sstream>
#include <regex>
#include "Distance.h"

using namespace std;

/**
 * If the double is an integer, return 1, else return 16
 *
 * @param d the number to be formatted
 *
 * @return The number of digits after the decimal point.
 */
int PrecisionNum(double d) {
    if (d == (int) d) {
        return 1;
    } else return 16;
}

int numCheck(string s) {
    int i, flag = 0;
    if (!isdigit(s[0])) {
        return 0;
    }
    for (i = 1; i < s.size(); i++) {
        if (!(isdigit(s[i]))) {
            if (s[i] == 46) {
                flag++;
                continue;
            }
        }
        if (flag>=2) {
            return 0;
        }
    }
    return 1;
}

/**
 * It takes two vectors of doubles, and returns the Euclidean distance between them
 *
 * @return The program returns the distance between two vectors.
 */
int main() {
    std::vector<double> FirstVector, SecondVector;
    std::string TextLineOne;
    std::string TextLineTwo;
    getline(std::cin, TextLineOne);
    int i, k;
    for (i = 1; i < TextLineOne.size(); i++) {
        if (TextLineOne[i - 1] == 32 && TextLineOne[i] == 32) {
            std::cout << "error";
            return 0;
        }
    }
    double num;
    std::istringstream LineStream(TextLineOne);
    std::string s;
    while (LineStream >> s) {
        if (!numCheck(s)) {
            std::cout << "error2";
            return 0;
        }
    }
    /**
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
     **/
    /**double EuclideanNum, ManhattanNum, ChebyshevNum, CanberraNum, MinkowskiNum;
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
    return 0;**/

}

