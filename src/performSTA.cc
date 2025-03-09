#include "DelayGraph/delayGraph.hh"
#include <iostream>

int main(){
    DelayGraph dg;
    
    dg.setDebugMode();
    dg.setCycleTime(29);
    dg.run();
    dg.print();
    return 0;
}