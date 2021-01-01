#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop();
    std::string getImagePath();
};

#endif // BISHOP_H
