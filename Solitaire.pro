#-------------------------------------------------
#
# Project created by QtCreator 2017-11-17T11:18:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Solitaire
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    Card.cpp \
    Deck.cpp \
    CardItem.cpp \
    DeckItem.cpp \
    CardPile.cpp \
    Tableau.cpp \
    TableauPile.cpp \
    CardPileItem.cpp \
    GameItem.cpp \
    SelectionPile.cpp \
    FoundationPile.cpp \
    FoundationPileItem.cpp

HEADERS += \
        MainWindow.h \
    Card.h \
    Deck.h \
    CardItem.h \
    DeckItem.h \
    CardPile.h \
    Tableau.h \
    TableauPile.h \
    CardPileItem.h \
    GameItem.h \
    SelectionPile.h \
    FoundationPile.h \
    FoundationPileItem.h

FORMS +=
