//
// Created by tea on 5/16/24.
//

#include "Objects.h"

Objects::Objects(std::string name)
: name(name), m_c()
{}

void Objects::place(Coord c) {
    m_c = c;
}

void Objects::pickUp() {
    m_c.remove();
}
