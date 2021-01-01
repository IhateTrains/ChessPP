#include "pawn.h"

Pawn::Pawn()
{

}


std::string Pawn::getImagePath()
{
    if (color==PieceColor::black) return ":/images/PawnB.png";
    else return ":/images/PawnW.png";
}
