#include "rook.h"



const std::string Rook::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/RookB.png";
    else return ":/images/RookW.png";
}

const std::vector<Location>& Rook::getLegalMoves()
{
    legalMoves.clear();

    // from a to h

    // from h to a

    // from 1 to 8
    // from 8 to 8



    return legalMoves;
}
