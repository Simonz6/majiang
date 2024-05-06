#ifndef CONNNECTION_H
#define CONNNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

static bool createConnection(){


    //连接第一个数据库
    //QMYSQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "connection1");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("root");
    db.setPort(8889);
    //test_majiang.db
    db.setDatabaseName("test_majiang");

    if (!db.open()) {
        //critical(QWidget *parent, const QString &title,
        //const QString &text,
        //QMessageBox::StandardButtons buttons = Ok,
        //QMessageBox::StandardButton defaultButton = NoButton)
           QMessageBox::critical(0, "Cannot open database",
                                 "Unable to establish a database connection", QMessageBox::Cancel);
           return false;
       }

    return true;
}
#endif // CONNNECTION_H
