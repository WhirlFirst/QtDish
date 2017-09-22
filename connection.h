#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dishsystem");
    db.setUserName("root");
    db.setPassword("");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection."
                     ), QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("create table user (name varchar(20) primary key, "
               "number varchar(20),""password varchar(20))");
    query.exec("create table dish (name varchar(20) primary key,""price int,""status varchar(15),""number int,score float)");
    query.exec("create table chef (name varchar(20) primary key,""pwd varchar(20),""averagetime float,""averagescore float,""dishnumber float)");
    query.exec("create table waiter (name varchar(20) primary key,"" pwd varchar(20)," "score float,""acount int)");
    for(int i=0;i<30;i++){
        query.exec(QString("create table dish%1 (number int primary key,name varchar(20),price int,status varchar(15),score float)").arg(i));
    }
    query.exec("create table ttable (number int primary key,"" name varchar(20)," "status varchar(20),waiter varchar(20))");
    for(int i=0;i<30;i++){
        query.exec(QString("create table message%1 (number int primary key,thing varchar(30))").arg(i));
        query.exec(QString("create table chefmessage%1 (number int primary key,name varchar(30))").arg(i));
    }
    return true;
}

#endif // CONNECTION_H
