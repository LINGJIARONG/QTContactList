#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QModelIndex>
#include <Qt>
#include <QtSql>
#include <QColor>
#include <QtWidgets>
#include <QBrush>
#include <iostream>
#include <string>
#include <regex>

#define max_capacity 100

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QString q="SELECT * from contact;";
    QSqlQuery query;
    query.exec(q);
    query.last();
    //  qDebug() << query.at() + 1;

    number=query.at() + 1;
    qDebug()<<number;
    for(int i=1;i<=number;i++){
        deck.append(i);
    }
    QStringList list;
    list<<"NAME"<<"TEL"<<"EMAIL";
    ui->comboBox->addItems(list);
    ui->pop->hide();
    hideNew();
    connect(ui->New,SIGNAL(clicked()),this, SLOT(add_clicked()));
    connect(ui->Back,SIGNAL(clicked()),this, SLOT(hide_pop()));
    connect(ui->eDITCheckBox, SIGNAL(stateChanged(int)), this, SLOT(setEditable(int)));
    connect(ui->Edit_Button,SIGNAL(clicked()),this, SLOT(update()));
    connect(ui->Delete_Button,SIGNAL(clicked()),this,SLOT(deleteItem()));
    connect(ui->Cancel,SIGNAL(clicked()),this,SLOT(hideNew()));
    connect(ui->Confirm,SIGNAL(clicked()),this,SLOT(add()));
    // connect(ui->search,SIGNAL(clicked()),this,SLOT(search()));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(search()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(search()));


}


MainWindow::~MainWindow()
{
    ui->lineEdit->setText("");
    search();
    updateId();
    delete ui;
}

bool verifyMail(QString email){
    QRegExp Exp ("^[\\w|\\.]+@[\\w]+\\.[\\w]{2,4}$");
    return (email.contains (Exp));
}

bool verifyNumber(QString tel){
    QRegExp Exp ("^[0-9]+$");
    return (tel.contains (Exp));
}

void MainWindow::updateId(){
    qDebug()<<number;
    qDebug()<<  "deck[0]: "<<deck[0]<<"deck[end]"<<deck[number-1];
    for(int i=1;i<=number;i++){
        if(i!=deck[i-1]){
            QString q="UPDATE contact "
                      "SET ID='"+QString::number(i)+"' WHERE ID ='"+QString::number(deck[i-1])+"';";
            qDebug()<<q;
            QSqlQuery query;
            query.exec(q);
        }
    }
    QSqlQuery query;

    query.exec("delete from sqlite_sequence where name='contact';");

}


void MainWindow::add(){
    QString name=ui->nAMELineEdit->text();
    QString email=ui->eMAILLineEdit->text();
    QString tel=ui->tELLineEdit->text();
    if(name.isEmpty()){
        QMessageBox::information (this, "Validation", "Empty name !");
    }
    else if (!verifyMail(email))
        QMessageBox::information (this, "Validation", "email address no valide !");
    else if(!verifyNumber(tel)){
        QMessageBox::information (this, "Validation", "phone number no valide !");
    }else{
        QSqlQuery query;
        QString q="INSERT INTO contact(ID,NAME,EMAIL,TEL) "
                  " VALUES(NULL,:name,:email,:tel);";
        query.prepare(q);
        query.bindValue(":name",name);
        query.bindValue(":email",email);
        query.bindValue(":tel",tel);
        if(query.exec())
            deck.append(++number);


        qDebug()<< number<<endl;
        hideNew();
        refresh();
    }
}

void MainWindow::setEditable(int edit){
    ui->nAMELineEdit_2->setReadOnly(!edit);
    ui->eMAILLineEdit_2->setReadOnly(!edit);
    ui->tELLineEdit_2->setReadOnly(!edit);
}

void MainWindow::deleteItem(){
    int id=deck[selected];
    QString q="DELETE from contact WHERE ID ='"+QString::number(id)+"';";
    deck.removeAt(selected);
    // qDebug()<< "i="<<selected<< m[selected];
    QSqlQuery query;
    query.exec(q);
    //qDebug()<< q<<endl;
    refresh();
    number--;

    //    while(query.next()){
    //        qDebug()<< query.value(0).toString()<<"\t"<<query.value(1).toString()<<
    //                   "\t"<<query.value(2).toString()<<"\t"<<query.value(3).toString()<<endl;
    //    }
    hide_pop();
}
void MainWindow::update(){
    QString name=ui->nAMELineEdit_2->text();
    QString email=ui->eMAILLineEdit_2->text();
    QString tel=ui->tELLineEdit_2->text();
    int id=deck[selected];
    if (!verifyMail(email))
        QMessageBox::information (this, "Validation", "email address no valide !");
    else if(!verifyNumber(tel)){
        QMessageBox::information (this, "Validation", "phone number no valide !");
    }else{
        QSqlQuery query;
        query.prepare( "UPDATE contact "
                       "SET NAME=:name, EMAIL=:email,TEL=:tel WHERE ID =:id;");
        query.bindValue(":name",name);
        query.bindValue(":email",email);
        query.bindValue(":tel",tel);
        query.bindValue(":id",QString::number(id));

        query.exec();
        hide_pop();
        search();    }
}

