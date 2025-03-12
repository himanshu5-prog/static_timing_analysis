## Static Timing Analysis Implentation in C++

This repo implements STA in C++ and provides Arrival Time/Required Arrival timeSlack at each node and list path in decreasing order of delay. 

The logic circuit is represented using delay graph which is Directed-Acyclic-Graph (DAG). Then the graph is processed using topological sorting and then traversed from source to sink. It calculates timing information at each node and print it for analysis purpose. Apart from that, all possible path from source and sink are listed in decreasing order of delay.

1) Compiling command:

> source run.tcl 

2) Running the code
 > ./performSTA

Reference:

https://www.coursera.org/learn/vlsi-cad-layout (Timing Analysis section) 
