#include "bishop.h"

Bishop::Bishop()
{

}


std::string Bishop::getImagePath()
{
    if (color==PieceColor::black) return ":/images/BishopB.png";
    else return ":/images/BishopW.png";
}
