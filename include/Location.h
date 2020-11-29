#ifndef _Location_H
#define _Location_H
#pragma once

struct Location
{
    explicit Location(int row = 0, int col = 0) : row(row), col(col) {}
    bool operator==(const Location& location)const;
    int row;
    int col;
};

bool inRectangle(const Location& topLeft, const Location& botRight,
    const Location& location);
bool isLeftOf(const Location& testLoc, const Location& loc);
bool isRightOf(const Location& testLoc, const Location& loc);
bool isAboveOf(const Location& testLoc, const Location& loc);
bool isBelowOf(const Location& testLoc, const Location& loc);
#endif // !_Location_H
