#include "point.h"

Point::Point()
{
    srand(time(0));
    x = y = z = 0;
}

void Point::Next() {
    x = (rand() * rand()) % MAX_RAND_VALUE;
    y = (rand() * rand()) % MAX_RAND_VALUE;
    z = (rand() * rand()) % MAX_RAND_VALUE;

}

qint32 Point::GetX() const{
    return x;
}

qint32 Point::GetY() const{
    return y;
}

qint32 Point::GetZ() const{
    return z;
}

bool operator < (const Point& lhs, const Point& rhs) {
    if (lhs.GetZ() != rhs.GetZ()) return lhs.GetZ() < rhs.GetZ();
    if (lhs.GetX() != rhs.GetX()) return lhs.GetX() < rhs.GetX();
    if (lhs.GetY() != rhs.GetY()) return lhs.GetY() < rhs.GetY();

    return false;
}
