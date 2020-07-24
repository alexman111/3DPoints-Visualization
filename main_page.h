#pragma once

#include <QWidget>
#include<QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFileDialog>
#include <QLabel>

#include "points_generator.h"
#include "viewer.h"


class MainPage : public QWidget
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();
private slots:
    void OnGenerate();
    void OnChoice();
    void OnDraw();
private:
    QString filename;
    Viewer *v;
    QLabel *lbl;
};
