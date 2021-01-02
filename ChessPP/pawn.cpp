#include "pawn.h"
#include "board.h"


const std::string Pawn::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/PawnB.png";
    else return ":/images/PawnW.png";
}


const std::vector<Location>& Pawn::getLegalMoves()
{



    legalMoves.clear();
    if (color == PieceColor::white)
    {
        if (location.y+1 < 8 && !board->getSquare(location.x, location.y+1)->containsPiece())
        {
            legalMoves.emplace_back(Location{location.x, location.y+1});

            // first move can be a long move
            if (firstMove && location.y+2 < 8 && !board->getSquare(location.x, location.y+2)->containsPiece())
            {
                legalMoves.emplace_back(Location{location.x, location.y+2});
            }

            if (location.x-1 >= 0)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x-1, location.y+1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color)
                    legalMoves.emplace_back(Location{location.x-1, location.y+1});
            }
            if (location.x+1 < 8)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x+1, location.y+1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color)
                    legalMoves.emplace_back(Location{location.x+1, location.y+1});
            }
        }


    }
    else
    {
        if (location.y-1 >= 0 && !board->getSquare(location.x, location.y-1)->containsPiece())
        {
            legalMoves.emplace_back(Location{location.x, location.y-1});

            // first move can be a long move
            if (location.y-2 >= 0 && !board->getSquare(location.x, location.y-2)->containsPiece())
            {
                legalMoves.emplace_back(Location{location.x, location.y-2});

            }

            if (location.x-1 >= 0)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x-1, location.y-1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color)
                    legalMoves.emplace_back(Location{location.x-1, location.y-1});
            }
            if (location.x+1 < 8)
            {
                const auto& possibleCaptureSquare = board->getSquare(location.x+1, location.y-1);
                if (possibleCaptureSquare->containsPiece() && possibleCaptureSquare->getPiece()->getColor() != color)
                    legalMoves.emplace_back(Location{location.x+1, location.y-1});
            }
        }
    }

    return legalMoves;
}
