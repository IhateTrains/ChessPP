#ifndef CLICKABLESQUARE_H
#define CLICKABLESQUARE_H


#define CIEMNY "background-color: rgb(207, 140, 72);"
#define JASNY "background-color: rgb(254, 206, 160);"
#define ZAZNACZONY "background-color: rgb(0, 0, 255);"
#define BITY "background-color: rgb(255, 0, 0);"
#define MOZLIWY_RUCH "background-color: rgb(0, 255, 0);"


#include <QLabel>
#include <QWidget>
#include <Qt>
#include "piece.h"


class ClickableSquare : public QLabel { // A QLabel, but clickable.
    Q_OBJECT

public:
    explicit ClickableSquare(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableSquare();

    [[nodiscard]] bool containsPiece() const;
    void setStyle(const QString& style);
    const QString& getStyle() const;

    QString defaultStyle;
    Piece* piece = nullptr;

private:
    QString currentStyle;

signals:
    void clicked(ClickableSquare* ptr);

protected:
    void mousePressEvent(QMouseEvent* event);


};

#endif // CLICKABLESQUARE_H
