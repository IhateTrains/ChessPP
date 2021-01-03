#include "piece.h"
#include "board.h"

Piece::Piece(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): color(color), board(board), location{x, y}
{

}

void Piece::move(unsigned short x, unsigned short y)
{
    const auto& piecePtr = board->getSquare(location.x, location.y)->getPiece();
    board->getSquare(x, y)->setPiece(piecePtr);
    board->getSquare(location.x, location.y)->setPiece(nullptr);

    location.x = x;
    location.y = y;
}
