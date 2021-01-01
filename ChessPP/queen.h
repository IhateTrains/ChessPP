#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen();
    std::string getImagePath();
};

#endif // QUEEN_H
