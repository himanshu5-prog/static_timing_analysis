#include "data_types.hh"

std :: string nodeTypeToString(NodeType type){
    switch(type){
        case SOURCE:
            return "SOURCE";
        case SINK:
            return "SINK";
        case GATE:
            return "GATE";
        default:
            return "UNKNOWN";
    }
}

void printDebugStatement(bool debugMode, std :: string statement){
    if (debugMode){
        std :: cout << statement << std :: endl;
    }
}