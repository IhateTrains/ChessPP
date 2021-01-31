#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clickableSquare.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->board->setHorizontalSpacing(0);
    ui->board->setVerticalSpacing(0);

    board = new Board(this, ui->board);
    QObject::connect(ui->actionSave, &QAction::triggered,
                     board, &Board::saveState);
    board->initialize();

    // add to QGridLayout board;
    //this->setLayout(ui->board);
}

MainWindow::~MainWindow()
{
    delete board;
    delete ui;
}

