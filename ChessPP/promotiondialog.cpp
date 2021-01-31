#include "promotiondialog.h"
#include "ui_promotiondialog.h"

#include "piece.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"

#include "qmessagebox.h"

promotionDialog::promotionDialog(PieceColor pieceColor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::promotionDialog)
{
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    ui->setupUi(this);
    ui->gridLayout->setHorizontalSpacing(10);
    ui->gridLayout->setVerticalSpacing(0);

    //auto color = PieceColor::white;
    ClickableSquare* pole;
    for (auto i=0; i<4; ++i)
    {
        pole = new ClickableSquare(i, 0, JASNY, this);

        // connect square's signals to board's slot
        QObject::connect(pole, &ClickableSquare::clicked,
                    this, &promotionDialog::squareClicked);

        // add square to array
        squaresArray[i] = pole;

        std::shared_ptr<Piece> newPiece;
        switch (i)
        {
        case 0: { newPiece = std::make_shared<Queen>(0, 0, pieceColor, nullptr); break; }
        case 1: { newPiece = std::make_shared<Rook>(1, 0, pieceColor, nullptr); break; }
        case 2: { newPiece = std::make_shared<Bishop>(2, 0, pieceColor, nullptr); break; }
        case 3: { newPiece = std::make_shared<Knight>(3, 0, pieceColor, nullptr); break; }
        default: break;
        }
        pole->setPiece(newPiece);

        // add the square to the board
        ui->gridLayout->addWidget(pole,0,i);
    }
}

promotionDialog::~promotionDialog()
{
    delete ui;
    for (const auto& pole : squaresArray)
        delete pole;
}

void promotionDialog::squareClicked(ClickableSquare* ptr)
{
    done(ptr->getLocation().x);
}
