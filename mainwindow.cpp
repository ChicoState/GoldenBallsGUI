#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Records_Viewer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_show_records_button_clicked()
{
    Records_Viewer *records = new Records_Viewer();
    records->show();
}
