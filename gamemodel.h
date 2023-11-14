#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include<vector>
#include <QSplashScreen>
enum Gametype
{
    MAN,
    AI
};
enum Gamestatus{
    PLAYING,
    WIN,
    DEFEAT
};
enum chess_color{
    black,
    white
};

const int board_number_size = 16;
const int margin = 30;
const int block_size = 50;
const int chess_radius = 20;
const int choose_radius = 5;
const int mouse_radius = chess_radius;

class gamemodel
{
public:
    gamemodel();
    int Isaddfiveheng(int x,int y,int signal);
public:
    std::vector<std::vector<int>> board_chess_data;
    std::vector<std::vector<int>> board_score_data;
    bool playflag;
    Gametype gametype;
    Gamestatus gamestatus;
    void startgame(Gametype type);
    chess_color chesscolor ;



};

#endif // GAMEMODEL_H
