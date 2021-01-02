#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight final: public Piece
{
public:
    Knight(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board){};
    [[nodiscard]] const std::string getImagePath() const;
};

#endif // KNIGHT_H
