#include "Distance.h"
#include "VectorCreation.h"

/**
 * It takes two vectors of doubles, and calculates the distance between them
 *
 * @return a boolean value.
 */
int main() {
    std::vector<double> FirstVector, SecondVector;
    if(!(InsertToVector(FirstVector))){
        return 0;
    }
    if(!(InsertToVector(SecondVector))){
        return 0;
    }
    if(!(CalculateDistance(FirstVector, SecondVector))) {
        return 0;
    }
    return 0;
}

