#ifndef __DATA_TYPES_HH__
#define __DATA_TYPES_HH__
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>

enum NodeType {
    SOURCE,
    SINK,
    GATE,
    NUM_NODE_TYPES
};
std :: string nodeTypeToString(NodeType type);
void printDebugStatement(bool debugMode, std :: string statement);

class Node {
    int id;
    NodeType type;
    int arrivalTime;
    int requiredTime;
    int slack;

    public:

        // Constructors
        Node(int id_, NodeType type_, int arrivalTime_, int requiredTime_) : id(id_), type(type_), arrivalTime(arrivalTime_), requiredTime(requiredTime_) {
            slack = requiredTime - arrivalTime;
        }

        Node (){
            id = -1;
            type = NUM_NODE_TYPES;
            arrivalTime = 0;
            requiredTime = 0;
            slack = 0;
        }

        // Getters
        int getId() const { return id; }
        NodeType getType() const { return type; }
        int getArrivalTime() const { return arrivalTime; }
        int getRequiredTime() const { return requiredTime; }
        int getSlack() const{ return slack; }

        // Setters
        void setId(int id_) { id = id_; }
        void setType(NodeType type_) { type = type_; }
        void setArrivalTime(int arrivalTime_) { arrivalTime = arrivalTime_; }
        void setRequiredTime(int requiredTime_) { requiredTime = requiredTime_; }
        void setSlack(int slack_) { slack = slack_; }

        // Print
        void print(){
            std::cout << "Node: " << id << std::endl;
            std::cout << "Type: " << type << std::endl;
            std::cout << "Arrival Time: " << arrivalTime << std::endl;
            std::cout << "Required Time: " << requiredTime << std::endl;
            std::cout << "Slack: " << slack << std::endl;
        }

};
typedef Node* NodePtr;
typedef std::vector<NodePtr> NodeList;
typedef std :: pair <int, int> GateArc;
typedef std :: map <GateArc, int> Delay;

inline std :: string nodeTypeToString(NodeType type){
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

inline void printDebugStatement(bool debugMode, std :: string statement){
    if (debugMode){
        std :: cout << statement << std :: endl;
    }
}
#endif