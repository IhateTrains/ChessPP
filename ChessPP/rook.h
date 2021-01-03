#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook final: public Piece
{
public:
    Rook(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board){};

    [[nodiscard]] const std::string getImagePath() const;
    [[nodiscard]] const std::vector<Move>& getLegalMoves();
};

#endif // ROOK_H
