#include "promotiondialog.h"
#include "ui_promotiondialog.h"

#include "clickableSquare.h"
#include "piece.h"

promotionDialog::promotionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::promotionDialog)
{
    ui->setupUi(this);

/*
    PieceColor color = PieceColor::white;
    ClickableSquare* pole;
    pole = new ClickableSquare(0, 0, JASNY, this); // bright square

    // connect square's signals to board's slot
    //QObject::connect(pole, &ClickableSquare::clicked,
    //            this, &Board::squareClicked);

    // add square to array
    //squaresVec[y][x] = pole;

    // set the square size
    pole->setFixedHeight(80);
    pole->setFixedWidth(80);

    // add the square to the board
    this->gridLayout->addWidget(pole,1,1);
*/


}

promotionDialog::~promotionDialog()
{
    delete ui;
}
