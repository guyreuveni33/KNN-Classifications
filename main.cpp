#include "Distance.h"
#include "VectorCreation.h"


int main() {
    std::vector<double> FirstVector, SecondVector;
    if(!(insertToVector(FirstVector))){
        return 0;
    }
    if(!(insertToVector(SecondVector))){
        return 0;
    }
    if(!(calculateDistance(FirstVector, SecondVector))) {
        return 0;
    }
    return 0;
}

