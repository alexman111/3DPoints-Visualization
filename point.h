#pragma once

#include <stdint.h>
#include <ctime>
#include <QtGlobal>

const qint32 MAX_RAND_VALUE = 100000;

class Point
{
public:
    Point();

    void Next();
    qint32 GetX() const;
    qint32 GetY() const;
    qint32 GetZ() const;

private:
    qint32 x, y, z;
};

bool operator < (const Point& lhs, const Point& rhs);
