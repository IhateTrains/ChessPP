#include "king.h"
#include "board.h"



const std::string King::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/KingB.png";
    else return ":/images/KingW.png";
}


const std::vector<Location>& King::getLegalMoves()
{
    legalMoves.clear();


    auto enemyKingPos = board->getEnemyKingPos(color);

    for (auto y=location.y-1; y<=location.y+1; ++y)
    {
        if (y>=0 && y<8)
        {
            for (auto x=location.x-1; x<=location.x+1; ++x)
            {
                if (x>=0 && x<8)
                {
                    if (x == location.x && y == location.y)
                        continue;

                    // a king can't get inside enemy king's move range
                    if ((abs(x-enemyKingPos.x)+abs(y-enemyKingPos.y)<=1) || (abs(x-enemyKingPos.x)==1 && abs(y-enemyKingPos.y) == 1))
                        continue;

                    tryAddLegalMove(x, y);
                }
            }
        }
    }

    return legalMoves;
}
