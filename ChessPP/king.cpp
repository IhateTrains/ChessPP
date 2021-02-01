#include "king.h"
#include "board.h"



const std::string King::getImagePath() const
{
    if (color==PieceColor::black) return ":/images/KingB.png";
    else return ":/images/KingW.png";
}


const std::vector<Move>& King::getLegalMoves()
{
    generateLegalMovesAndKingDangers();
    return legalMoves;
}

const std::vector<Location>& King::getKingDangerSquarePositions()
{
    generateLegalMovesAndKingDangers();
    return kingDangerSquareLocations;
}

void King::move(const Move& move)
{
    Piece::move(move);

    // castling
    if (move.moveType == MoveType::castling)
    {
        // move the rook
        if (move.destPos.x == 2)
        {
            board->getSquare(3, move.destPos.y)->setPiece(board->getSquare(0, move.destPos.y)->getPiece());
            board->getSquare(3, move.destPos.y)->getPiece()->setLocation(3, move.destPos.y);
            board->getSquare(0, move.destPos.y)->setPiece(nullptr);
        }
        else // destPos.x == 6
        {
            board->getSquare(5, move.destPos.y)->setPiece(board->getSquare(7, move.destPos.y)->getPiece());
            board->getSquare(5, move.destPos.y)->getPiece()->setLocation(5, move.destPos.y);
            board->getSquare(7, move.destPos.y)->setPiece(nullptr);
        }
    }
}


void King::generateLegalMovesAndKingDangers()
{
    legalMoves.clear();
    kingDangerSquareLocations.clear();

    auto enemyKingPos = board->getEnemyKingPos(color);

    // regular moves
    for (auto y=location.y-1; y<=location.y+1; ++y)
    {
        if (y>=0 && y<8)
        {
            for (auto x=location.x-1; x<=location.x+1; ++x)
            {
                if (x>=0 && x<8)
                {
                    if (x == location.x && y == location.y)
                        continue;

                    // a king can't get inside enemy king's move range
                    if ((abs(x-enemyKingPos.x)+abs(y-enemyKingPos.y)<=1) || (abs(x-enemyKingPos.x)==1 && abs(y-enemyKingPos.y) == 1))
                    {
                        tryAddKingDangerSquarePos(x, y);
                        continue;
                    }

                    // a king can't move onto a square that is in check
                    if (board->isKingDangerSquare(x, y, color))
                    {
                        tryAddKingDangerSquarePos(x, y);
                        continue;
                    }

                    tryAddLegalMove(x, y);
                    tryAddKingDangerSquarePos(x, y);

                }
            }
        }
    }
    // castling
    const auto& [x, y] = location;
    if (board->isSquareUntouched(x, y)) // only possible if rook hasn't moved
    {
        // to the right
        if (!board->getSquare(x+1, y)->containsPiece() && !board->getSquare(x+2, y)->containsPiece())
        {
            if (board->isSquareUntouched(x+3, y)) // rook hasn't moved
            {
                addLegalMove(x+2, y, MoveType::castling);
            }
        }
        // to the left
        if (!board->getSquare(x-1, y)->containsPiece() && !board->getSquare(x-2, y)->containsPiece())
        {
            if (board->isSquareUntouched(x-4, y)) // rook hasn't moved
            {
                addLegalMove(x-2, y, MoveType::castling);
            }
        }
    }
}
