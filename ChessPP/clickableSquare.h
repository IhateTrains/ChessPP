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
#include <memory>


class ClickableSquare : public QLabel { // A QLabel, but clickable.
    Q_OBJECT

public:
    explicit ClickableSquare(unsigned short x, unsigned short y, const QString& defaultStyle, QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableSquare();

    [[nodiscard]] bool containsPiece() const;

    [[nodiscard]] const auto& getPiece() const { return piece; }
    void setPiece(const std::shared_ptr<Piece>& _piece);

    void setStyle(const QString& style);
    void resetStyle() { setStyle(defaultStyle); }
    const QString& getStyle() const;

    void update();

    [[nodiscard]] const auto& getLocation() const { return pos; }


private:
    QString currentStyle;
    QString defaultStyle;

    std::shared_ptr<Piece> piece = nullptr;

    Location pos;

signals:
    void clicked(ClickableSquare* ptr);

protected:
    void mousePressEvent(QMouseEvent* event);


};

#endif // CLICKABLESQUARE_H
