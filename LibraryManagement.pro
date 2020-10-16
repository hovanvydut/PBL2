#-------------------------------------------------
#
# Project created by QtCreator 2020-10-15T14:48:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryManagement
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/Book/Book.cpp \
    src/DB/DB.cpp \
    src/Publisher/Publisher.cpp \
    src/Category/Category.cpp \
    utils/Date/Date.cpp \
    src/IssuingCompany/IssuingCompany.cpp \
    src/Author/Author.cpp \
    src/Author/AuthorController.cpp \
    src/Author/AuthorRepository.cpp \
    src/Author/AuthorQueryCondition.cpp

HEADERS  += mainwindow.h \
    src/Book/Book.h \
    src/DB/DB.h \
    src/Publisher/Publisher.h \
    src/Category/Category.h \
    utils/Date/Date.h \
    src/IssuingCompany/IssuingCompany.h \
    src/Author/Author.h \
    src/Author/AuthorController.h \
    src/Author/AuthorRepository.h \
    src/Author/AuthorQueryCondition.h

FORMS    += mainwindow.ui
