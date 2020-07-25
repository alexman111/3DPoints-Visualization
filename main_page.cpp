#include "main_page.h"
#include <QMessageBox>

MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);

    v = new Viewer();


    QPushButton *file_generate_button = new QPushButton("Generate data into file", this);
    connect(file_generate_button, &QPushButton::clicked, this, &MainPage::OnGenerate);

    QPushButton *file_choice_button = new QPushButton("Choice file", this);
    connect(file_choice_button, &QPushButton::clicked, this, &MainPage::OnChoice);

    QPushButton *draw_button = new QPushButton("Draw data from file", this);
    connect(draw_button, &QPushButton::clicked, this, &MainPage::OnDraw);


    lbl = new QLabel("No file selected");
    grid -> addWidget(v, 0, 0, 4, 4);

    grid -> addWidget(draw_button, 0, 4, 1, 1);
    grid -> addWidget(file_generate_button, 1, 4, 1, 1);
    grid -> addWidget(file_choice_button, 2, 4, 1, 1);
    grid -> addWidget(lbl, 3, 4, 1, 1);


    setLayout(grid);
}

MainPage::~MainPage()
{
}

void MainPage::OnGenerate() {
    QMessageBox msgBox;
    try {
        PointsGenerator generator;
        this->setCursor(Qt::WaitCursor);

        generator.Generate(filename, 1000000);

        this->setCursor(Qt::ArrowCursor);

        msgBox.setText("Succesfully generating!");
        msgBox.exec();
    } catch (std::exception &e) {
        this->setCursor(Qt::ArrowCursor);

        msgBox.setText(e.what());
        msgBox.exec();
    }

}

void MainPage::OnChoice() {
    filename = QFileDialog::getOpenFileName();

    int slash_position = 0;
    for (int i = 0; i < filename.size(); ++i) if (filename[i] == '/') {
        slash_position = i;
    }

    lbl->setText("Current filename: " + filename.mid(slash_position + 1));
}

void MainPage::OnDraw() {
    QMessageBox msgBox;
    try {
        this->setCursor(Qt::WaitCursor);
        v->InitPoints(filename);
        this->setCursor(Qt::ArrowCursor);
        msgBox.setText("Succesfully visualizate!");
        msgBox.exec();
    } catch (std::exception& e) {
        this->setCursor(Qt::ArrowCursor);
        msgBox.setText(e.what());
        msgBox.exec();
    }
}
