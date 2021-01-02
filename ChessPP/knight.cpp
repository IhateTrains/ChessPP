#include "knight.h"



const std::string Knight::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/KnightB.png";
    else return ":/images/KnightW.png";
}
