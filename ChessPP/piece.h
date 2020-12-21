#ifndef PIECE_H
#define PIECE_H

enum class PieceColor { black, white };

class Piece
{
public:
    Piece();

    PieceColor color;
};

#endif // PIECE_H
