#include "gamemodel.h"

gamemodel::gamemodel()
{

}
//first setup data
void gamemodel::startgame(Gametype type)
{
    type = gametype;
    board_chess_data.clear();
    for(int i = 0;i<board_grad_size;i++)
    {
        std::vector<int> lineboard;
        for(int j = 0;j<board_grad_size;j++)
            lineboard.push_back(0);
        board_chess_data.push_back(lineboard);
    }
}
