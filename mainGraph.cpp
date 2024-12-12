//
//  mainGraph.cpp
//  Graph
//
//  Created by Tamara Edmond on 12/12/24.
#include "mainGraph.hpp"
#include <iostream>
#include <queue>
using namespace std;

// Constructor to initialize the graph
WeightedGraph::WeightedGraph(int size) {
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size, nullptr);
    m_edges.resize(size, vector<int>(size, 0));
    m_marks.resize(size, false);
}

// Add a vertex to the graph
void WeightedGraph::addVertex(Vertex* vertex) {
    if (m_numVertices < m_maxVertices) {
        m_vertices[m_numVertices] = vertex;
        m_numVertices++;
    } else {
        cout << "Graph is full. Cannot add more vertices." << endl;
    }
}

// Add an edge between two vertices with a weight
void WeightedGraph::addEdge(int from, int to, int weight) {
    if (from < m_numVertices && to < m_numVertices) {
        m_edges[from][to] = weight;
    } else {
        cout << "Invalid vertex indices for edge." << endl;
    }
}

// Reset visited marks
void WeightedGraph::clearMarks() {
    for (int i = 0; i < m_marks.size(); i++) {
        m_marks[i] = false;
    }
}

// Helper function for DFS
void WeightedGraph::doDFS(Vertex* vertex) {
    int index = indexIs(vertex);
    if (index == -1 || m_marks[index]) return;

    cout << vertex->getTitle() << " ";
    m_marks[index] = true;

    for (int i = 0; i < m_numVertices; i++) {
        if (m_edges[index][i] > 0 && !m_marks[i]) {
            doDFS(m_vertices[i]);
        }
    }
}

// Perform Depth First Search
void WeightedGraph::DFS(Vertex* start) {
    clearMarks();
    doDFS(start);
    cout << endl;
}

// Helper function for BFS
void WeightedGraph::doBFS(Vertex* vertex) {
    queue<Vertex*> q;
    int startIndex = indexIs(vertex);
    if (startIndex == -1) return;

    m_marks[startIndex] = true;
    q.push(vertex);

    while (!q.empty()) {
        Vertex* current = q.front();
        q.pop();
        cout << current->getTitle() << " ";

        int currentIndex = indexIs(current);
        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[currentIndex][i] > 0 && !m_marks[i]) {
                m_marks[i] = true;
                q.push(m_vertices[i]);
            }
        }
    }
}

// Perform Breadth First Search
void WeightedGraph::BFS(Vertex* start) {
    clearMarks();
    doBFS(start);
    cout << endl;
}

// Get the index of a vertex in the list
int WeightedGraph::indexIs(Vertex* vertex) {
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

// Find a path between two vertices and calculate its cost
bool WeightedGraph::findPath(Vertex* source, Vertex* destination, vector<string>& path, int& totalCost) {
    clearMarks();
    queue<Vertex*> q;
    vector<int> distances(m_numVertices, -1);
    vector<int> parents(m_numVertices, -1);
    int sourceIndex = indexIs(source);
    int destinationIndex = indexIs(destination);

    if (sourceIndex == -1 || destinationIndex == -1) {
        cout << "Source or destination vertex not found." << endl;
        return false;
    }

    distances[sourceIndex] = 0;
    q.push(source);

    while (!q.empty()) {
        Vertex* current = q.front();
        q.pop();
        int currentIndex = indexIs(current);

        if (currentIndex == destinationIndex) {
            // Reconstruct the path
            int backtrack = destinationIndex;
            while (backtrack != -1) {
                path.insert(path.begin(), m_vertices[backtrack]->getTitle());
                backtrack = parents[backtrack];
            }
            totalCost = distances[destinationIndex];
            return true;
        }

        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[currentIndex][i] > 0 && distances[i] == -1) {
                distances[i] = distances[currentIndex] + m_edges[currentIndex][i];
                parents[i] = currentIndex;
                q.push(m_vertices[i]);
            }
        }
    }

    return false; // No path found
}
