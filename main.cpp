#include "main_page.h"
#include "viewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  MainPage w;
   //w.show();
    Viewer viewer;
    viewer.setWindowTitle("simple");
    viewer.show();

    return a.exec();
}
