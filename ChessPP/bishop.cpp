#include "bishop.h"



const std::string Bishop::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/BishopB.png";
    else return ":/images/BishopW.png";
}
