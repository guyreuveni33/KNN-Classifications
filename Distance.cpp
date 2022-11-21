#include "Distance.h"
#include <cmath>

/**
 * The function takes two vectors of the same size and calculates the Minkowski distance between them
 *
 * @param v1 The first vector
 * @param v2 The vector to compare to
 * @param x The power of the Minkowski distance.
 *
 * @return The distance between two vectors.
 */
double Minkowski(std::vector<double> &v1, std::vector<double> &v2, int x) {
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

/**
 * "Given two vectors, return the Euclidean distance between them."
 *
 * The first line of the function is a comment. Comments are ignored by the compiler. They are used to document the code
 *
 * @param v1 The first vector
 * @param v2 The vector to compare against.
 *
 * @return The Euclidean distance between two vectors.
 */
double Euclidean(std::vector<double> &v1, std::vector<double> &v2) {
    return Minkowski(v1, v2, 2);
}

/**
 * > The Manhattan distance between two vectors is the sum of the absolute differences between the corresponding elements
 * of the vectors
 *
 * @param v1 The first vector
 * @param v2 The vector to compare against.
 *
 * @return The Manhattan distance between two vectors.
 */
double Manhattan(std::vector<double> &v1, std::vector<double> &v2) {
    return Minkowski(v1, v2, 1);
}

/**
 * The Canberra distance is the sum of the absolute differences between the two vectors, divided by the sum of the absolute
 * values of the two vectors
 *
 * @param v1 The first vector
 * @param v2 the vector of the current document
 *
 * @return The Canberra distance between two vectors.
 */
double Canberra(std::vector<double> &v1, std::vector<double> &v2) {
    int l;
    double sum = 0, UpSum = 0, DownSum = 0, TempOne, TempTwo;
    l = v1.size();
    for (int i = 0; i < l; i++) {
        UpSum = v1.at(i) - v2.at(i);
        if ((UpSum < 0)) {
            UpSum = UpSum * (-1);
        }
        TempOne = v1.at(i);
        TempTwo = v2.at(i);
        if (TempOne < 0)
            TempOne = TempOne * (-1);
        if (TempTwo < 0)
            TempTwo = TempTwo * (-1);
        if (TempOne == 0 && TempTwo == 0) {
            continue;
        }
        DownSum = TempOne + TempTwo;
        sum = sum + (UpSum / DownSum);
    }
    return sum;
}


/**
 * It takes two vectors of the same length and returns the maximum difference between the corresponding elements
 *
 * @param v1 The first vector
 * @param v2 the vector of the query image
 *
 * @return The maximum difference between the two vectors.
 */
double Chebyshev(std::vector<double> &v1, std::vector<double> &v2) {
    int l;
    double max, temp;
    l = v1.size();
    max = v1.at(0) - v2.at(0);
    if ((max < 0)) {
        max = max * (-1);
    }
    for (int i = 1; i < l; ++i) {
        temp = (v1.at(i) - v2.at(i));
        if (temp < 0)
            temp = temp * (-1);
        if (temp > max)
            max = temp;
    }
    return max;
}


