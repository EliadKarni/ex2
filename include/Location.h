#pragma once

struct Location
{
    explicit Location(int row, int col) : row(row), col(col) {}
    bool operator==(const Location& location)const;
    int row = 0;
    int col = 0;
};