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


private slots:
    void add_clicked();
    void item_clicked(QModelIndex index);
    void show_new();
    void hide_new();
    void hide_detail();
    void setEditable(int edit);
    void update();
    void delete_item();
    void add();
    void search();

private:
    /**
     * @brief updateId
     * update all Id by order before closing the app
     */
    void updateId();
    /**
     * @brief ui GUI
     */
    Ui::MainWindow *ui;
    /**
     * @brief selected: item selected (n-th row)
     */
    int selected;
    /**
     * @brief deck: determine item's id by its n-th row
     */
    QList<int> deck;
    /**
     * @brief number size of the current UI
     */
    int number;
    /**
     * @brief to_list : paint to the QListView
     * @param query : query result
     * @param champs : which key to displayed the result
     */
    void to_list(QSqlQuery query,QString champs);
    /**
     * @brief set_deck: pre-set deck
     */
    void set_deck();
    /**
     * @brief set_combobox pre-set comboBox
     */
    void set_combobox();
    /**
     * @brief init_setup setUps
     */
    void init_setup();

};

#endif // MAINWINDOW_H
