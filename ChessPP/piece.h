#ifndef PIECE_H
#define PIECE_H

#include <string>

enum class PieceColor { black, white };
enum class PieceType { king, queen, rook, bishop, knight, pawn };

struct Location
{
    unsigned int x;
    unsigned int y;
};

class Piece
{
public:
    Piece();

    PieceColor color;
    virtual std::string getImagePath() { throw("Something's wrong: getImagePath used in base Piece class!");};

private:
    Location location;
};

#endif // PIECE_H
