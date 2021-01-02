#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen final: public Piece
{
public:
    Queen(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board){};
    [[nodiscard]] const std::string getImagePath() const;
};

#endif // QUEEN_H
