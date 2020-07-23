#include "main_page.h"
#include<QPushButton>
#include <QApplication>

MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *file_generate_button = new QPushButton("Generate", this);
    file_generate_button->setGeometry(50, 40, 75, 30);
    connect(file_generate_button, &QPushButton::clicked, this, &MainPage::OnGenerate);
}

MainPage::~MainPage()
{
}

void MainPage::OnGenerate() {
    try {
        PointsGenerator generator;
        generator.Generate("C:\\Users\\sanch\\Documents\\QT_Projects\\3DCoordinates\\input.txt", 1000000);
    } catch (std::exception &e) {
    }

}

