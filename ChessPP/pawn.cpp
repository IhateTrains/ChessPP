#include "pawn.h"
#include "board.h"


const std::string Pawn::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/PawnB.png";
    else return ":/images/PawnW.png";
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
                addLegalMove(location.x, location.y+1, MoveType::onlyMove);

            // first move can be a long move
            if (firstMove && location.y+2 < 8 && !board->getSquare(location.x, location.y+1)->containsPiece() && !board->getSquare(location.x, location.y+2)->containsPiece())
            {
                addLegalMove(location.x, location.y+2, MoveType::onlyMove);
            }

            //regular capture moves
            if (location.x-1 >= 0)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x-1, location.y+1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color && !possibleCaptureSquare->getPiece()->isKing())
                {
                    addLegalMove(location.x-1, location.y+1, MoveType::onlyCapture);
                }
                addKingDangerSquarePos(location.x-1, location.y+1);

            }
            if (location.x+1 < 8)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x+1, location.y+1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color && !possibleCaptureSquare->getPiece()->isKing())
                {
                    addLegalMove(location.x+1, location.y+1, MoveType::onlyCapture);
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
                addLegalMove(location.x, location.y-1, MoveType::onlyMove);

            // first move can be a long move
            if (firstMove && location.y-2 >= 0 && !board->getSquare(location.x, location.y-1)->containsPiece() && !board->getSquare(location.x, location.y-2)->containsPiece())
            {
                addLegalMove(location.x, location.y-2, MoveType::onlyMove);
            }

            //regular capture moves
            if (location.x-1 >= 0)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x-1, location.y-1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color)
                {
                    addLegalMove(location.x-1, location.y-1, MoveType::onlyCapture);
                }
                addKingDangerSquarePos(location.x-1, location.y-1);
            }
            if (location.x+1 < 8)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x+1, location.y-1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color && !possibleCaptureSquare->getPiece()->isKing())
                {
                    addLegalMove(location.x+1, location.y-1, MoveType::onlyCapture);
                }
                addKingDangerSquarePos(location.x+1, location.y-1);
            }
        }
    }
}


void Pawn::move(unsigned short x, unsigned short y)
{
    Piece::move(x,y);
    firstMove = false;
}
