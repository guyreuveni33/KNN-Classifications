#include "Distance.h"
#include "VectorCreation.h"

/**
 * It takes two vectors of doubles, and calculates the distance between them
 *
 * @return a boolean value.
 */
int main() {
    std::vector<double> firstVector, secondVector;
    if(!(insertToVector(firstVector))){
        return 0;
    }
    if(!(insertToVector(secondVector))){
        return 0;
    }
    if(!(calculateDistance(firstVector, secondVector))) {
        return 0;
    }
    return 0;
}

