#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>  //  library for reading files

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playlistsList->addItem("bög");
}

MainWindow::~MainWindow()
{
    delete ui;
}

