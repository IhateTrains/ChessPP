#ifndef BOARD_H
#define BOARD_H

#include "clickableSquare.h"

#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

#include <QVector>
#include <QGridLayout>
#include "qmessagebox.h"

enum class BoardState { defaultState, srcSelected, destSelected };

class Board : public QObject
{
public:
    Board(QWidget* parent, QGridLayout* gridLayout);

    void initialize(); // initial placement of pieces on the board
    [[nodiscard]] const auto& getSquare(const int x, const int y) const { return squaresVec[y][x]; }

public slots:
    void squareClicked(ClickableSquare* ptr);

private:
    void refresh();

    QGridLayout* gridLayout = nullptr;
    BoardState state = BoardState::defaultState;
    PieceColor movingPlayerColor = PieceColor::white;

    std::array<std::array<ClickableSquare*, 8>, 8> squaresVec;
    Location movingPieceLocation;
};

#endif // BOARD_H
