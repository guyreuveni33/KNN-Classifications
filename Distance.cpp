#include "Distance.h"
#include <cmath>

double minkowski(std::vector<double> &v1, std::vector<double> &v2, int x) {
    int i;
    double sum = 0;
    for (i = 0; i < v1.size(); i++) {
        double temp = v1.at(i) - v2.at(i);
        if (temp < 0) {
            temp = temp * (-1);
        }
        sum += pow(temp, x);
    }
    double distance = pow(sum, 1.0 / (double) x);
    return distance;
}

double euclidean(std::vector<double> &v1, std::vector<double> &v2) {
    return minkowski(v1, v2, 2);
}

double manhattan(std::vector<double> &v1, std::vector<double> &v2) {
    return minkowski(v1, v2, 1);
}

double canberra(std::vector<double> &v1, std::vector<double> &v2) {
    double sum = 0, upperSum, lowerSum, tempOne, tempTwo;
    for (int i = 0; i < v1.size(); i++) {
        upperSum = v1.at(i) - v2.at(i);
        if ((upperSum < 0)) {
            upperSum = upperSum * (-1);
        }
        tempOne = v1.at(i);
        tempTwo = v2.at(i);
        if (tempOne < 0)
            tempOne = tempOne * (-1);
        if (tempTwo < 0)
            tempTwo = tempTwo * (-1);
        if (tempOne == 0 && tempTwo == 0) {
            continue;
        }
        lowerSum = tempOne + tempTwo;
        sum = sum + (upperSum / lowerSum);
    }
    return sum;
}

double chebyshev(std::vector<double> &v1, std::vector<double> &v2) {
    double max, temp;
    max = v1.at(0) - v2.at(0);
    if ((max < 0)) {
        max = max * (-1);
    }
    for (int i = 1; i < v1.size(); ++i) {
        temp = (v1.at(i) - v2.at(i));
        if (temp < 0)
            temp = temp * (-1);
        if (temp > max)
            max = temp;
    }
    return max;
}


