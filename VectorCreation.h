#include <vector>

/**
 * If the double is an integer, return 1, else return 16
 *
 * @param d the number to be formatted
 *
 * @return The number of digits after the decimal point.
 */
int PrecisionNum(double d);

/**
 * If the first character is a digit or a negative sign, and if there are no more than one decimal point, and if all the
 * characters are digits or a decimal point, then return 1, else return 0
 *
 * @param s The string to be checked
 *
 * @return a boolean value.
 */
int NumCheck(std::string s);

/**
 * It checks if the string is empty, if the first character is a space, and if there are any double spaces
 *
 * @param TextLine The string that is being checked.
 *
 * @return an integer.
 */
int StringValidation(std::string TextLine);

/**
 * It takes a vector of doubles as a parameter, reads a line from the standard input, checks if the line is valid, and
 * if it is, it parses the line and inserts the numbers into the vector
 *
 * @param vector the vector to insert the numbers into
 *
 * @return 1 if the function was successful, 0 if it was not.
 */
int InsertToVector(std::vector<double> &vector);

/**
 * It takes two vectors of doubles, and calculates the Euclidean, Manhattan, Chebyshev, Canberra, and Minkowski
 * distances between them
 *
 * @param FirstVector the first vector
 * @param SecondVector the second vector to be compared
 *
 * @return 1
 */
int CalculateDistance(std::vector<double> &FirstVector, std::vector<double> &SecondVector);