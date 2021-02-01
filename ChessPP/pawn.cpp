#include "pawn.h"
#include "board.h"


const std::string Pawn::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/PawnB.png";
    else return ":/images/PawnW.png";
}

bool Pawn::isLongMovePossible() const
{
    return board->isSquareUntouched(location.x, location.y);
}


const std::vector<Move>& Pawn::getLegalMoves()
{
    generateLegalMovesAndKingDangers();
    return legalMoves;
}

const std::vector<Location>& Pawn::getKingDangerSquarePositions()
{
    generateLegalMovesAndKingDangers();
    return kingDangerSquareLocations;
}

void Pawn::generateLegalMovesAndKingDangers()
{
    legalMoves.clear();
    kingDangerSquareLocations.clear();

    if (color == PieceColor::white)
    {
        if (location.y+1 < 8)
        {
            // regular move
            if (!board->getSquare(location.x, location.y+1)->containsPiece())
                addLegalMove(location.x, location.y+1, MoveType::simplePush);

            // first move can be a long move
            if (isLongMovePossible() && location.y+2 < 8 && !board->getSquare(location.x, location.y+1)->containsPiece() && !board->getSquare(location.x, location.y+2)->containsPiece())
            {
                addLegalMove(location.x, location.y+2, MoveType::simplePush);
            }

            //regular capture moves + en passant
            if (location.x-1 >= 0)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x-1, location.y+1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color && !possibleCaptureSquare->getPiece()->isKing())
                {
                    addLegalMove(location.x-1, location.y+1, MoveType::simpleCapture);
                }
                else if (!possibleCaptureSquare->containsPiece() && board->isEnpassantPossible(location.x-1, location.y+1)) // en passant is possible
                {
                    const auto& possibleEnPassantCaptureSquare = board->getSquare(location.x-1, location.y);
                    if (possibleEnPassantCaptureSquare->containsPiece())
                    {
                        addLegalMove(location.x-1, location.y+1, MoveType::enPassant);
                    }
                }
                addKingDangerSquarePos(location.x-1, location.y+1);
            }
            if (location.x+1 < 8)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x+1, location.y+1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color && !possibleCaptureSquare->getPiece()->isKing())
                {
                    addLegalMove(location.x+1, location.y+1, MoveType::simpleCapture);
                }
                else if (!possibleCaptureSquare->containsPiece() && board->isEnpassantPossible(location.x+1, location.y+1)) // en passant is possible
                {
                    const auto& possibleEnPassantCaptureSquare = board->getSquare(location.x+1, location.y);
                    if (possibleEnPassantCaptureSquare->containsPiece())
                    {
                        addLegalMove(location.x+1, location.y+1, MoveType::enPassant);
                    }
                }
                addKingDangerSquarePos(location.x+1, location.y+1);
            }
        }
    }
    else
    {
        if (location.y-1 >= 0)
        {
            // regular move
            if (!board->getSquare(location.x, location.y-1)->containsPiece())
                addLegalMove(location.x, location.y-1, MoveType::simplePush);

            // first move can be a long move
            if (isLongMovePossible() && location.y-2 >= 0 && !board->getSquare(location.x, location.y-1)->containsPiece() && !board->getSquare(location.x, location.y-2)->containsPiece())
            {
                addLegalMove(location.x, location.y-2, MoveType::simplePush);
            }

            //regular capture moves + en passant
            if (location.x-1 >= 0)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x-1, location.y-1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color)
                {
                    addLegalMove(location.x-1, location.y-1, MoveType::simpleCapture);
                }
                else if (!possibleCaptureSquare->containsPiece() && board->isEnpassantPossible(location.x-1, location.y-1)) // en passant is possible
                {
                    const auto& possibleEnPassantCaptureSquare = board->getSquare(location.x-1, location.y);
                    if (possibleEnPassantCaptureSquare->containsPiece())
                    {
                        addLegalMove(location.x-1, location.y-1, MoveType::enPassant);
                    }
                }
                addKingDangerSquarePos(location.x-1, location.y-1);
            }
            if (location.x+1 < 8)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x+1, location.y-1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color && !possibleCaptureSquare->getPiece()->isKing())
                {
                    addLegalMove(location.x+1, location.y-1, MoveType::simpleCapture);
                }
                else if (!possibleCaptureSquare->containsPiece() && board->isEnpassantPossible(location.x+1, location.y-1)) // en passant is possible
                {
                    const auto& possibleEnPassantCaptureSquare = board->getSquare(location.x+1, location.y);
                    if (possibleEnPassantCaptureSquare->containsPiece())
                    {
                        addLegalMove(location.x+1, location.y-1, MoveType::enPassant);
                    }
                }
                addKingDangerSquarePos(location.x+1, location.y-1);
            }
        }
    }
}


void Pawn::move(const Move& move)
{
    Piece::move(move);
    // promotion
    const auto& [x, y] = move.destPos;
    if ( (color == PieceColor::white && y==7) || (color == PieceColor::black && y==0) )
        board->promotePawn(x, y);
    // en passant
    else if (move.moveType == MoveType::enPassant)
    {
        if (color==PieceColor::white)
        {
            board->getSquare(x, y-1)->setPiece(nullptr);
        }
        else
        {
            board->getSquare(x, y+1)->setPiece(nullptr);
        }
    }

    board->gameDataVec.back().movesSinceLastLongPawnMove = 0;
}
