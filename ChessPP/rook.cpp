#include "rook.h"
#include "board.h"



const std::string Rook::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/RookB.png";
    else return ":/images/RookW.png";
}

const std::vector<Move>& Rook::getLegalMoves()
{
    legalMoves.clear();

    // from a to h
    for (auto x=location.x+1; x<8; ++x)
    {
        if(tryAddLegalMove(x, location.y))
            break;
    }

    // from h to a
    for (auto x=location.x-1; x>=0; --x)
    {
        if(tryAddLegalMove(x, location.y))
            break;
    }

    // from 1 to 8
    for (auto y=location.y+1; y<8; ++y)
    {
        if(tryAddLegalMove(location.x, y))
            break;
    }

    // from 8 to 1
    for (auto y=location.y-1; y>=0; --y)
    {
        if(tryAddLegalMove(location.x, y))
            break;
    }

    return legalMoves;
}

const std::vector<Location>& Rook::getKingDangerSquarePositions()
{
    kingDangerSquareLocations.clear();

    // from a to h
    for (auto x=location.x+1; x<8; ++x)
    {
        if(tryAddKingDangerSquarePos(x, location.y))
            break;
    }

    // from h to a
    for (auto x=location.x-1; x>=0; --x)
    {
        if(tryAddKingDangerSquarePos(x, location.y))
            break;
    }

    // from 1 to 8
    for (auto y=location.y+1; y<8; ++y)
    {
        if(tryAddKingDangerSquarePos(location.x, y))
            break;
    }

    // from 8 to 1
    for (auto y=location.y-1; y>=0; --y)
    {
        if(tryAddKingDangerSquarePos(location.x, y))
            break;
    }

    return kingDangerSquareLocations;
}
