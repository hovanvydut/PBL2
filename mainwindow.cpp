#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/DB/DB.h"
#include <QStandardItemModel>
#include "src/Author/Author.h"
#include "src/Author/AuthorController.h"
#include <QDebug>
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Load books
void MainWindow::on_pushButton_clicked()
{
    DB *db = DB::getInstance();
    QSqlQuery* query = db->getQuery();
    query->exec("SELECT * FROM books");

    QStandardItemModel *model = new QStandardItemModel();
    QStringList horizontalHeader;
    QStringList verticalHeader;
    horizontalHeader.append("ID");
    horizontalHeader.append(QString::fromUtf8("Tên sách"));
    horizontalHeader.append(QString::fromUtf8("Loại bìa"));
    horizontalHeader.append(QString::fromUtf8("Tồng cộng"));
    model->setHorizontalHeaderLabels(horizontalHeader);
    ui->tableView->setModel(model);
    while(query->next()){
        QStandardItem *col1 = new QStandardItem(query->value(0).toString());
        QStandardItem *col2 = new QStandardItem(query->value(1).toString());
        QStandardItem *col3 = new QStandardItem(query->value(2).toString());
        QStandardItem *col4 = new QStandardItem(query->value(4).toString());
        model->appendRow( QList<QStandardItem*>() << col1 << col2 << col3 << col4);
    }
}


// Load first author
void MainWindow::on_pushButton_2_clicked()
{
    try {
        AuthorController *authControl = new AuthorController();
        Author* author = authControl->findFirst();

        QStandardItem *idCol = new QStandardItem(QString::number(author->getId()));
        QStandardItem *nameCol = new QStandardItem(author->getName());

        QStandardItemModel *model = new QStandardItemModel();
        QStringList horizontalHeader;
        horizontalHeader.append("ID");
        horizontalHeader.append(QString::fromUtf8("Tên tác giả"));
        model->setHorizontalHeaderLabels(horizontalHeader);
        ui->tableView->setModel(model);

        model->appendRow( QList<QStandardItem*>() << idCol << nameCol);
    } catch(const char* msg) {
        qDebug() << msg;
    }
}

// find all authors
void MainWindow::on_pushButton_3_clicked()
{
    try {
        AuthorController* authControl = new AuthorController();
        QList<Author*> authorList = authControl->findAll();

        QStandardItemModel *model = new QStandardItemModel();
        QStringList horizontalHeader;
        horizontalHeader.append("ID");
        horizontalHeader.append(QString::fromUtf8("Tên tác giả"));
        model->setHorizontalHeaderLabels(horizontalHeader);
        ui->tableView->setModel(model);

        for (int i = 0; i < authorList.size(); i++) {
            QStandardItem *idCol = new QStandardItem(QString::number(authorList.at(i)->getId()));
            QStandardItem *nameCol = new QStandardItem(authorList.at(i)->getName());

            model->appendRow( QList<QStandardItem*>() << idCol << nameCol);
        }
        ui->label->setText(QString::number(authControl->count()));
    } catch(const char* msg) {
        qDebug() << msg;
    }
}

// find author by Id
void MainWindow::on_pushButton_4_clicked()
{
    try {
        AuthorController* authControl = new AuthorController();
        Author* author = authControl->findById(5);

        QStandardItemModel *model = new QStandardItemModel();
        QStringList horizontalHeader;
        horizontalHeader.append("ID");
        horizontalHeader.append(QString::fromUtf8("Tên tác giả"));
        model->setHorizontalHeaderLabels(horizontalHeader);
        ui->tableView->setModel(model);

        QStandardItem *idCol = new QStandardItem(QString::number(author->getId()));
        QStandardItem *nameCol = new QStandardItem(author->getName());

        model->appendRow( QList<QStandardItem*>() << idCol << nameCol);

    } catch(const char* msg) {
        qDebug() << msg;
    }
}
