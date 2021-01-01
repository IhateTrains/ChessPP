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

enum class BoardState { defaultState, srcSelected, destSelected };

class Board : public QObject
{
public:
    Board(QWidget* parent, QGridLayout* gridLayout);

    void initialize(); // initial placement of pieces on the board


    QVector<ClickableSquare*> squaresVec;
    QGridLayout* gridLayout = nullptr;

public slots:
    void squareClicked(ClickableSquare* ptr);

private:
    BoardState state = BoardState::defaultState;
};

#endif // BOARD_H
