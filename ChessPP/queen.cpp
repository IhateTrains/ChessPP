#include "queen.h"



const std::string Queen::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/QueenB.png";
    else return ":/images/QueenW.png";
}


const std::vector<Move>& Queen::getLegalMoves()
{
    legalMoves.clear();

    // ROOK-LIKE MOVES
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

    // BISHOP-LIKE MOVES
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

const std::vector<Location>& Queen::getKingDangerSquarePositions()
{
    kingDangerSquareLocations.clear();

    // ROOK-LIKE MOVES
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

    // BISHOP-LIKE MOVES
    //up right
    auto x = location.x;
    for (auto y=location.y+1; y<8; ++y)
    {
        ++x;
        if (x<8)
        {
            if (tryAddKingDangerSquarePos(x, y))
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
            if (tryAddKingDangerSquarePos(x, y))
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
            if (tryAddKingDangerSquarePos(x, y))
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
            if (tryAddKingDangerSquarePos(x, y))
                break;
        }
    }

    return kingDangerSquareLocations;
}
