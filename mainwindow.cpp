#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpainter.h>
#include<QMouseEvent>
#include <math.h>
#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setGeometry(0,0,16*50+4,16*50+4);
    this->setGeometry(0,0,board_number_size*block_size+2*margin,board_number_size*block_size+2*margin);
    this->setFixedSize(board_number_size*block_size+2*margin,board_number_size*block_size+2*margin);
    //start_up this define a setup fuction
    set_up();

}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::distance(int x_1, int y_1, int x_2, int y_2)
{
    float result = sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
    return result;
}



void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing,true);

    for(int i=0;i<board_number_size+1;i++)
    {
        painter.drawLine(margin+i*block_size,margin,margin+i*block_size,this->height()- margin);
        painter.drawLine(margin,margin+i*block_size,this->width()-margin,margin+i*block_size);
    }
    //

    QPen pen;
    QBrush brush;
    if(ISchoose)
    {
//        if(game->chesscolor ==black)
//        {
//            pen.setColor(Qt::black);
//            brush.setColor(Qt::darkRed);
//        }
        if(game->chesscolor ==black)
        {
            pen.setColor(Qt::black);
            brush.setColor(Qt::black);
        }
        else
        {
            pen.setColor(Qt::white);
            brush.setColor(Qt::white);
        }


        brush.setStyle(Qt::SolidPattern);
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(choose_X-3,choose_Y-3,6,6);
    }
    //画出棋盘上的妻子
    if(paintzi)
    {
        for(int i = 0;i<board_number_size;i++)
        {
            for(int j = 0;j<board_number_size;j++)
            {
                if(game->board_chess_data[i][j]==1)
                {
                    pen.setColor(Qt::black);
                    brush.setColor(Qt::black);
                    painter.drawEllipse(margin+block_size*i-chess_radius,margin+block_size*j-chess_radius,2*chess_radius,2*chess_radius);
//                    qDebug()<<i<<","<<j<<endl;
                }
                if(game->board_chess_data[i][j]==-1)
                {
                    pen.setColor(Qt::white);
                    brush.setColor(Qt::white);
                    painter.drawEllipse(margin+block_size*i-chess_radius,margin+block_size*j-chess_radius,2*chess_radius,2*chess_radius);
//                    qDebug()<<i<<","<<j<<endl;

                }
            }
        }
    }
//    paintzi = false;

// WARNING:更新函数
    update();
//painter.drawEllipse(margin+block_size*1-25,margin+block_size*1-25,50,50);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    int hang = (x-margin)/block_size;
    int lie = (y-margin)/block_size;
    int left_up_X=margin+hang*block_size;
    int left_up_Y=margin+lie*block_size;


    for(int i=0;i<4;i++)
    {

        float dis_0 = distance(x,y,left_up_X,left_up_Y);
        if(dis_0<mouse_radius)//到规定距离
        {
            if(left_up_X!=margin && left_up_X!=this->width()-margin&& left_up_Y!=margin&&left_up_Y!=this->height()-margin)//不落在margin上
            {
                //TODO:添加选中的行和列，计算不行应该计算量过大，报错溢了

                    choose_X = left_up_X;
                    choose_Y = left_up_Y;
                    ISchoose = true;
//                    qDebug()<<choose_X<<","<<choose_Y<<endl;
                    break;

            }
        }
        if(i==0)
            left_up_X+=block_size;
        if(i==1)
            left_up_Y+=block_size;
        if(i==2)
            left_up_X-=block_size;
        if(i==3)
        {
            left_up_Y-=block_size;
            //fix a bug
            ISchoose = false;
        }
    }

//    if()
    //TODO:可以优化一下算法的合理写法
    //得到了判距和坐标，画图paintevent里

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
//    int x = event->x();
//    int y = event->y();
//    qDebug()<<"clicked "<<x<<" "<<y<<endl;
    //luozi条件判断,1.选中
    if(ISchoose)
    {
        add_chess_data();
    }
}

void MainWindow::set_up()
{
    game = new gamemodel();
    //这里写ai和对弈的两个入口函数
    initAIgame();

}

void MainWindow::initAIgame()
{
    game->gametype = AI;
    game->gamestatus =PLAYING;
    game->startgame(game->gametype);
}

void MainWindow::add_chess_data()
{
//    qDebug()<<(choose_X-margin)/block_size<<(choose_Y-margin)/block_size<<endl;
    int colomn = (choose_X-margin)/block_size;
    int line = (choose_Y-margin)/block_size;
    //判断没有棋子
    if(game->board_chess_data[colomn][line] ==0)
    {
        //哎呀自己SB了
        if(game->chesscolor == black)
        {
            game->board_chess_data[colomn][line] = 1;
            game->chesscolor = white;
            qDebug()<<"1"<<endl;
        }
        else
        {
            game->board_chess_data[colomn][line] = -1;
            game->chesscolor = black;
//            qDebug()<<"2"<<endl;

        }

//        qDebug()<<"luole"<<endl;
        //luozi标志，在paint函数中判断的
        paintzi = true;
    }
}

