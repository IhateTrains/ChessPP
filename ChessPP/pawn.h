#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn();
    std::string getImagePath();
};

#endif // PAWN_H