void MainWindow::itemClicked(QModelIndex index){
    // qDebug()<< "index.data()"<<index.data().toString()<< index.row()<<endl;
    selected=index.row();
    int id=deck[selected];
    ui->listView->hide();
    ui->pop->show();
    ui->lineEdit->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->New->setEnabled(false);
    //  QString q="select * from contact where ID = '"+ QString::number(id)+"'";
    QSqlQuery query;
    query.prepare("select * from contact where ID = :id");
    query.bindValue(":id",QString::number(id));
    query.exec();
    if(query.next()){
        //        qDebug()<< query.value(0).toString()<<"\t"<<query.value(1).toString()<<
        //                   "\t"<<query.value(2).toString()<<"\t"<<query.value(3).toString()<<endl;
        ui->nAMELineEdit_2->setText(query.value(1).toString());
        ui->eMAILLineEdit_2->setText(query.value(2).toString());
        ui->tELLineEdit_2->setText(query.value(3).toString());
        ui->eDITCheckBox->setChecked(false);
        setEditable(false);
    }

}


void MainWindow::hide_pop(){
    ui->pop->hide();
    ui->listView->show();
    ui->lineEdit->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->New->setEnabled(true);

}
void MainWindow::add_clicked(){
    if(number>=max_capacity){
        QString h="Max "+QString::number(max_capacity)+ "contact information.\n ";
        QMessageBox::information (this, "Validation", h);
    }
    else
        showNew();
}

void MainWindow::search(){
    QString champs=ui->comboBox->currentData(0).toString();
    QString value=ui->lineEdit->text();
    QSqlQuery query;
    QString q="select * from contact where  "+champs +
            " like :value;";
    query.prepare(q);
    query.bindValue(":value", "%"+value+"%");
    qDebug()<<q<<champs;
    query.exec();
    if(champs=="NAME")
        to_list(query);
    else if(champs=="TEL"||champs=="EMAIL")
        to_list(query,champs);
    else
        qDebug()<<"bug";
    deck.clear();
    query.first();
    do{
        QSqlRecord rec = query.record();
        int idx=rec.indexOf("ID");
        int id=query.value(idx).toInt();
        deck.append(id);
    }while(query.next());




}

void MainWindow ::refresh(){
    QSqlQuery query;
    QSqlRecord rec = query.record();
    query.exec("select * from contact");
    while(query.next()){
        qDebug()<< query.value(0).toString()<<"\t"<<query.value(1).toString()<<
                   "\t"<<query.value(2).toString()<<"\t"<<query.value(3).toString()<<endl;
    }
    query.exec("select NAME from contact");
    to_list(query);
    deck.clear();
    qDebug()<<number;
    for(int i=1;i<=number;i++){
        deck.append(i);
    }
}

void MainWindow::to_list( QSqlQuery query){
    QStringList list;
    while(query.next()){
        QSqlRecord rec = query.record();
        int idx=rec.indexOf("NAME");
        list<< query.value(idx).toString();
    }
    int nCount=list.size();
    QStandardItemModel *QS=new QStandardItemModel(this);
    for(int i=0;i<nCount;i++){
        QString qs=list.at(i);
        QStandardItem* item=new QStandardItem(qs);
        item->setTextAlignment(Qt::AlignCenter);
        if(i%2){
            QLinearGradient linearGrad(QPointF(0,0),QPointF(200,200));
            linearGrad.setColorAt(0,QColor(127, 0, 100, 127));
            linearGrad.setColorAt(1,QColor(127, 30, 100, 127));
            QBrush brush(linearGrad);
            item->setBackground(brush);
        }
        item->setEditable(false);
        QS->appendRow(item);
    }
    ui->listView->reset();
    ui->listView->setModel(QS);
    list.clear();
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(itemClicked(QModelIndex)));
}


void MainWindow::to_list( QSqlQuery query,QString champs){
    QStringList list;

    while(query.next()){
        QSqlRecord rec = query.record();
        int idx1=rec.indexOf("NAME");
        int idx2=rec.indexOf(champs);
        list<< query.value(idx1).toString()+ "\n"+champs+" : "+  query.value(idx2).toString();
    }
    int nCount=list.size();
    QStandardItemModel *QS=new QStandardItemModel(this);
    for(int i=0;i<nCount;i++){
        QString qs=list.at(i);
        QStandardItem* item=new QStandardItem(qs);
        item->setTextAlignment(Qt::AlignCenter);
        if(i%2){
            QLinearGradient linearGrad(QPointF(0,0),QPointF(200,200));
            linearGrad.setColorAt(0,QColor(127, 0, 100, 127));
            linearGrad.setColorAt(1,QColor(127, 30, 100, 127));
            QBrush brush(linearGrad);
            item->setBackground(brush);
        }
        item->setEditable(false);
        QS->appendRow(item);
    }
    ui->listView->reset();
    ui->listView->setModel(QS);
    list.clear();
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(itemClicked(QModelIndex)));
}

void MainWindow ::searchBy(){
    QSqlQuery query;QString attribute;QString value;
    QString q="select * from contact where "+ attribute +" = :value";
    //qDebug()<<q<<endl;
    query.prepare(q);
    query.bindValue(":value",value);
    query.exec();

    //    while(query.next()){
    //        qDebug()<< query.value(0).toString()<<"\t"<<query.value(1).toString()<<
    //                   "\t"<<query.value(2).toString()<<"\t"<<query.value(3).toString()<<endl;
    //    }
}

void MainWindow::hideNew(){
    ui->listView->show();
    ui->lineEdit->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->New->setEnabled(true);

    ui->frame->hide();

    refresh();
}

void MainWindow::showNew(){
    ui->frame->show();

    ui->listView->hide();
    ui->lineEdit->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->New->setEnabled(false);

}

