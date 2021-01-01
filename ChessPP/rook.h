#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
public:
    Rook();
    std::string getImagePath();
};

#endif // ROOK_H
