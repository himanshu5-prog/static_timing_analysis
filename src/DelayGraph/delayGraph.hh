#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <array>
#include "../DataType/data_types.hh"

class DelayGraph{
    int gateCount;
    std::map<NodePtr,NodeList> circuit;
    Delay delay; // Delay object
    std :: map <NodePtr, int> incomingEdges;
    std :: vector <NodePtr> topologicalOrder;
    std :: map <NodePtr, NodeList> successor;
    std :: map <NodePtr, NodeList> predecessor;
    

    public:
        // Constructors
        DelayGraph(int gateCount_) : gateCount(gateCount_) {
            circuit.clear();
        }

        DelayGraph (){
            gateCount = 0;
            circuit.clear();
        }
        //--------------------------------------------------------------------------------

        // Getters
        int getGateCount() const { return gateCount; }
        std::map<NodePtr,NodeList> getCircuit() const { return circuit; }

        // Setters
        void setGateCount(int gateCount_) { gateCount = gateCount_; }
        void setCircuit(std::map<NodePtr,NodeList> circuit_) { circuit = circuit_; }

        // Add node list
        void addNodeList(NodePtr node, NodeList nodes){
            circuit[node] = nodes;
        }

        // Add fanout to the node
        void addNode(NodePtr node, NodePtr newNode){
            circuit[node].push_back(newNode);
        }

        // Set delay from source node to destination node
        void setDelay(int sourceId, int destId, int delayValue){
            delay.insert ({std::make_pair(sourceId,destId), delayValue});
        }

        void performTopologicalSort();
        // Print
        void printCircuit();
        void printDelay();
        void printIncomingEdges();
        void print();
        void printTopologicalOrder();
        void printSuccessor();
        void printPredecessor();
        //--------------------------------------------------------------------------------

        void run();
        //Create Circuit
        void createCircuit();
        void createSimpleCircuit();
};