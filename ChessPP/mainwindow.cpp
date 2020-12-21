#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clickablelabel.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->board->setHorizontalSpacing(0);
    ui->board->setVerticalSpacing(0);

    QVector<ClickableLabel*> squaresVec;

    bool isSquareDark = false;

    for (int i = 0; i<64; ++i)
    {
        // create a chess square
        ClickableLabel* pole = new ClickableLabel(this);
        squaresVec.append(pole);

        // determine square color
        if (!isSquareDark) { pole->setStyleSheet("background-color: rgb(207, 140, 72);"); isSquareDark = true; }
        else { pole->setStyleSheet("background-color: rgb(254, 206, 160);"); isSquareDark = false; } // przezroczysty czarny
        if ((i+1)%8==0) isSquareDark = !isSquareDark;

        // set the square size
        pole->setFixedHeight(80);
        pole->setFixedWidth(80);

        // this is a test: add a piece to the square
        QPixmap pix(":/images/BishopW.png");
        int w = pole->width();
        int h = pole->height();
        pole->setPixmap (pix.scaled (w,h,Qt::KeepAspectRatio));

        // add the square to the board
        ui->board->addWidget(pole,i/8,i%8);
    }

    // add to QGridLayout board;
     //this->setLayout(ui->board);


}

MainWindow::~MainWindow()
{
    delete ui;
}

