#include <vector>

/**
 * The function takes two vectors of the same size and calculates the Minkowski distance between them
 *
 * @param v1 The first vector
 * @param v2 The vector to compare to
 * @param x The power of the Minkowski distance.
 *
 * @return The distance between two vectors.
 */
double Minkowski(std::vector<double> &v1, std::vector<double> &v2, int x);

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
double Euclidean(std::vector<double> &v1, std::vector<double> &v2);

/**
 * > The Manhattan distance between two vectors is the sum of the absolute differences between the corresponding elements
 * of the vectors
 *
 * @param v1 The first vector
 * @param v2 The vector to compare against.
 *
 * @return The Manhattan distance between two vectors.
 */
double Manhattan(std::vector<double> &v1, std::vector<double> &v2);

/**
 * The Canberra distance is the sum of the absolute differences between the two vectors, divided by the sum of the absolute
 * values of the two vectors
 *
 * @param v1 The first vector
 * @param v2 the vector of the current document
 *
 * @return The Canberra distance between two vectors.
 */
double Canberra(std::vector<double> &v1, std::vector<double> &v2);

/**
 * It takes two vectors of the same length and returns the maximum difference between the corresponding elements
 *
 * @param v1 The first vector
 * @param v2 the vector of the query image
 *
 * @return The maximum difference between the two vectors.
 */
double Chebyshev(std::vector<double> &v1, std::vector<double> &v2);
