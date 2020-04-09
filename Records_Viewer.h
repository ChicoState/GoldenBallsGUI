#ifndef RECORDS_VIEWER_H
#define RECORDS_VIEWER_H

#include <QWidget>
#include <QStringListModel>
#include <QListView>
#include "ObserverPattern.h"
#include "Records.h"

namespace Ui {
class Records_Viewer;
}

//class Records_Viewer : public QWidget
class Records_Viewer : public QWidget, IObserver
{
    Q_OBJECT

public:
    explicit Records_Viewer(QWidget *parent = nullptr);
    void load_records();
    ~Records_Viewer();
    void update() override;

private:
    Ui::Records_Viewer *_ui;
    QStringListModel *_model;
    QListView _view;
    Records& _data;
};

#endif // RECORDS_VIEWER_H
