#include "gamemodel.h"

gamemodel::gamemodel()
{

}

int gamemodel::Isaddfiveheng(int x, int y,int signal)
{
    int result;
    if(x+4>15)
        return 0;
    else
    result = board_chess_data[x][y]+board_chess_data[x+1][y]+board_chess_data[x+2][y]+board_chess_data[x+3][y]+board_chess_data[x+4][y];
    if(signal == 1&& result == 5)
        return 1;
    else if(signal == -1 && result ==-5)
        return -1;
    else
        return 0;


}

int gamemodel::Isaddfiveshu(int x, int y, int signal)
{
    int result;
    if(y+4>15)
        return 0;
    else
    result = board_chess_data[x][y]+board_chess_data[x][y+1]+board_chess_data[x][y+2]+board_chess_data[x][y+3]+board_chess_data[x][y+4];
    if(signal == 1&& result == 5)
        return 1;
    else if(signal == -1 && result ==-5)
        return -1;
    else
        return 0;


}

int gamemodel::Isaddfivepie(int x, int y, int signal)
{
    int result;
    if(y+4>15||x+4>15)
        return 0;
    else
        result = board_chess_data[x][y]+board_chess_data[x+1][y+1]+board_chess_data[x+2][y+2]+board_chess_data[x+3][y+3]+board_chess_data[x+4][y+4];
    if(signal == 1&& result == 5)
        return 1;
    else if(signal == -1 && result ==-5)
        return -1;
    else
        return 0;

}

int gamemodel::Isaddfivena(int x, int y, int signal)
{
    int result;
    if(x-4<0||y+4>15)
        return 0;
    else
        result = board_chess_data[x][y]+board_chess_data[x-1][y+1]+board_chess_data[x-2][y+2]+board_chess_data[x-3][y+3]+board_chess_data[x-4][y+4];
    if(signal == 1&& result == 5)
        return 1;
    else if(signal == -1 && result ==-5)
        return -1;
    else
        return 0;



}
//first setup data
void gamemodel::startgame(Gametype type)
{
    type = gametype;
    chesscolor = black;
    board_chess_data.clear();
    for(int i = 0;i<board_number_size;i++)
    {
        std::vector<int> lineboard;
        for(int j = 0;j<board_number_size;j++)
            lineboard.push_back(0);
        board_chess_data.push_back(lineboard);
    }
}
