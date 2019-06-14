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

#define max_capacity 500

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_setup();//initial state of UI
    //handle signals and slots
    connect(ui->New,SIGNAL(clicked()),this, SLOT(add_clicked()));
    connect(ui->Back,SIGNAL(clicked()),this, SLOT(hide_detail()));
    connect(ui->eDITCheckBox, SIGNAL(stateChanged(int)), this, SLOT(setEditable(int)));
    connect(ui->Edit_Button,SIGNAL(clicked()),this, SLOT(update()));
    connect(ui->Delete_Button,SIGNAL(clicked()),this,SLOT(delete_item()));
    connect(ui->Cancel,SIGNAL(clicked()),this,SLOT(hide_new()));
    connect(ui->Confirm,SIGNAL(clicked()),this,SLOT(add()));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(search()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(search()));
}

/**
 * @brief MainWindow::init_setup
 */
void MainWindow::init_setup(){
    ui->lineEdit->setPlaceholderText("Search..");
    set_deck();
    set_combobox();
    ui->pop->hide();
    hide_new();
}

/**
 * @brief MainWindow::set_combobox
 */
void MainWindow::set_combobox(){
    QStringList list;
    list<<" "<<"NAME"<<"TEL"<<"EMAIL";
    ui->comboBox->addItems(list);
    ui->comboBox->setCurrentIndex(1);
}

/**
 * @brief MainWindow::set_deck
 */
void MainWindow::set_deck(){
    QString q="SELECT * from contact;";
    QSqlQuery query;
    query.exec(q);
    query.last();
    number=query.at() + 1;
    qDebug()<<number;
    for(int i=1;i<=number;i++){
        deck.append(i);
    }
}

bool verifyMail(QString email){
    QRegExp Exp ("^[\\w|\\.]+@[\\w]+\\.[\\w]{2,4}$");
    return (email.contains (Exp));
}

bool verifyNumber(QString tel){
    QRegExp Exp ("^[+]{0,1}[(]{0,1}[0-9]{1,4}[)]{0,1}[-\\s0-9]{8,15}$");
    return (tel.contains (Exp));
}

QString verifyDuplicate(QString email,QString tel){
    QSqlQuery query;
    QString q="SELECT * from contact where TEL =:tel AND EMAIL=:email ;";
    query.prepare(q);
    query.bindValue(":tel",tel);
    query.bindValue(":email",email);
    query.exec();
    query.last();
    int number=query.at() + 1;
    qDebug()<<number<<"+number "<<q;
    query.first();
    qDebug()<< query.value(0).toString()<<"\t"<<query.value(1).toString()<<
               "\t"<<query.value(2).toString()<<"\t"<<query.value(3).toString()<<endl;

    if(number<1)
        return "";
    else{
        QString message="name : "+query.value(1).toString()+",tel : "+query.value(3).toString()+
                ",email : "+query.value(2).toString()+" already exists! (Fail: same phone number + email)";
        return message;
    }

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
    QString message=verifyDuplicate(email,tel);
    qDebug()<<"mes"<<message;
    if(name.isEmpty()){
        QMessageBox::information (this, "Validation", "Empty name !");
    }
    else if (!verifyMail(email))
        QMessageBox::information (this, "Validation", "email address no valide !");
    else if(!verifyNumber(tel)){
        QMessageBox::information (this, "Validation", "phone number no valide !");
    }else if(!message.isEmpty()){
        QMessageBox::warning (this, "Warning", message);
    }else {
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
        hide_new();
        search();
    }
}

void MainWindow::setEditable(int edit){
    ui->nAMELineEdit_2->setReadOnly(!edit);
    ui->eMAILLineEdit_2->setReadOnly(!edit);
    ui->tELLineEdit_2->setReadOnly(!edit);
    ui->Delete_Button->setEnabled(edit);
    ui->Edit_Button->setEnabled(edit);
}

void MainWindow::delete_item(){

    int id=deck[selected];
    QString q="DELETE from contact WHERE ID ='"+QString::number(id)+"';";
    deck.removeAt(selected);
    QSqlQuery query;
    query.exec(q);
    search();//refresh
    number--;
    hide_detail();
}

void MainWindow::update(){
    QString name=ui->nAMELineEdit_2->text();
    QString email=ui->eMAILLineEdit_2->text();
    QString tel=ui->tELLineEdit_2->text();
    QString message=verifyDuplicate(email,tel);

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
        hide_detail();
        search();
    }
}

