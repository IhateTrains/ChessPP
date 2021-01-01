#include "king.h"

King::King()
{

}


std::string King::getImagePath()
{
    if (color==PieceColor::black) return ":/images/KingB.png";
    else return ":/images/KingW.png";
}
