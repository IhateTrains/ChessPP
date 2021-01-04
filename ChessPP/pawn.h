#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn final: public Piece
{
public:
    Pawn(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): Piece(x, y, color, board){};

    [[nodiscard]] const std::string getImagePath() const;
    [[nodiscard]] bool isLongMovePossible() const { return firstMove; }

    [[nodiscard]] const std::vector<Move>& getLegalMoves();
    [[nodiscard]] const std::vector<Location>& getKingDangerSquarePositions();

    void move(unsigned short x, unsigned short y);

private:
    bool firstMove = true;
    void generateLegalMovesAndKingDangers();
};

#endif // PAWN_H
