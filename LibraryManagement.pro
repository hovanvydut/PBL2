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
    src/DB/DB.cpp \
    src/Publisher/Publisher.cpp \
    src/Category/Category.cpp \
    utils/Date/Date.cpp \
    src/IssuingCompany/IssuingCompany.cpp \
    src/Author/Author.cpp \
    src/Author/AuthorRepository.cpp \
    src/Author/AuthorQueryCondition.cpp \
    src/Author/AuthorService.cpp \
    base/Repository.cpp \
    utils/ArrayListt/ArrayListt.cpp \
    utils/Listt/Listt.cpp \
    utils/LinkedListt/LinkedListt.cpp \
    utils/NodeLinkedListt/NodeLinkedListt.cpp \
    src/Publisher/PublisherRepository.cpp \
    base/Entity.cpp \
    utils/Comparable/Comparable.cpp

HEADERS  += mainwindow.h \
    src/DB/DB.h \
    src/Publisher/Publisher.h \
    src/Category/Category.h \
    utils/Date/Date.h \
    src/IssuingCompany/IssuingCompany.h \
    src/Author/Author.h \
    src/Author/AuthorRepository.h \
    src/Author/AuthorQueryCondition.h \
    src/Author/AuthorService.h \
    base/Repository.h \
    utils/ArrayListt/ArrayListt.h \
    utils/Listt/Listt.h \
    utils/LinkedListt/LinkedListt.h \
    utils/NodeLinkedListt/NodeLinkedListt.h \
    src/Publisher/PublisherRepository.h \
    base/Entity.h \
    utils/Comparable/Comparable.h

FORMS    += mainwindow.ui
