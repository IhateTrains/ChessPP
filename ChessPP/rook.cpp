#include "rook.h"
#include "board.h"



const std::string Rook::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/RookB.png";
    else return ":/images/RookW.png";
}

const std::vector<Location>& Rook::getLegalMoves()
{
    legalMoves.clear();

    // from a to h
    for (auto x=location.x+1; x<8; ++x)
    {
        if (!board->getSquare(x, location.y)->containsPiece())
        {
            addLegalMove(x, location.y);
        }
        else if (board->getSquare(x, location.y)->getPiece()->getColor() != color)
        {
            addLegalMove(x, location.y);
            break;
        }
        else
            break;
    }

    // from h to a
    for (auto x=location.x-1; x>=0; --x)
    {
        if (!board->getSquare(x, location.y)->containsPiece())
        {
            addLegalMove(x, location.y);
        }
        else if (board->getSquare(x, location.y)->getPiece()->getColor() != color)
        {
            addLegalMove(x, location.y);
            break;
        }
        else
            break;
    }

    // from 1 to 8
    for (auto y=location.y+1; y<8; ++y)
    {
        if (!board->getSquare(location.x, y)->containsPiece())
        {
            addLegalMove(location.x, y);
        }
        else if (board->getSquare(location.x, y)->getPiece()->getColor() != color)
        {
            addLegalMove(location.x, y);
            break;
        }
        else
           break;
    }

    // from 8 to 1
    for (auto y=location.y-1; y>=0; --y)
    {
        if (!board->getSquare(location.x, y)->containsPiece())
        {
            addLegalMove(location.x, y);
        }
        else if (board->getSquare(location.x, y)->getPiece()->getColor() != color)
        {
            addLegalMove(location.x, y);
            break;
        }
        else
            break;
    }



    return legalMoves;
}
