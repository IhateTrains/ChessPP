#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop final: public Piece
{
public:
    Bishop(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board){};
    [[nodiscard]] const std::string getImagePath() const;
};

#endif // BISHOP_H
