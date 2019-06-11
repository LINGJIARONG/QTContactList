#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QtSql>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();
    void searchBy();


public slots:
    void add_clicked();
    void itemClicked(QModelIndex index);
    void showNew();
    void hideNew();
    void hide_pop();
    void setEditable(int edit);
    void update();
    void deleteItem();
    void add();
    void search();



private:
    void updateId();
    Ui::MainWindow *ui;
    int selected;
    QList<int> deck;
    int number;
    void to_list(QSqlQuery query);
    void to_list(QSqlQuery query,QString champs);

};

#endif // MAINWINDOW_H
