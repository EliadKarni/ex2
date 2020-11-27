#pragma once

struct Location
{
    explicit Location(int row = 0, int col = 0) : row(row), col(col) {}
    bool operator==(const Location& location)const;
    int row;
    int col;
};