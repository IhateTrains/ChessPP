#include "board.h"



Board::Board(QWidget* parent, QGridLayout* gridLayout): gridLayout(gridLayout)
{
    for (auto y = 7; y>=0; --y)
    {
         for (auto x = 0; x<8; ++x)
         {
             // determine square color and create a chess square
             ClickableSquare* pole;
             if ((y+(x%2))%2 == 0)
                 pole = new ClickableSquare(x, y, CIEMNY, parent); // dark square
             else
                 pole = new ClickableSquare(x, y, JASNY, parent); // bright square

             // connect square's signals to board's slot
             QObject::connect(pole, &ClickableSquare::clicked,
                         this, &Board::squareClicked);
             // add square to array
             squaresVec[y][x] = pole;

             // set the square size
             pole->setFixedHeight(80);
             pole->setFixedWidth(80);

             // add the square to the board
             this->gridLayout->addWidget(pole,7-y,x);
         }
    }
}

void Board::initialize()
{
    /*
     * King = K
     * Queen = Q
     * Knight = N
     * Bishop = B
     * Rook = R
     * Pawn = p
     * no piece = 0 (color not needed)
     *
     * black = b
     * white = w
    */
    std::array<std::array<std::string, 8>, 8> initialPlecement { {
        {"Rb", "Nb", "Bb", "Qb", "Kb", "Bb", "Nb", "Rb"},
        {"pb", "pb", "pb", "pb", "pb", "pb", "pb", "pb"},
        { "0",  "0",  "0",  "0",  "0",  "0",  "0",  "0"},
        { "0",  "0",  "0",  "0",  "0",  "0",  "0",  "0"},
        { "0",  "0",  "0",  "0",  "0",  "0",  "0",  "0"},
        { "0",  "0",  "0",  "0",  "0",  "0",  "0",  "0"},
        {"pw", "pw", "pw", "pw", "pw", "pw", "pw", "pw"},
        {"Rw", "Nw", "Bw", "Kw", "Qw", "Bw", "Nw", "Rw"},
    } };


    auto sharedBoardPtr = std::shared_ptr<Board>(this);

    for (auto i = 0; i<8; ++i)
    {
        auto y=7-i;
        for (auto x = 0; x<8; ++x)
        {
            auto pieceStr = initialPlecement[i][x];

            std::shared_ptr<Piece> newPiece;
            PieceColor newPieceColor;

            if (pieceStr.at(0) == '0')
                continue; // no piece on this square

            if (pieceStr.at(1) == 'b')
                newPieceColor = PieceColor::black;
            else if (pieceStr.at(1) == 'w')
                newPieceColor = PieceColor::white;
            else throw("Board state corrupt!");

            if (pieceStr.at(0) == 'K')
                newPiece = std::make_shared<King>(x, y, newPieceColor, sharedBoardPtr);
            else if (pieceStr.at(0) == 'Q')
                newPiece = std::make_shared<Queen>(x, y, newPieceColor, sharedBoardPtr);
            else if (pieceStr.at(0) == 'N')
                newPiece = std::make_shared<Knight>(x, y, newPieceColor, sharedBoardPtr);
            else if (pieceStr.at(0) == 'B')
                newPiece = std::make_shared<Bishop>(x, y, newPieceColor, sharedBoardPtr);
            else if (pieceStr.at(0) == 'R')
                newPiece = std::make_shared<Rook>(x, y, newPieceColor, sharedBoardPtr);
            else if (pieceStr.at(0) == 'p')
                newPiece = std::make_shared<Pawn>(x, y, newPieceColor, sharedBoardPtr);
            else throw("Board state corrupt!");


            auto pole = squaresVec[y][x];

            pole->setPiece(newPiece);
        }
    }
}

void Board::squareClicked(ClickableSquare* ptr)
{
    QMessageBox msgBox;
    //if (squaresVec[0][0]->containsPiece())
       // QMessageBox::question(&msgBox, "", QString::number(1+ptr->getPiece()->getLocation().x) + " " + QString::number(1+ptr->getPiece()->getLocation().y), QMessageBox::Yes);


    switch(state)
    {
    case BoardState::defaultState:
        if (ptr->containsPiece() && ptr->getPiece()->getColor() == movingPlayerColor)
        {
            ptr->setStyle(ZAZNACZONY);
            movingPieceLocation = ptr->getPiece()->getLocation();
            state = BoardState::srcSelected;

            // display legal moves
            for (const auto& move : ptr->getPiece()->getLegalMoves())
            {
                squaresVec[move.y][move.x]->setStyle(MOZLIWY_RUCH);
            }
        }
        break;
    //TODO: ADD CASE FOR DESTSELECTED
    case BoardState::srcSelected:
        if (ptr->containsPiece())
        {
            if (ptr->getStyle() == ZAZNACZONY) // undo selection without making a move
            {
                state = BoardState::defaultState;
                refresh();
            }
            else if (ptr->getStyle() == MOZLIWY_RUCH) // capture
            {
                ptr->setPiece(nullptr);
                auto destPos = ptr->getLocation();
                squaresVec[movingPieceLocation.y][movingPieceLocation.x]->getPiece()->move(destPos.x, destPos.y);
                state = BoardState::defaultState;
                refresh();
            }
        }
        else if (ptr->getStyle() == MOZLIWY_RUCH) // move the piece from src to dest
        {
            auto destPos = ptr->getLocation();
            squaresVec[movingPieceLocation.y][movingPieceLocation.x]->getPiece()->move(destPos.x, destPos.y);
            state = BoardState::defaultState;
            refresh();
        }
        break;
    default:
        break;
    }
}

void Board::refresh()
{
    switch (state)
    {
    case BoardState::defaultState:
        for (auto y=0; y<8; ++y)
        {
            for (auto x=0; x<8; ++x)
            {
                squaresVec[y][x]->resetStyle();
            }
        }
        break;
    default:
        break;
    }


}
