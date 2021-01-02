#include "queen.h"



const std::string Queen::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/QueenB.png";
    else return ":/images/QueenW.png";
}
