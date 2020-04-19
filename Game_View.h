#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QWidget>
#include "ObserverPattern.h"
#include "Records.h"

namespace Ui {
class Game_View;
}

class Game_View : public QWidget, IObserver
{
    Q_OBJECT

public:
    explicit Game_View(QWidget *parent = nullptr);
    ~Game_View();
    void update() override;

private:
    Ui::Game_View *ui;
    Records& _all_records;
};

#endif // GAME_VIEW_H
