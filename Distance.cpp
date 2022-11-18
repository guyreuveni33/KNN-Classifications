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

double Canberra(std::vector<double> &v1, std::vector<double> &v2) {
    int l;
    double sum = 0;
    l = v1.size();
    for (int i = 0; i < l; ++i) {
        if ((v1.at(i) < 0)) {
            v1.push_back(v1.at(i) * (-1));
        }
        if ((v2.at(i) < 0)) {
            v2.push_back(v2.at(i) * (-1));
            if (v1.at(i) == 0 && v2.at(i) == 0) {
                continue;
            }
            sum = v1.at(i) - v2.at(i) / (v1.at(i)) + (v2.at(i));
        }
        return sum;
    }
}
double Chebyshev(std::vector<double> &v1, std::vector<double> &v2) {
    int l;
    double max;
    l = v1.size();
    if ((v1.at(0) < 0)) {
        v1.push_back(v1.at(0) * (-1));
    }
    if ((v2.at(0) < 0)) {
        v2.push_back(v2.at(0) * (-1));
        max = v1.at(0) - v2.at(0);
        for (int i = 1; i < l; ++i) {
            if ((v1.at(i) < 0)) {
                v1.push_back(v1.at(i) * (-1));
            }
            if ((v2.at(i) < 0)) {
                v2.push_back(v2.at(i) * (-1));
            }
            if (v1.at(0) - v2.at(0) > max)
                max = (v1.at(0) - v2.at(0));
        }
        return max;
    }
}
