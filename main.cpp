#include "mainwindow.h"
#include "Records.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication qt_app(argc, argv);
    MainWindow menu;
    Records& records_singleton = Records::instance();
    records_singleton.update_record("loser",false);
    records_singleton.update_record("winner",true);
    records_singleton.update_record("winner",false);

    menu.show();
    return qt_app.exec();
}
