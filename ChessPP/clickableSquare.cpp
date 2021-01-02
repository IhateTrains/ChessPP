#include "clickableSquare.h"

ClickableSquare::ClickableSquare(const QString& defaultStyle, QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent), currentStyle(defaultStyle), defaultStyle(defaultStyle)
{
    setStyleSheet(defaultStyle);
}

ClickableSquare::~ClickableSquare() {}

void ClickableSquare::mousePressEvent(QMouseEvent* event) {
    emit clicked(this);
}

bool ClickableSquare::containsPiece() const
{
    if (piece == nullptr) return false;
    return true;
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
