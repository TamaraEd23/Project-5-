//
//  vertex.hpp
//  Graph
//
//  Created by Tamara Edmond on 12/12/24.
//

 #ifndef vertex_hpp
 #define vertex_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Vertex {
public:
    Vertex(string name);       // Constructor
    string getTitle();         // Get the name of the vertex
    void setTitle(string name); // Set a new name for the vertex

private:
    string m_title;            // Name of the vertex
};

#endif // VERTEX_H
