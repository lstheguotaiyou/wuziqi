#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include<vector>

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
const int board_grad_size = 16;
const int margin = 30;
const int block_size = 50;
const int chess_radius = 20;
const int choose_radius = 5;
const int mouse_radius = chess_radius;

class gamemodel
{
public:
    gamemodel();
public:
    std::vector<std::vector<int>> board_chess_data;
    std::vector<std::vector<int>> board_score_data;
    bool playflag;
    Gametype gametype;
    Gamestatus gamestatus;
    void startgame(Gametype type);



};

#endif // GAMEMODEL_H
