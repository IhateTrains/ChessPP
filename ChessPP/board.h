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
#include "promotiondialog.h"

enum class BoardState { defaultState, srcSelected };

struct GameData {
    unsigned short movesSinceLastLongPawnMove;
    Move lastMove;
};

class Board : public QObject
{
public:
    Board(QWidget* parent, QGridLayout* gridLayout);
    ~Board();

    void initialize(); // initial placement of pieces on the board

    [[nodiscard]] const auto& getSquare(const unsigned short x, const unsigned short y) const { return squaresArray[y][x]; }
    [[nodiscard]] const auto& getSquare(const Location& pos) const { return getSquare(pos.x, pos.y); }

    [[nodiscard]] Location getEnemyKingPos(const PieceColor playerColor) const;
    [[nodiscard]] const auto& getEnemyCaptures(const PieceColor playerColor) const;
    [[nodiscard]] bool isKingDangerSquare(const unsigned short x, const unsigned short y, const PieceColor kingColor) const;
    [[nodiscard]] bool isEnpassantPossible(unsigned short x, unsigned short y);

    void promotePawn(unsigned short x, unsigned short y);

    std::vector<GameData> gameDataVec = { {} };

public slots:
    void squareClicked(ClickableSquare* ptr);

    void loadState();
    void saveState();

private:
    void refresh();

    void changeMovingPlayerColor();
    [[nodiscard]] auto getOppositeColor(const PieceColor color) const;

    void generateMoves();
    void makeMove(const Move& move);

    void loadPlacementFromArray(const std::array<std::array<std::string, 8>, 8>& array);

    QWidget* parent = nullptr;
    QGridLayout* gridLayout = nullptr;
    std::shared_ptr<Board> sharedBoardPtr = nullptr;

    std::array<std::array<ClickableSquare*, 8>, 8> squaresArray;
    std::array<std::array<Move, 8>, 8> moveCache; // updated every time a moving piece is selected

    BoardState state = BoardState::defaultState;
    PieceColor movingPlayerColor = PieceColor::white;
    Location movingPieceLocation;


    std::map<PieceColor, std::vector<Move>> movesMap { { PieceColor::black, std::vector<Move>{} }, { PieceColor::white, std::vector<Move>{} } };
    std::map<PieceColor, std::vector<Move>> capturesMap { { PieceColor::black, std::vector<Move>{} }, { PieceColor::white, std::vector<Move>{} } };
    std::map<PieceColor, std::vector<Location>> kingDangerSquaresMap { { PieceColor::black, std::vector<Location>{} }, { PieceColor::white, std::vector<Location>{} } };
};

#endif // BOARD_H
