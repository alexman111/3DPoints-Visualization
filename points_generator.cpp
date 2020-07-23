#include "points_generator.h"
#include <QFile>
#include <QTextStream>

PointsGenerator::PointsGenerator(){}

void PointsGenerator::Generate(const QString& filename, qint32 count) {
    Point p;

    p.Next();

    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)) {
        throw std::runtime_error("Can't write to file!");
    }

    QTextStream out(&file);
    while(count--) {
        while(is_exist.count(p)) {
            p.Next();
        }

        is_exist[p] = true;

        out << p.GetX() << " " << p.GetY() << " " << p.GetZ() << "\n";
    }
}
