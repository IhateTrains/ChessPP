#include "clickableSquare.h"

ClickableSquare::ClickableSquare(unsigned short x, unsigned short y, const QString& defaultStyle, QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent), currentStyle(defaultStyle), defaultStyle(defaultStyle), pos{x, y}
{
    setStyle(defaultStyle);

    // set the square size
    setFixedHeight(80);
    setFixedWidth(80);
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


void ClickableSquare::setPiece(const std::shared_ptr<Piece>& _piece)
{
    piece = _piece;
    update();
}


void ClickableSquare::update()
{
    if (!piece)
        clear();
    else
    {
        const int w = width();
        const int h = height();
        QPixmap pix(piece->getImagePath().c_str());
        setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}
