#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<gamemodel.h>
#include <DICOMAppHelper.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//const int board_grad_size = 16;
//const int margin = 30;
//const int block_size = 50;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float distance(int x_1,int y_1,int x_2,int y_2);
//    void paintevent();
private:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void set_up();
    void initAIgame();
    void initMANgame();
    void add_chess_data();
    void Iswin();
    void Iswinheng();

private:
    Ui::MainWindow *ui;
    gamemodel *game;
    Gametype game_type;
    bool ISchoose = false;
    int choose_X,choose_Y;
    bool paintzi = false;
    int clicked_X,clicked_Y;
    int clicked_color;

};
#endif // MAINWINDOW_H
