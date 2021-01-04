#include "king.h"
#include "board.h"



const std::string King::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/KingB.png";
    else return ":/images/KingW.png";
}


const std::vector<Move>& King::getLegalMoves()
{
    generateLegalMovesAndKingDangers();
    return legalMoves;
}

const std::vector<Location>& King::getKingDangerSquarePositions()
{
    generateLegalMovesAndKingDangers();
    return kingDangerSquareLocations;
}


void King::generateLegalMovesAndKingDangers()
{
    legalMoves.clear();
    kingDangerSquareLocations.clear();

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
                    {
                        tryAddKingDangerSquarePos(x, y);
                        continue;
                    }

                    // a king can't move onto a square that is in check
                    if (board->isKingDangerSquare(x, y, color))
                    {
                        tryAddKingDangerSquarePos(x, y);
                        continue;
                    }

                    tryAddLegalMove(x, y);
                    tryAddKingDangerSquarePos(x, y);

                }
            }
        }
    }
}
