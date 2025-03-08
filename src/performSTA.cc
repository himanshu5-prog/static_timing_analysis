#include "DelayGraph/delayGraph.hh"
#include <iostream>

int main(){
    DelayGraph dg;
    dg.createSimpleCircuit();
    dg.printCircuit();
    dg.printDelay();
    dg.printIncomingEdges();
    return 0;
}