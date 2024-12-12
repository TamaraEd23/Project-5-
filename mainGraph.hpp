//
//  mainGraph.hpp
//  Graph
//  Created by Tamara Edmond on 12/12/24.
//

#ifndef mainGraph_hpp
#define mainGraph_hpp
#include <vector>
#include <string>
#include "vertex.hpp"
using namespace std;

class WeightedGraph {
public:
    WeightedGraph(int size);
    void addVertex(Vertex* vertex);
    void addEdge(int from, int to, int weight);
    void DFS(Vertex* start);
    void BFS(Vertex* start);
    bool findPath(Vertex* source, Vertex* destination, vector<string>& path, int& totalCost);

private:
    int m_numVertices;
    int m_maxVertices;
    vector<Vertex*> m_vertices;
    vector<vector<int>> m_edges;
    vector<bool> m_marks;

    void clearMarks();
    void doDFS(Vertex* vertex);
    void doBFS(Vertex* vertex);
    int indexIs(Vertex* vertex);
};

#endif 
