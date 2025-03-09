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
    m_sourceNodePtr.reset(source);

    // Creating sink node
    NodePtr sink = new Node(101, SINK, 0, 0);
    incomingEdges[sink] = 0;
    m_sinkNodePtr.reset(sink);

    NodePtr* gatePtr = new NodePtr[5];

    for (int i = 0; i < 5; i++){
        gatePtr[i] = new Node(i, GATE, 0, 0);
        incomingEdges[gatePtr[i]] = 0;
    }

    // Creating the circuit
    addNodeList(source, {gatePtr[0], gatePtr[1]});
    incomingEdges[gatePtr[0]] += 1;
    incomingEdges[gatePtr[1]] += 1;
    successor[source] = {gatePtr[0], gatePtr[1]};
    predecessor[gatePtr[0]].push_back(source);
    predecessor[gatePtr[1]].push_back(source);


    addNodeList(gatePtr[0], {gatePtr[2], gatePtr[3]});
    incomingEdges[gatePtr[2]] += 1;
    incomingEdges[gatePtr[3]] += 1;
    successor[gatePtr[0]] = {gatePtr[2], gatePtr[3]};
    predecessor[gatePtr[2]].push_back(gatePtr[0]);
    predecessor[gatePtr[3]].push_back(gatePtr[0]);

    addNodeList(gatePtr[1], {gatePtr[3], gatePtr[4]});
    incomingEdges[gatePtr[3]] += 1;
    incomingEdges[gatePtr[4]] += 1;
    successor[gatePtr[1]] = {gatePtr[3], gatePtr[4]};
    predecessor[gatePtr[3]].push_back(gatePtr[1]);
    predecessor[gatePtr[4]].push_back(gatePtr[1]);

    addNodeList(gatePtr[2], {gatePtr[4]});
    incomingEdges[gatePtr[4]] += 1;
    successor[gatePtr[2]] = {gatePtr[4]};
    predecessor[gatePtr[4]].push_back(gatePtr[2]);  

    addNodeList(gatePtr[3], {gatePtr[4]});
    incomingEdges[gatePtr[4]] += 1;
    successor[gatePtr[3]] = {gatePtr[4]};
    predecessor[gatePtr[4]].push_back(gatePtr[3]);

    addNodeList(gatePtr[4], {sink});
    incomingEdges[sink] += 1;
    successor[gatePtr[4]] = {sink};
    predecessor[sink].push_back(gatePtr[4]);

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

void DelayGraph :: createSimpleCircuit_2(){
    // Creating source node
    NodePtr source = new Node(100, SOURCE, 0, 0);
    incomingEdges[source] = 0;
    m_sourceNodePtr.reset(source);

    // Creating sink node
    NodePtr sink = new Node(101, SINK, 0, 0);
    incomingEdges[sink] = 0;
    m_sinkNodePtr.reset(sink);

    NodePtr* gatePtr = new NodePtr[5];

    for (int i = 0; i < 4; i++){
        gatePtr[i] = new Node(i, GATE, 0, 0);
        incomingEdges[gatePtr[i]] = 0;
    }

    // Create the circuit

    addNodeList(source, {gatePtr[0], gatePtr[1]});
    incomingEdges[gatePtr[0]] += 1;
    incomingEdges[gatePtr[1]] += 1;
    successor[source] = {gatePtr[0], gatePtr[1]};
    predecessor[gatePtr[0]].push_back(source);
    predecessor[gatePtr[1]].push_back(source);

    addNodeList(gatePtr[0], {gatePtr[2], gatePtr[3]});
    incomingEdges[gatePtr[2]] += 1;
    incomingEdges[gatePtr[3]] += 1;
    successor[gatePtr[0]] = {gatePtr[2], gatePtr[3]};
    predecessor[gatePtr[2]].push_back(gatePtr[0]);
    predecessor[gatePtr[3]].push_back(gatePtr[0]);

    addNodeList(gatePtr[1], {gatePtr[3]});
    incomingEdges[gatePtr[3]] += 1;
    successor[gatePtr[1]] = {gatePtr[3]};
    predecessor[gatePtr[3]].push_back(gatePtr[1]);

    addNodeList(gatePtr[2], {sink});
    incomingEdges[sink] += 1;
    successor[ gatePtr[2]].push_back(sink);
    predecessor[sink].push_back(gatePtr[2]);

    addNodeList(gatePtr[3], {sink});
    incomingEdges[sink] += 1;
    successor[gatePtr[3]].push_back(sink);
    predecessor[sink].push_back(gatePtr[3]);

    setDelay(100,0,3);
    setDelay(100,1,4);
    setDelay(0,2,5);
    setDelay(0,3,11);
    setDelay(1,3,9);
    setDelay(2,101,6);
    setDelay(3,101,15);

}

