#include <vector>
#include <string>
/**
 * The function takes two vectors of the same size and calculates the minkowski distance between them
 *
 * @param v1 The first vector
 * @param v2 The vector to compare to
 * @param x The power of the minkowski distance.
 *
 * @return The distance between two vectors.
 */
double minkowski(std::vector<double> &v1, std::vector<double> &v2, int x);

/**
 * "Given two vectors, return the euclidean distance between them."
 *
 * The first line of the function is a comment. Comments are ignored by the compiler. They are used to document the code
 *
 * @param v1 The first vector
 * @param v2 The vector to compare against.
 *
 * @return The euclidean distance between two vectors.
 */
double euclidean(std::vector<double> &v1, std::vector<double> &v2);

/**
 * > The manhattan distance between two vectors is the sum of the absolute differences between the corresponding elements
 * of the vectors
 *
 * @param v1 The first vector
 * @param v2 The vector to compare against.
 *
 * @return The manhattan distance between two vectors.
 */
double manhattan(std::vector<double> &v1, std::vector<double> &v2);

/**
 * The canberra distance is the sum of the absolute differences between the two vectors, divided by the sum of the absolute
 * values of the two vectors
 *
 * @param v1 The first vector
 * @param v2 the vector of the current document
 *
 * @return The canberra distance between two vectors.
 */
double canberra(std::vector<double> &v1, std::vector<double> &v2);

/**
 * It takes two vectors of the same length and returns the maximum difference between the corresponding elements
 *
 * @param v1 The first vector
 * @param v2 the vector of the query image
 *
 * @return The maximum difference between the two vectors.
 */
double chebyshev(std::vector<double> &v1, std::vector<double> &v2);
