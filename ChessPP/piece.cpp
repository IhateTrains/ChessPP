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


bool Piece::tryAddLegalMove(unsigned short x, unsigned short y)
{
    // returns true if it's supposed to break a loop

    const auto& destSquare = board->getSquare(x, y);

    if (!destSquare->containsPiece())
    {
        addLegalMove(x, y);
    }
    else if (destSquare->getPiece()->getColor() != color)
    {
        addLegalMove(x, y);
        return true;
    }
    else
        return true;

    return false;
}
