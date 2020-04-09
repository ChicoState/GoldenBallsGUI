#include "Game_View.h"
#include "ui_Game_View.h"
#include "Records.h"
#include <string>
#include <map>
#include <QStringList>
#include <QListView>

Game_View::Game_View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_View)
{
    ui->setupUi(this);
    load_leaderboard();
}

Game_View::~Game_View()
{
    delete ui;
}

//Leaderboard example format, showing winning ratio
// LEADERBOARD: winner 2-0 (1.0)
void Game_View::load_leaderboard()
{
    Records& current = Records::instance();
    map <const string, Record> records_map = current.get_records();

  //  _data = Records::instance();
  //  map <const string, Record> records_map = _data.get_records();

    QStringList win_list;
    double win_ratio = 0.0;
    std::map <const string, Record>::iterator cur = records_map.begin();

    for (std::map <const string, Record>::iterator it = records_map.begin(); it != records_map.end(); ++it)
    {
        double temp = it->second.wins/(it->second.wins+it->second.losses);
        if(temp > win_ratio){
            win_ratio = temp;
            cur = it;
        }
    }

    _model = new QStringListModel(this);
    QString winner = cur->first.c_str();
    winner.append(" ");
    winner.append(std::to_string(cur->second.wins).c_str());
    winner.append("-");
    winner.append(std::to_string(cur->second.losses).c_str());
    winner.append(" (");
    winner.append(std::to_string(win_ratio).c_str());
    winner.append(")");
    win_list << winner;
    _model->setStringList(win_list);
    ui->leader_view->setModel(_model);
}
