#-------------------------------------------------
#
# Project created by QtCreator 2014-12-05T13:19:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MatrixCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    saisiematrice.cpp \
    gerermatrice.cpp \
    conteneur.cpp \
	matrice.cpp \
    operation.cpp \
    determinant.cpp \
    matriceinverse.cpp \
    puissance.cpp \
    norme.cpp \
    trace.cpp \
    transposee.cpp \
    multmatricescalaire.cpp \
    enregistrermatrice.cpp \
    ouvrirmatrice.cpp

HEADERS  += mainwindow.h \
    saisiematrice.h \
    gerermatrice.h \
    conteneur.h \
	matrice.h \
    operation.h \
    determinant.h \
    matriceinverse.h \
    puissance.h \
    norme.h \
    trace.h \
    transposee.h \
    multmatricescalaire.h \
    enregistrermatrice.h \
    ouvrirmatrice.h

FORMS    += mainwindow.ui \
    saisiematrice.ui \
    gerermatrice.ui \
    operation.ui \
    determinant.ui \
    matriceinverse.ui \
    puissance.ui \
    norme.ui \
    trace.ui \
    transposee.ui \
    multmatricescalaire.ui \
    enregistrermatrice.ui \
    ouvrirmatrice.ui
