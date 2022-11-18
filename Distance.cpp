#include "Distance.h"
#include <vector>
#include <cmath>

double Minkowski (std::vector<double> &v1, std::vector<double> &v2, int x) {
    int i;
    double sum = 0;
    for (i = 0; i < v1.size(); i++) {
        double temp = v1.at(i) - v2.at(i);
        if (temp < 0) {
            temp = temp * (-1);
        }
        sum += pow(temp, x);
    }
    double distance = pow(sum, 1/x);
    return distance;
}

double Euclidean (std::vector<double> &v1, std::vector<double> &v2) {
    return Minkowski(v1, v2, 2);
}
double Manhattan (std::vector<double> &v1, std::vector<double> &v2) {
    return Minkowski(v1, v2, 1);
}
