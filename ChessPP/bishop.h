#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop final: public Piece
{
public:
    Bishop(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board)
    {
        pieceStr = "B";
        if (color == PieceColor::white)
            pieceStr += "w";
        else
            pieceStr += "b";
    };
    [[nodiscard]] const std::string getImagePath() const;

    [[nodiscard]] const std::vector<Move>& getLegalMoves();
    [[nodiscard]] const std::vector<Location>& getKingDangerSquarePositions();

    [[nodiscard]] int getValue() const { return 3; }
};

#endif // BISHOP_H
