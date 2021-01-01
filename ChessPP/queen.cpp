#include "queen.h"

Queen::Queen()
{

}


std::string Queen::getImagePath()
{
    if (color==PieceColor::black) return ":/images/QueenB.png";
    else return ":/images/QueenW.png";
}
