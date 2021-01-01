#include "knight.h"

Knight::Knight()
{

}


std::string Knight::getImagePath()
{
    if (color==PieceColor::black) return ":/images/KnightB.png";
    else return ":/images/KnightW.png";
}
