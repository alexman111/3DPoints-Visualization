#pragma once

#include <map>
#include "point.h"

class PointsGenerator
{
public:
    PointsGenerator();
    void Generate(const QString& filename, qint32 count);

private:
    std::map<Point, bool> is_exist;
};

