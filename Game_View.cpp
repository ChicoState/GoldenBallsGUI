#include "Game_View.h"
#include "ui_Game_View.h"

Game_View::Game_View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_View)
{
    ui->setupUi(this);
}

Game_View::~Game_View()
{
    delete ui;
}
