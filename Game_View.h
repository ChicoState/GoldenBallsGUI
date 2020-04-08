#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QWidget>

namespace Ui {
class Game_View;
}

class Game_View : public QWidget
{
    Q_OBJECT

public:
    explicit Game_View(QWidget *parent = nullptr);
    ~Game_View();

private:
    Ui::Game_View *ui;
};

#endif // GAME_VIEW_H
