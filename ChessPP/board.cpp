#include "board.h"

Board::Board(QWidget* parent, QGridLayout* gridLayout): gridLayout(gridLayout)
{
    for (int i = 0; i<8; ++i)
    {
         for (int j = 0; j<8; ++j)
         {
             // create a chess square
             ClickableSquare* pole = new ClickableSquare(parent);
             QObject::connect(pole, &ClickableSquare::clicked,
                         this, &Board::squareClicked);
             squaresVec.append(pole);

             // determine square color
             if ((i+(j%2))%2 == 1) { pole->setStyleSheet(CIEMNY); pole->defaultStyle = CIEMNY; } // dark square
             else { pole->setStyleSheet(JASNY); pole->defaultStyle = JASNY; } // bright square

             // set the square size
             pole->setFixedHeight(80);
             pole->setFixedWidth(80);

             // add the square to the board
             this->gridLayout->addWidget(pole,i,j);
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

    for (unsigned int i = 0; i<8; ++i)
    {
        for (unsigned int j = 0; j<8; ++j)
        {
            auto pieceStr = initialPlecement[i][j];

            Piece* newPiece;

            if (pieceStr.at(0) == '0')
                continue; // no piece on this square
            if (pieceStr.at(0) == 'K')
                newPiece = new King;
            else if (pieceStr.at(0) == 'Q')
                newPiece = new Queen;
            else if (pieceStr.at(0) == 'N')
                newPiece = new Knight;
            else if (pieceStr.at(0) == 'B')
                newPiece = new Bishop;
            else if (pieceStr.at(0) == 'R')
                newPiece = new Rook;
            else if (pieceStr.at(0) == 'p')
                newPiece = new Pawn;
            else throw("Board state corrupt!");

            if (pieceStr.at(1) == 'b')
                newPiece->color = PieceColor::black;
            else if (pieceStr.at(1) == 'w')
                newPiece->color = PieceColor::white;
            else throw("Board state corrupt!");


            QPixmap pix(newPiece->getImagePath().c_str());
            auto pole = squaresVec[i*8 + j];
            int w = pole->width();
            int h = pole->height();
            pole->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            pole->piece = newPiece;
        }
    }
}

void Board::squareClicked(ClickableSquare* ptr)
{
    switch(state)
    {
    case BoardState::defaultState:
        if (ptr->containsPiece())
        {
            ptr->setStyle(ZAZNACZONY);
            state = BoardState::srcSelected;
        }
        break;
    //TODO: ADD CASE FOR DESTSELECTED
    case BoardState::srcSelected:
        if (ptr->containsPiece())
        {
            if (ptr->getStyle() == ZAZNACZONY)
            {
                ptr->setStyle(ptr->defaultStyle);// undo selection without making a move
                state = BoardState::defaultState;
            }
        }
        break;
    default:
        break;
    }
}
