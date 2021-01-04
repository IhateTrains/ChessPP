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
    [[nodiscard]] const auto& getSquare(const unsigned short x, const unsigned short y) const { return squaresVec[y][x]; }

    [[nodiscard]] Location getEnemyKingPos(const PieceColor playerColor) const;
    [[nodiscard]] const auto& getEnemyCaptures(const PieceColor playerColor) const;
    [[nodiscard]] bool isKingDangerSquare(const unsigned short x, const unsigned short y, const PieceColor kingColor) const;


public slots:
    void squareClicked(ClickableSquare* ptr);

private:
    void refresh();
    void changeMovingPlayerColor();
    [[nodiscard]] auto getOppositeColor(const PieceColor color) const;
    void generateMoves();

    QGridLayout* gridLayout = nullptr;

    std::array<std::array<ClickableSquare*, 8>, 8> squaresVec;

    BoardState state = BoardState::defaultState;
    PieceColor movingPlayerColor = PieceColor::white;
    Location movingPieceLocation;

    std::map<PieceColor, std::vector<Move>> movesMap { { PieceColor::black, std::vector<Move>{} }, { PieceColor::white, std::vector<Move>{} } };
    std::map<PieceColor, std::vector<Move>> capturesMap { { PieceColor::black, std::vector<Move>{} }, { PieceColor::white, std::vector<Move>{} } };

    std::map<PieceColor, std::vector<Location>> kingDangerSquaresMap { { PieceColor::black, std::vector<Location>{} }, { PieceColor::white, std::vector<Location>{} } };
};

#endif // BOARD_H
