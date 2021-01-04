#include "knight.h"



const std::string Knight::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/KnightB.png";
    else return ":/images/KnightW.png";
}


const std::vector<Move>& Knight::getLegalMoves()
{
    generateLegalMovesAndKingDangers();
    return legalMoves;
}

const std::vector<Location>& Knight::getKingDangerSquarePositions()
{
    generateLegalMovesAndKingDangers();
    return kingDangerSquareLocations;
}

void Knight::generateLegalMovesAndKingDangers()
{
    legalMoves.clear();
    kingDangerSquareLocations.clear();

    auto x = location.x - 2;
    auto y = location.y + 1;
    if (x>=0 && y<8)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }

    x = location.x - 2;
    y = location.y - 1;
    if (x>=0 && y>=0)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }

    x = location.x - 1;
    y = location.y - 2;
    if (x>=0 && y>=0)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }

    x = location.x + 1;
    y = location.y - 2;
    if (x<8 && y>=0)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }

    x = location.x + 2;
    y = location.y - 1;
    if (x<8 && y>=0)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }

    x = location.x + 2;
    y = location.y + 1;
    if (x<8 && y<8)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }

    x = location.x - 1;
    y = location.y + 2;
    if (x>=0 && y<8)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }

    x = location.x + 1;
    y = location.y + 2;
    if (x<8 && y<8)
    {
        tryAddLegalMove(x, y);
        tryAddKingDangerSquarePos(x, y);
    }
}
