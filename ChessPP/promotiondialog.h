#ifndef PROMOTIONDIALOG_H
#define PROMOTIONDIALOG_H

#include <QDialog>
#include "QGridLayout"
#include "clickableSquare.h"

namespace Ui {
class promotionDialog;
}

class promotionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit promotionDialog(PieceColor pieceColor, QWidget *parent = nullptr);
    ~promotionDialog();

public slots:
    void squareClicked(ClickableSquare* ptr);

private:
    Ui::promotionDialog *ui;

    QGridLayout* gridLayout = nullptr;
    std::array<ClickableSquare*, 4> squaresArray;
};

#endif // PROMOTIONDIALOG_H
