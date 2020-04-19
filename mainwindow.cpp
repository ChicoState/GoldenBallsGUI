#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Records_Viewer.h"
#include "Records.h"
#include "Game_View.h"

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

void MainWindow::on_new_game_button_clicked()
{

    Game_View *game = new Game_View();
    game->show();
}

void MainWindow::on_add_button_clicked()
{
    Records& singleton = Records::instance();
    singleton.update_record("winner",true);
}
