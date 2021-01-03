#include "bishop.h"
#include "board.h"



const std::string Bishop::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/BishopB.png";
    else return ":/images/BishopW.png";
}


const std::vector<Location>& Bishop::getLegalMoves()
{
    legalMoves.clear();

    //up right
    auto x = location.x;
    for (auto y=location.y+1; y<8; ++y)
    {
        ++x;
        if (x<8)
        {
            if (tryAddLegalMove(x, y))
                break;
        }
    }
    //up left
    x = location.x;
    for (auto y=location.y+1; y<8; ++y)
    {
        --x;
        if (x>=0)
        {
            if (tryAddLegalMove(x, y))
                break;
        }
    }
    //down right
    x = location.x;
    for (auto y=location.y-1; y>=0; --y)
    {
        ++x;
        if (x<8)
        {
            if (tryAddLegalMove(x, y))
                break;
        }
    }
    //down left
    x = location.x;
    for (auto y=location.y-1; y>=0; --y)
    {
        --x;
        if (x>=0)
        {
            if (tryAddLegalMove(x, y))
                break;
        }
    }

    return legalMoves;
}
