#ifndef PROMOTIONDIALOG_H
#define PROMOTIONDIALOG_H

#include <QDialog>
#include "QGridLayout"

namespace Ui {
class promotionDialog;
}

class promotionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit promotionDialog(QWidget *parent = nullptr);
    ~promotionDialog();

private:
    Ui::promotionDialog *ui;

    QGridLayout* gridLayout = nullptr;
};

#endif // PROMOTIONDIALOG_H
