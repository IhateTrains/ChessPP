#include "clickableSquare.h"

ClickableSquare::ClickableSquare(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {}

ClickableSquare::~ClickableSquare() {}

void ClickableSquare::mousePressEvent(QMouseEvent* event) {
    emit clicked(this);
}

bool ClickableSquare::containsPiece() const
{
    if (piece) return true;
    return false;
}

void ClickableSquare::setStyle(const QString& style)
{
    currentStyle = style;
    setStyleSheet(currentStyle);
}

const QString& ClickableSquare::getStyle() const
{
    return currentStyle;
}
