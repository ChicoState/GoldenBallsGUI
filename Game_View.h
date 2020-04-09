#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class Game_View;
}

class Game_View : public QWidget
{
    Q_OBJECT

public:
    explicit Game_View(QWidget *parent = nullptr);
    ~Game_View();
    void load_leaderboard();

private:
    Ui::Game_View *ui;
    QStringListModel *_model;

};

#endif // GAME_VIEW_H