void DelayGraph :: printCircuit(){
    std::cout << "Printing Circuit:" << std::endl;
    for(auto it = circuit.begin(); it != circuit.end(); it++){
        std::cout << "Node: " << it->first->getId(); ;
        std::cout << " Fanout: ";
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

void
DelayGraph :: performTopologicalSort(){
    std :: queue <NodePtr> q;

    NodePtr source;

    for (auto it = incomingEdges.begin(); it != incomingEdges.end(); it++){
        if(it->second == 0){
            q.push(it->first);
        }
    }
    NodePtr currentNodePtr;
    while( q.size() > 0){
        currentNodePtr = q.front();
        q.pop();
        topologicalOrder.push_back(currentNodePtr);
        for(auto node : circuit[currentNodePtr]){
            incomingEdges[node] -= 1;
            if(incomingEdges[node] == 0){
                q.push(node);
            }
        }
    }
}

void
DelayGraph :: updateArrivalTime(){
    printDebugStatement(m_debugMode, "Updating Arrival Time");

    for (auto node : topologicalOrder){
        if (node->getType() == SOURCE){
            node->setArrivalTime(0);
            printDebugStatement(m_debugMode, "currentNode: SOURCE Node Arrival Time: " + std::to_string(node->getArrivalTime()));
        } else {
            // node is not source
            int arrTime = INT_MIN;
            int edgeDelay;
            printDebugStatement(m_debugMode, "Current Node id: " + std::to_string(node->getId()));
            for (auto pred: predecessor[node]){
                edgeDelay = delay[std::make_pair(pred->getId(), node->getId())];
                arrTime = std :: max(arrTime, pred->getArrivalTime() + edgeDelay);
                printDebugStatement(m_debugMode, "Node id: " + std :: to_string(node->getId()) + ", Predecessor id: " + std::to_string(pred->getId()) 
                + ", Pred arrivalTime: " + std :: to_string(pred->getArrivalTime())+ ", edge delay: " + std:: to_string(edgeDelay) + ", setting ArrTime:" + std::to_string(arrTime));
            }
            printDebugStatement(m_debugMode, "Node id: " + std::to_string(node->getId()) + ", Final Arrival Time: " + std::to_string(arrTime));
            node->setArrivalTime(arrTime);
        }
    }
}

void
DelayGraph :: updateRequiredTime(){
    printDebugStatement(m_debugMode, "Updating Required Time");
    for (auto itr = topologicalOrder.crbegin(); itr != topologicalOrder.crend(); ++itr){
        NodePtr node = *itr;
        std :: string nodeIdStr = std::to_string(node->getId());
        std :: string nodeReqTimesStr = std::to_string(node->getRequiredTime());

        if (node->getType() == SINK){
            node->setRequiredTime(m_cycleTime);
            printDebugStatement(m_debugMode, "currentNode: SINK Node id: " + nodeIdStr + ", Required Time: " + nodeReqTimesStr);
        } else {
            int reqTime = INT_MAX;
            int edgeDelay;
            int succReqTime;
            std::string succId;
            printDebugStatement(m_debugMode, "Current Node id: " + std::to_string(node->getId()));
            for (auto succ: successor[node]){
                edgeDelay = delay[std::make_pair(node->getId(), succ->getId())];
                succReqTime = succ->getRequiredTime();
                succId = std::to_string(succ->getId());
                reqTime = std :: min(reqTime, succReqTime - edgeDelay);
                printDebugStatement(m_debugMode, "Node id: " + std :: to_string(node->getId()) + ", Successor id: " + std::to_string(succ->getId()) + 
                ", successor reqTime: " + std::to_string(succReqTime) + ", edgeDelay: " + std::to_string(edgeDelay)  + ", setting ReqTime:" + std::to_string(reqTime));
            }
            printDebugStatement(m_debugMode, "Node id: " + std::to_string(node->getId()) + ", Final Required Time: " + std::to_string(reqTime));
            node->setRequiredTime(reqTime);
        }
    }
}

void
DelayGraph :: updateSlack(){
    for (const auto node: topologicalOrder){
        node->setSlack(node->getRequiredTime() - node->getArrivalTime()); // Slack = Required Time - Arrival Time
    }
}

void DelayGraph :: getPathList(){
    PathType pathVar;
    assert (m_sourceNodePtr != nullptr);
    pathVar.path.push_back(m_sourceNodePtr.get());
    pathVar.endNode = m_sourceNodePtr.get();
    pathVar.delay = 0;
    pathVar.slack = m_sourceNodePtr->getSlack();

    std :: priority_queue <PathType, std :: vector<PathType>, PathSlackComparator> pq; 
    pq.push(pathVar);

    while(!pq.empty()){
        PathType currentPath = pq.top();
        pq.pop();
        auto succNodePtr = currentPath.endNode;

        for (auto node: circuit[currentPath.endNode]){

            PathType localPath = currentPath;

            int localPathEndNode = localPath.endNode->getId();
            int currrentNodeId = node->getId();

            
            if (delay.find(std :: make_pair(localPathEndNode, currrentNodeId)) == delay.end()) {
                std :: cout << "ERROR: CurrentPath endnode: " <<localPathEndNode << ", starting node: " <<
                localPath.endNode->getId() << ", end node: " << currrentNodeId<< "\n";
            }
            
            assert(delay.find(std :: make_pair(localPathEndNode, currrentNodeId)) != delay.end());
            
            
            printDebugStatement(m_debugMode, "getPathList :: CurrentPath endnode: " + std::to_string(currrentNodeId) + ", delay lookup start node: "
            + std::to_string(localPathEndNode) + ", delay lookup end node: " + std::to_string(currrentNodeId));
            
            
            localPath.delay += delay[std::make_pair(localPathEndNode, currrentNodeId)];
            localPath.path.push_back(node);
            localPath.slack = node->getSlack();
            localPath.endNode = node;
            

            if (node->getType() == SINK){
                m_finalPathList.push_back(localPath);
            } else {
                pq.push(localPath);
            }
        }
    }
}

void DelayGraph :: printPathList(){
    std::cout << "Printing Path List (decreasing order of delay)" << std::endl;
    for (auto path : m_finalPathList){
        std::cout << "Path: ";
        for (auto node : path.path){
            if (node == m_sourceNodePtr.get()){
                std :: cout << "SRC ";
            } else if (node == m_sinkNodePtr.get()){
                std :: cout << "SNK";
            } else {
                std::cout << node->getId() << " ";
            }
        }
        std::cout << std::endl;
        std::cout << "Delay: " << path.delay << std::endl;
        std :: cout << "--------------------------------" << std::endl;
    }
}

void DelayGraph :: printTopologicalOrder(){
    std::cout << "Printing Topological Order" << std::endl;
    for(auto node : topologicalOrder){
        std::cout << node->getId() << " ";
    }
    std::cout << std::endl;
}

void DelayGraph :: run(){
    createSimpleCircuit_2();
    printIncomingEdges();
    performTopologicalSort();
    updateArrivalTime();
    updateRequiredTime();
    updateSlack();
    getPathList();
}

void DelayGraph :: print(){
    printCircuit();
    printDelay();
    printSuccessor();
    printPredecessor();
    printTopologicalOrder();
    printTimingInformation();
    printPathList();
}

void DelayGraph :: printSuccessor(){
    std::cout << "Printing Successor" << std::endl;
    for(auto it = successor.begin(); it != successor.end(); it++){
        std::cout << "Node: " << it->first->getId() << " Successor: ";
        for(auto node : it->second){
            std::cout << node->getId() << " ";
        }
        std::cout << std::endl;
    }
}

void DelayGraph :: printPredecessor(){
    std::cout << "Printing Predecessor" << std::endl;
    for(auto it = predecessor.begin(); it != predecessor.end(); it++){
        std::cout << "Node: " << it->first->getId() << " Predecessor: ";
        for(auto node : it->second){
            std::cout << node->getId() << " ";
        }
        std::cout << std::endl;
    }
}

void DelayGraph :: printTimingInformation(){
    std :: cout << "Printing Timing Information" << std::endl;
    for (auto node: topologicalOrder){
        std::cout << "Node: " << node->getId() << ", "<< nodeTypeToString(node->getType()) << std::endl;
        std::cout << "Arrival Time: " << node->getArrivalTime() << std::endl;
        std::cout << "Required Time: " << node->getRequiredTime() << std::endl;
        std::cout << "Slack: " << node->getSlack() << std::endl;
        std :: cout << "--------------------------------" << std::endl;
    }
    
}