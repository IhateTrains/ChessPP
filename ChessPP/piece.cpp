#include "piece.h"
#include "board.h"



Piece::Piece(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): color(color), board(board), location{x, y}
{

}

void Piece::move(const Move& move)
{
    std::shared_ptr<Piece> capturedPiece = nullptr;
    if (move.moveType == MoveType::simpleCapture)
    {
        capturedPiece = board->getSquare(move.destPos)->getPiece();
    }

    const auto& piecePtr = board->getSquare(location)->getPiece();
    board->getSquare(move.destPos)->setPiece(piecePtr);
    board->getSquare(location)->setPiece(nullptr);

    location = move.destPos;

    auto temp = board->gameDataVec.back().movesSinceLastLongPawnMove;
    board->gameDataVec.emplace_back();

    board->gameDataVec.back().movesSinceLastLongPawnMove = temp+1;
    board->gameDataVec.back().lastMove = move;

    board->gameDataVec.back().untouchedSquares = board->gameDataVec[board->gameDataVec.size()-2].untouchedSquares;
    board->gameDataVec.back().untouchedSquares[location.y][location.x] = false;
    board->gameDataVec.back().untouchedSquares[move.startPos.y][move.startPos.x] = false;

    board->gameDataVec.back().lastCapturedPiece = capturedPiece;
}


bool Piece::tryAddLegalMove(unsigned short x, unsigned short y)
{
    // returns true if it's supposed to break a loop

    const auto& destSquare = board->getSquare(x, y);

    if (!destSquare->containsPiece())
    {
        addLegalMove(x, y, MoveType::simplePush);
    }
    else if (destSquare->getPiece()->getColor() != color && !destSquare->getPiece()->isKing())
    {
        addLegalMove(x, y, MoveType::simpleCapture);
        return true;
    }
    else
        return true;

    return false;
}


bool Piece::tryAddKingDangerSquarePos(unsigned short x, unsigned short y)
{
    // returns true if it's supposed to break a loop

    const auto& destSquare = board->getSquare(x, y);

    if (!destSquare->containsPiece())
    {
        addKingDangerSquarePos(x, y);
    }
    else if (destSquare->getPiece()->getColor() != color)
    {
        addKingDangerSquarePos(x, y);
        if (!destSquare->getPiece()->isKing())
            return true;
    }
    else
        return true;

    return false;
}
