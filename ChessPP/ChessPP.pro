QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    board.cpp \
    clickableSquare.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    mainwindow.cpp \
    pawn.cpp \
    piece.cpp \
    queen.cpp \
    rook.cpp

HEADERS += \
    bishop.h \
    board.h \
    clickableSquare.h \
    king.h \
    knight.h \
    mainwindow.h \
    pawn.h \
    piece.h \
    queen.h \
    rook.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Chess_Artwork/Chess Board/Wood/border_bottom_legend.png \
    ../Chess_Artwork/Chess Board/Wood/border_bottom_legend.png \
    ../Chess_Artwork/Chess Board/Wood/border_left_legend.png \
    ../Chess_Artwork/Chess Board/Wood/border_left_legend.png

RESOURCES += \
    resources.qrc
