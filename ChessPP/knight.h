#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight();
    std::string getImagePath();
};

#endif // KNIGHT_H
