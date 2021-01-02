#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>

enum class PieceColor { black, white };
//enum class PieceType { king, queen, rook, bishop, knight, pawn };

struct Location
{
    int x;
    int y;
};

class Board; // forward declaration
class Piece
{
public:
    Piece(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board);

    [[nodiscard]] virtual const std::string getImagePath() const { throw("Something's wrong: getImagePath used in base Piece class!");};
    [[nodiscard]] auto getColor() const { return color; }
    [[nodiscard]] const auto& getLocation() const { return location; }
    [[nodiscard]] virtual const std::vector<Location>& getLegalMoves() { return legalMoves; }


protected:
    PieceColor color;
    std::vector<Location> legalMoves{};
    std::shared_ptr<Board> board;
    Location location;

private:
};

#endif // PIECE_H
