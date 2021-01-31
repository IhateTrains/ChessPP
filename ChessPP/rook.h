#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook final: public Piece
{
public:
    Rook(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board)
    {
        pieceStr = "R";
        if (color == PieceColor::white)
            pieceStr += "w";
        else
            pieceStr += "b";
    };

    [[nodiscard]] const std::string getImagePath() const;

    [[nodiscard]] const std::vector<Move>& getLegalMoves();
    [[nodiscard]] const std::vector<Location>& getKingDangerSquarePositions();

    [[nodiscard]] int getValue() const { return 5; }
};

#endif // ROOK_H
