#pragma once
#include <QWidget>
#include "points_generator.h"

class MainPage : public QWidget
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();
private slots:
    void OnGenerate();
};
