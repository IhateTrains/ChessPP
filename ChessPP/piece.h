#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>

enum class PieceColor { black, white };
enum class MoveType { onlyMove, onlyCapture, enPassant };

struct Location
{
    int x;
    int y;
};

class Move
{
public:
    Move(const Location& a, const Location& b, const MoveType& type): startPos(a), destPos(b), moveType(type) {};
    Location startPos;
    Location destPos;
    MoveType moveType;
};

class Board; // forward declaration
class Piece
{
public:
    Piece(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board);

    [[nodiscard]] virtual const std::string getImagePath() const { throw("Something's wrong: getImagePath used in base Piece class!");};
    [[nodiscard]] auto getColor() const { return color; }

    [[nodiscard]] const auto& getLocation() const { return location; }
    [[nodiscard]] virtual const std::vector<Move>& getLegalMoves() { return legalMoves; }
    virtual void move(unsigned short x, unsigned short y);

    [[nodiscard]] virtual const std::vector<Location>& getKingDangerSquarePositions() { return kingDangerSquareLocations; }

    [[nodiscard]] virtual bool isKing() { return false; }


protected:
    void addLegalMove(unsigned short x, unsigned short y, MoveType moveType) { legalMoves.emplace_back(Location{location.x, location.y}, Location{x, y}, moveType); }
    virtual bool tryAddLegalMove(unsigned short x, unsigned short y);

    void addKingDangerSquarePos(unsigned short x, unsigned short y) { kingDangerSquareLocations.push_back(Location{x, y}); }
    virtual bool tryAddKingDangerSquarePos(unsigned short x, unsigned short y);

    PieceColor color;

    std::vector<Move> legalMoves{};
    std::vector<Location> kingDangerSquareLocations{};

    std::shared_ptr<Board> board;
    Location location;

private:

};

#endif // PIECE_H
