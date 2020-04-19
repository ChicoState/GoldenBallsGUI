#include "Game_View.h"
#include "ui_Game_View.h"
#include "Records.h"
#include <QString>


Game_View::Game_View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_View),
    _all_records(Records::instance())
{
    ui->setupUi(this);
    _all_records.addObserver(this);
    update();
}

Game_View::~Game_View()
{
    delete ui;
}

void Game_View::update() //override
{
    // First, find the player with the highest winning ratio
    QString lead = "";
    double best = -1.1; //lower winning record than is possible.
    int wins = 0; //if a tie, we will pick the winner with the most wins
    for (std::map <const string, Record>::iterator it = _all_records.get_records().begin();
         it != _all_records.get_records().end(); ++it)
    {
        QString name = QString::fromStdString(it->first);
        int current_wins = it->second.wins;
        int current_losses = it->second.losses;
        double ratio = (double) current_wins / (current_wins + current_losses);

        if( ratio > best || ( ratio == best && it->second.wins > wins) )
        {
            lead = name;
            best = ratio;
            wins = current_wins;
        }
    }

    // Next, update the display
    QString display = "LEADERBOARD: " + lead + " (" + QString::number(best) + ")";
    ui->leaderboard->setText(display);
}
