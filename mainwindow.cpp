#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/DB/DB.h"
#include <QStandardItemModel>
#include "src/Author/Author.h"
#include "src/Author/AuthorService.h"
#include <QDebug>
#include <QList>
#include "src/Author/AuthorQueryCondition.h"
#include "utils/ArrayListt/ArrayListt.h"
#include "utils/LinkedListt/LinkedListt.h"

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
        AuthorService *authorService = new AuthorService();
        Author author = authorService->findFirst();

        QStandardItem *idCol = new QStandardItem(QString::number(author.getId()));
        QStandardItem *nameCol = new QStandardItem(author.getName());

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
        AuthorQueryCondition* authorCondition = new AuthorQueryCondition();
        authorCondition->setLimit(5);
        authorCondition->setOffsetId(40);

        AuthorService* authorService = new AuthorService();
        Listt<Author>* authorList = authorService->findAll(authorCondition);

        QStandardItemModel *model = new QStandardItemModel();
        QStringList horizontalHeader;
        horizontalHeader.append("ID");
        horizontalHeader.append(QString::fromUtf8("Tên tác giả"));
        model->setHorizontalHeaderLabels(horizontalHeader);
        ui->tableView->setModel(model);
        for (int i = 0; i < authorList->getSize(); i++) {
            QStandardItem *idCol = new QStandardItem("test");
            QStandardItem *nameCol = new QStandardItem((authorList->get(i)).getName());

            model->appendRow( QList<QStandardItem*>() << idCol << nameCol);
        }

        ui->label->setText(QString::number(authorService->count()));
    } catch(const char* msg) {
        // show dialog instead console log
        qDebug() << msg;
    }
}

// find author by Id
void MainWindow::on_pushButton_4_clicked()
{
    try {
        AuthorService* authorService = new AuthorService();
        Author author = authorService->findById(5);

        QStandardItemModel *model = new QStandardItemModel();
        QStringList horizontalHeader;
        horizontalHeader.append("ID");
        horizontalHeader.append(QString::fromUtf8("Tên tác giả"));
        model->setHorizontalHeaderLabels(horizontalHeader);
        ui->tableView->setModel(model);

        QStandardItem *idCol = new QStandardItem(QString::number(author.getId()));
        QStandardItem *nameCol = new QStandardItem(author.getName());

        model->appendRow( QList<QStandardItem*>() << idCol << nameCol);

    } catch(const char* msg) {
        qDebug() << msg;
    }
}
