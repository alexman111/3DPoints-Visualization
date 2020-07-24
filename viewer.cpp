#include "viewer.h"



void Viewer::init() {

  setMouseBinding(Qt::NoModifier, Qt::LeftButton, QGLViewer::CAMERA,
                  QGLViewer::ROTATE);
  setMouseBinding(Qt::NoModifier, Qt::RightButton, QGLViewer::CAMERA,
                  QGLViewer::TRANSLATE);
  setMouseBinding(Qt::NoModifier, Qt::MidButton, QGLViewer::CAMERA,
                  QGLViewer::ZOOM);
  setWheelBinding(Qt::NoModifier, QGLViewer::CAMERA, QGLViewer::ZOOM);



#ifdef GL_RESCALE_NORMAL // OpenGL 1.2 Only...
  glEnable(GL_RESCALE_NORMAL);
#endif

  setSceneRadius(30);
  camera()->fitSphere(qglviewer::Vec(0, 0, 0), 1);

}

void Viewer::draw() {
  drawAxis(1);

  glBegin(GL_POINTS);
  double r = 0, g = 0, b = 0, step = 3.0 / (points.size() + 1);
  size_t cnt = 0;

  for (const auto& point: points) {
      glColor3f(r, g, b);
      cnt++;
      if (cnt <= points.size() / 3) {
          r += step;
      } else if (cnt <= 2 * points.size() / 3) {
          g += step;
      }else {
          b += step;
      }

      glVertex3fv(point);
  }

  glEnd();

}

void Viewer::InitPoints(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Can't open file for reading");
    }

    QTextStream in(&file);

    points.clear();
    while(!in.atEnd()) {
       qreal x, y, z;
       in >> x >> y >> z;
       x /= MAX_RAND_VALUE;
       y /= MAX_RAND_VALUE;
       z /= MAX_RAND_VALUE;

       points.push_back(qglviewer::Vec(x, y, z));
    }
    std::sort(points.begin(), points.end(), [](const qglviewer::Vec& v1, const qglviewer::Vec& v2) {
        return v1.z < v2.z;
    });

    draw();

}
