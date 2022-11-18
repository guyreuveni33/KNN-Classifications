#include "Distance.h"
#include <cmath>

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

double Euclidean(std::vector<double> &v1, std::vector<double> &v2) {
    return Minkowski(v1, v2, 2);
}

double Manhattan(std::vector<double> &v1, std::vector<double> &v2) {
    return Minkowski(v1, v2, 1);
}

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


