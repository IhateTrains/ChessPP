#include "piece.h"
#include "board.h"

Piece::Piece(unsigned short x, unsigned short y, PieceColor color, std::shared_ptr<Board> board): color(color), board(board), location{x, y}
{

}
