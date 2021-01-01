#include "rook.h"

Rook::Rook()
{

}


std::string Rook::getImagePath()
{
    if (color==PieceColor::black) return ":/images/RookB.png";
    else return ":/images/RookW.png";
}
