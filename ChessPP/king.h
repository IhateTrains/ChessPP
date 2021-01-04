#ifndef KING_H
#define KING_H

#include "piece.h"

class King final: public Piece
{
public:
    King(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board){};
    [[nodiscard]] const std::string getImagePath() const;

    [[nodiscard]] const std::vector<Move>& getLegalMoves();
    [[nodiscard]] const std::vector<Location>& getKingDangerSquarePositions();

    [[nodiscard]] bool isKing() { return true; }

private:
    void generateLegalMovesAndKingDangers();
};

#endif // KING_H
