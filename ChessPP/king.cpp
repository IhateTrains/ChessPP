#include "king.h"



const std::string King::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/KingB.png";
    else return ":/images/KingW.png";
}
