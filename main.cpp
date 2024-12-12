//
//  main.cpp
//  Graph
//
//  Created by Tamara Edmond on 12/12/24.
//
#include <iostream>
#include "Vertex.hpp"
#include "mainGraph.hpp" //had to change the name of the file bc i made a error naming the file 
using namespace std;
int main()
{
    WeightedGraph myGraph(10);
    Vertex* startNode;
    Vertex* aVertex;
    startNode = new Vertex("A"); // node 0
    myGraph.addVertex(startNode);
    aVertex = new Vertex("B"); // node 1
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("C"); // node 2
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("D"); // node 3
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("E"); // node 4
    myGraph.addVertex(aVertex);
    myGraph.addEdge(0,1,12);
    myGraph.addEdge(0,2,17);
    myGraph.addEdge(0,4,22);
    myGraph.addEdge(1,3,9);
    myGraph.addEdge(1,2,6);
    myGraph.addEdge(3,4,1);
    cout << "DFS: ";
    myGraph.DFS(startNode);
    cout << endl;
    cout << "BFS: ";
    myGraph.BFS(startNode);
    cout << endl;
    return 0;
}



