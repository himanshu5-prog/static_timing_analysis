#include "delayGraph.hh"

void
DelayGraph :: createCircuit(){
    // Creating source node
    NodePtr source = new Node(0, SOURCE, 0, 0);

    NodePtr sink = new Node(gateCount, SINK, 0, 0);

    NodePtr* gatePtr = new NodePtr[gateCount];

    // Creating gate nodes
    for(int i = 0; i < 10; i++){
        gatePtr[i] = new Node(i+1, GATE, 0, 0);
    }




}

void
DelayGraph :: createSimpleCircuit(){
    // Creating source node
    NodePtr source = new Node(100, SOURCE, 0, 0);
    incomingEdges[source] = 0;

    // Creating sink node
    NodePtr sink = new Node(101, SINK, 0, 0);
    incomingEdges[sink] = 0;

    NodePtr* gatePtr = new NodePtr[5];

    for (int i = 0; i < 5; i++){
        gatePtr[i] = new Node(i, GATE, 0, 0);
        incomingEdges[gatePtr[i]] = 0;
    }

    // Creating the circuit
    addNodeList(source, {gatePtr[0], gatePtr[1]});
    incomingEdges[gatePtr[0]] += 1;
    incomingEdges[gatePtr[1]] += 1;

    addNodeList(gatePtr[0], {gatePtr[2], gatePtr[3]});
    incomingEdges[gatePtr[2]] += 1;
    incomingEdges[gatePtr[3]] += 1;

    addNodeList(gatePtr[1], {gatePtr[3], gatePtr[4]});
    incomingEdges[gatePtr[3]] += 1;
    incomingEdges[gatePtr[4]] += 1;

    addNodeList(gatePtr[2], {gatePtr[4]});
    incomingEdges[gatePtr[4]] += 1;

    addNodeList(gatePtr[3], {gatePtr[4]});
    incomingEdges[gatePtr[4]] += 1;

    addNodeList(gatePtr[4], {sink});
    incomingEdges[sink] += 1;

    //Setting the delay

    // Delay from source node
    setDelay(100,0,0);
    setDelay(100,1,0);

    // Delay from gate nodes

    // Delay from Gate id: 0
    setDelay(0,2,2);
    setDelay(0,3,3);

    // Delay from Gate id: 1
    setDelay(1,3,4);
    setDelay(1,4,5);

    // Delay from Gate id: 2
    setDelay(2,4,6);

    //Delay from Gate id: 3
    setDelay(3,4,7);

    // Delay from Gate id: 4
    setDelay(4,101,0);
}

void DelayGraph :: printCircuit(){
    std::cout << "Printing Circuit:" << std::endl;
    for(auto it = circuit.begin(); it != circuit.end(); it++){
        std::cout << "Node: " << it->first->getId() << std::endl;
        std::cout << "Fanout: ";
        for(auto node : it->second){
            std::cout << node->getId() << " ";
        }
        std::cout << std::endl;
    }
}

void DelayGraph :: printDelay(){
    std::cout << "Printing Delay" << std::endl;
    for(auto it = delay.begin(); it != delay.end(); it++){
        std::cout << "Source: " << it->first.first << " Destination: " << it->first.second << " Delay: " << it->second << std::endl;
    }
}

void 
DelayGraph :: printIncomingEdges(){
    std::cout << "Printing Incoming Edges" << std::endl;
    for(auto it = incomingEdges.begin(); it != incomingEdges.end(); it++){
        std::cout << "Node: " << it->first->getId() << " ,Incoming Edges: " << it->second << std::endl;
    }
}