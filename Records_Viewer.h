#ifndef RECORDS_VIEWER_H
#define RECORDS_VIEWER_H

#include <QWidget>
#include <QStringListModel>
#include <QListView>

namespace Ui {
class Records_Viewer;
}

class Records_Viewer : public QWidget
{
    Q_OBJECT

public:
    explicit Records_Viewer(QWidget *parent = nullptr);
    void load_records();
    ~Records_Viewer();

private:
    Ui::Records_Viewer *_ui;
    QStringListModel *_model;
    QListView _view;
};

#endif // RECORDS_VIEWER_H
