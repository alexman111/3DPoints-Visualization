#pragma once
#include <QGLViewer/qglviewer.h>
#include <QGLViewer/manipulatedFrame.h>

#include <QFile>
#include <QTextStream>

#include <vector>
#include <algorithm>
#include "point.h"

class Viewer : public QGLViewer {
protected:
  virtual void init();
  virtual void draw();
private:
    std::vector<qglviewer::Vec> points;
};
