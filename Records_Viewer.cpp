#include "Records_Viewer.h"
#include "Records.h"
#include "ui_Records_Viewer.h"
#include <string>
#include <map>
#include <QStringList>
#include <QListView>

Records_Viewer::Records_Viewer(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Records_Viewer),
    _data(Records::instance())
{
    _ui->setupUi(this);
    load_records();
    _data.addObserver(this);
}

void Records_Viewer::load_records()
{
    _data = Records::instance();
    map <const string, Record> records_map = _data.get_records();
    QStringList record_list;

    //record_list << "Player" << "Wins" << "Losses" << std::to_string(records_map.size()).c_str();

    for (std::map <const string, Record>::iterator it = records_map.begin(); it != records_map.end(); ++it)
    {
        QString player = it->first.c_str();
        player.append(" (");
        player.append(std::to_string(it->second.wins).c_str());
        player.append("-");
        player.append(std::to_string(it->second.losses).c_str());
        player.append(")");
        record_list << player;
    }

    _model = new QStringListModel(this);
    _model->setStringList(record_list);
    _ui->records_list_view->setModel(_model);
}

void Records_Viewer::update()
{
    load_records();
}

Records_Viewer::~Records_Viewer()
{
    delete _ui;
}

void Records_Viewer::update()
{
    load_records();
}
