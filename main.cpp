#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <cstdlib>
#include <QtWidgets>
/**
 * @brief createConnection
 * @return true if success
 */
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

/**
 * @brief createFakeData: pre fill database
 */
void createFakeData()
{
    QSqlQuery query;
    query.exec("DROP TABLE contact;");
    query.exec("create table contact(ID INTEGER PRIMARY KEY AUTOINCREMENT ,NAME VARCHAR(255) NOT NULL,"
               "EMAIL VARCHAR(255) NOT NULL, TEL INTEGER NOT NULL);");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'LING Jiarong','ling@contact.fr',61232170);");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Lebron James','James@contact.fr',60000970)");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Kobe Bryant','Bryant@contact.fr',60083170);");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Stephen Curry','curry@contact.fr',98722170);");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Dick Nowizki','Dick@contact.fr',69932170);");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'John Smith','john_smith@contact.fr',62252490);");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'Paul Celestin','paul_celestin@contact.fr',69832170);");
    query.exec("insert into contact(ID,NAME,EMAIL, TEL) "
               "VALUES (NULL,'MC Jin','Jin@contact.fr',2321370);");
}


int main(int argc, char *argv[])
{
    bool existingData = QFile::exists("contact.dat");
    if (!createConnection())
        return 1;
    if (!existingData)
        createFakeData();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return  a.exec();
}
