#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight final: public Piece
{
public:
    Knight(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board){};
    [[nodiscard]] const std::string getImagePath() const;

    [[nodiscard]] const std::vector<Move>& getLegalMoves();
    [[nodiscard]] const std::vector<Location>& getKingDangerSquarePositions();

private:
    void generateLegalMovesAndKingDangers();
};

#endif // KNIGHT_H
