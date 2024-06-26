//
// Created by tea on 5/27/24.
//

#ifndef PROJECT3_COORD_H
#define PROJECT3_COORD_H


class Coord // Class used to store coordinates
{
public:
    inline Coord() : m_row(-1), m_col(-1), path(0) {}
    inline Coord(int rr, int cc) : m_row(rr), m_col(cc), path(0) {}
    inline int r() const { return m_row; }
    inline int c() const { return m_col; }
    inline void incRow(int v = 1) { m_row += v; }
    inline void incCol(int v = 1) { m_col += v; }
    inline int getPath() const { return path; }
    inline void incPath() { path++; }
    inline void remove() {  m_row = -1; m_col = -1; }
private:
    int m_row;
    int m_col;
    int path;
};


#endif //PROJECT3_COORD_H
