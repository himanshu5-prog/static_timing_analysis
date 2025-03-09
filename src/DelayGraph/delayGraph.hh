#ifndef __DELAY_GRAPH_HH__
#define __DELAY_GRAPH_HH__
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <utility>
#include <algorithm>
#include "../DataType/data_types.hh"

class DelayGraph{
    int gateCount;
    std::map<NodePtr,NodeList> circuit;
    Delay delay; // Delay object
    std :: map <NodePtr, int> incomingEdges;
    std :: vector <NodePtr> topologicalOrder;
    std :: map <NodePtr, NodeList> successor;
    std :: map <NodePtr, NodeList> predecessor;
    NodePtr m_sourceNodePtr;
    NodePtr m_sinkNodePtr;
    int m_cycleTime;
    bool m_debugMode;

    public:
        // Constructors
        DelayGraph(int gateCount_, int cycleTime_, int debugMode_) : gateCount(gateCount_), m_cycleTime(cycleTime_), m_debugMode(debugMode_){
            circuit.clear();
        }

        DelayGraph (){
            gateCount = 0;
            circuit.clear();
            m_cycleTime = 20;
            m_debugMode = false;
        }
        //--------------------------------------------------------------------------------

        // Getters
        int getGateCount() const { return gateCount; }
        std::map<NodePtr,NodeList> getCircuit() const { return circuit; }

        // Setters
        void setGateCount(int gateCount_) { gateCount = gateCount_; }
        void setCircuit(std::map<NodePtr,NodeList> circuit_) { circuit = circuit_; }
        void setCycleTime(int cycleTime_) { m_cycleTime = cycleTime_; }
        void setDebugMode() { m_debugMode = true; }

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
        void updateArrivalTime();
        void updateRequiredTime();
        void updateSlack();
        // Print
        void printCircuit();
        void printDelay();
        void printIncomingEdges();
        void print();
        void printTopologicalOrder();
        void printSuccessor();
        void printPredecessor();
        void printTimingInformation();
        //--------------------------------------------------------------------------------
        void run();
        //Create Circuit
        void createCircuit();
        void createSimpleCircuit();
};

#endif