void MainWindow::item_clicked(QModelIndex index){
    selected=index.row();
    int id=deck[selected];
    ui->listView->hide();
    ui->pop->show();
    ui->lineEdit->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->New->setEnabled(false);
    QSqlQuery query;
    query.prepare("select * from contact where ID = :id");
    query.bindValue(":id",QString::number(id));
    query.exec();
    if(query.next()){
        ui->nAMELineEdit_2->setText(query.value(1).toString());
        ui->eMAILLineEdit_2->setText(query.value(2).toString());
        ui->tELLineEdit_2->setText(query.value(3).toString());
        ui->eDITCheckBox->setChecked(false);
        setEditable(false);
    }

}


void MainWindow::hide_detail(){
    ui->pop->hide();
    ui->listView->show();
    ui->lineEdit->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->New->setEnabled(true);
}

void MainWindow::add_clicked(){
    if(number>=max_capacity){
        QString h="Max "+QString::number(max_capacity)+ "contact information.\n ";
        QMessageBox::warning (this, "Validation", h);
    }
    else
        show_new();
}

void MainWindow::search(){
    QString champs=ui->comboBox->currentData(0).toString();
    QString value=ui->lineEdit->text();
    QSqlQuery query;
    if(champs!=" "){
        QString q="select * from contact where  "+champs +
                " like :value order by NAME COLLATE NOCASE;";
        query.prepare(q);
        query.bindValue(":value", "%"+value+"%");
        qDebug()<<q<<champs;
        query.exec();
    }else{
        QString q="select * from contact where NAME"
                  " like :value OR EMAIL like :value OR TEL like :value order by NAME COLLATE NOCASE;";
        query.prepare(q);
        query.bindValue(":value", "%"+value+"%");
        qDebug()<<q<<champs;
        query.exec();
    }
    to_list(query,champs);
    deck.clear();
    query.first();
    do{
        QSqlRecord rec = query.record();
        int idx=rec.indexOf("ID");
        int id=query.value(idx).toInt();
        deck.append(id);
    }while(query.next());
}



void MainWindow::to_list( QSqlQuery query,QString champs){
    QStringList list;
    if(champs=="TEL"||champs=="EMAIL"){
        while(query.next()){
            QSqlRecord rec = query.record();
            int idx1=rec.indexOf("NAME");
            int idx2=rec.indexOf(champs);
            list<< query.value(idx1).toString()+ "\n"+champs+" : "+  query.value(idx2).toString();
        }
    }else if(champs=="NAME"){
        while(query.next()){
            QSqlRecord rec = query.record();
            int idx1=rec.indexOf("NAME");
            list<< query.value(idx1).toString()+ "\n";
        }
    }else if(champs==" "){
        while(query.next()){
            QSqlRecord rec = query.record();
            int idx1=rec.indexOf("NAME");
            int idx2=rec.indexOf("EMAIL");
            int idx3=rec.indexOf("TEL");
            list<< query.value(idx1).toString()+ "\n E-mail : "+  query.value(idx2).toString()+ "\n TEL : "
                   +  query.value(idx3).toString();
        }
    }
    int nCount=list.size();
    QStandardItemModel *QS=new QStandardItemModel(this);
    for(int i=0;i<nCount;i++){
        QString qs=list.at(i);
        QStandardItem* item=new QStandardItem(qs);
        item->setDragEnabled(false);
        item->setTextAlignment(Qt::AlignCenter);
        item->setEditable(false);
        QS->appendRow(item);
    }
    ui->listView->reset();
    ui->listView->setModel(QS);
    list.clear();
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(item_clicked(QModelIndex)));
}


void MainWindow::hide_new(){
    ui->listView->show();
    ui->lineEdit->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->New->setEnabled(true);
    ui->frame->hide();
    search();
}


void MainWindow::show_new(){
    ui->frame->show();
    ui->eMAILLineEdit->setPlaceholderText("*@*.**");
    ui->nAMELineEdit->setPlaceholderText("A Name");
    ui->tELLineEdit->setPlaceholderText("A Number");
    ui->listView->hide();
    ui->lineEdit->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->New->setEnabled(false);

}

MainWindow::~MainWindow()
{
    ui->lineEdit->setText("");
    search();
    updateId();
    delete ui;
}

