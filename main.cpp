#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <cstdlib>
#include <QtWidgets>

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("contact.dat");
    if (!db.open()) {
        QMessageBox::warning(nullptr, QObject::tr("Database Error"),
                             db.lastError().text());
        return false;
    }
    return true;
}


void createFakeData()
{
    QSqlQuery query;
    query.exec("DROP TABLE contact");
    query.exec("create table contact(ID INTEGER PRIMARY KEY AUTOINCREMENT ,NAME VARCHAR(255) NOT NULL,"
               "EMAIL VARCHAR(255) NOT NULL, TEL INTEGER NOT NULL)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'LING Jiarong','ling@contact.fr',61232170)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Lebron James','James@contact.fr',60000970)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Kobe Bryant','Bryant@contact.fr',60083170)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Stephen Curry','curry@contact.fr',98722170)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Dick Nowizki','Dick@contact.fr',69932170)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'John Smith','john_smith@contact.fr',62252490)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Paul Celestin','paul_celestin@contact.fr',69832170)");
    query.exec("select * from contact");
//    while(query.next()){
//           qDebug()<< query.value(0).toString()<<"\t"<<query.value(1).toString()<<
//                      "\t"<<query.value(2).toString()<<"\t"<<query.value(3).toString()<<endl;
//    }
}


void searchBy(QSqlQuery query,QString attribute,QString value){
      QString q="select * from contact where "+ attribute +" = :value";
     // qDebug()<<q<<endl;
      query.prepare(q);
      query.bindValue(":value",value);
      query.exec();

//      while(query.next()){
//             qDebug()<< query.value(0).toString()<<"\t"<<query.value(1).toString()<<
//                        "\t"<<query.value(2).toString()<<"\t"<<query.value(3).toString()<<endl;
//      }
}



int main(int argc, char *argv[])
{
    bool existingData = QFile::exists("contact.dat");
    if (!createConnection())
        return 1;
    if (!existingData)
        createFakeData();
    QSqlQuery query;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return  a.exec();
}
