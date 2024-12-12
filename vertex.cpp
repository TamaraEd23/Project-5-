//
//  vertex.cpp
//  Graph
//
//  Created by Tamara Edmond on 12/12/24.
//

#include "vertex.hpp"

Vertex::Vertex(string name) {
    m_title = name;
}

string Vertex::getTitle() {
    return m_title;
}

void Vertex::setTitle(string name) {
    m_title = name;
}
