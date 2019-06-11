/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *New;
    QListView *listView;
    QFrame *pop;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *Back;
    QFormLayout *formLayout_2;
    QLabel *nAMELabel_2;
    QLineEdit *nAMELineEdit_2;
    QLabel *eMAILLabel_2;
    QLineEdit *eMAILLineEdit_2;
    QLabel *tELLabel_2;
    QLineEdit *tELLineEdit_2;
    QLabel *eDITLabel;
    QCheckBox *eDITCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Delete_Button;
    QPushButton *Edit_Button;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout;
    QLabel *nAMELabel;
    QLineEdit *nAMELineEdit;
    QLabel *eMAILLabel;
    QLineEdit *eMAILLineEdit;
    QLabel *tELLabel;
    QLineEdit *tELLineEdit;
    QPushButton *Cancel;
    QPushButton *Confirm;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(287, 581);
        MainWindow->setIconSize(QSize(32, 32));
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setSizeIncrement(QSize(0, 0));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        horizontalLayout_2->addLayout(horizontalLayout);

        New = new QPushButton(centralWidget);
        New->setObjectName(QString::fromUtf8("New"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        New->setFont(font);
        New->setCursor(QCursor(Qt::PointingHandCursor));
        New->setFlat(false);

        horizontalLayout_2->addWidget(New);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        QFont font1;
        font1.setPointSize(12);
        listView->setFont(font1);
        listView->setSpacing(4);
        listView->setModelColumn(0);
        listView->setSelectionRectVisible(true);
        listView->setItemAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(listView);

        pop = new QFrame(centralWidget);
        pop->setObjectName(QString::fromUtf8("pop"));
        pop->setAutoFillBackground(true);
        pop->setFrameShape(QFrame::StyledPanel);
        pop->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(pop);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        Back = new QPushButton(pop);
        Back->setObjectName(QString::fromUtf8("Back"));

        horizontalLayout_4->addWidget(Back);


        verticalLayout->addLayout(horizontalLayout_4);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        nAMELabel_2 = new QLabel(pop);
        nAMELabel_2->setObjectName(QString::fromUtf8("nAMELabel_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nAMELabel_2);

        nAMELineEdit_2 = new QLineEdit(pop);
        nAMELineEdit_2->setObjectName(QString::fromUtf8("nAMELineEdit_2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, nAMELineEdit_2);

        eMAILLabel_2 = new QLabel(pop);
        eMAILLabel_2->setObjectName(QString::fromUtf8("eMAILLabel_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, eMAILLabel_2);

        eMAILLineEdit_2 = new QLineEdit(pop);
        eMAILLineEdit_2->setObjectName(QString::fromUtf8("eMAILLineEdit_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, eMAILLineEdit_2);

        tELLabel_2 = new QLabel(pop);
        tELLabel_2->setObjectName(QString::fromUtf8("tELLabel_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, tELLabel_2);

        tELLineEdit_2 = new QLineEdit(pop);
        tELLineEdit_2->setObjectName(QString::fromUtf8("tELLineEdit_2"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, tELLineEdit_2);

        eDITLabel = new QLabel(pop);
        eDITLabel->setObjectName(QString::fromUtf8("eDITLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, eDITLabel);

        eDITCheckBox = new QCheckBox(pop);
        eDITCheckBox->setObjectName(QString::fromUtf8("eDITCheckBox"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, eDITCheckBox);


        verticalLayout->addLayout(formLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        Delete_Button = new QPushButton(pop);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));

        horizontalLayout_3->addWidget(Delete_Button);

        Edit_Button = new QPushButton(pop);
        Edit_Button->setObjectName(QString::fromUtf8("Edit_Button"));

        horizontalLayout_3->addWidget(Edit_Button);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addWidget(pop);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nAMELabel = new QLabel(frame);
        nAMELabel->setObjectName(QString::fromUtf8("nAMELabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nAMELabel);

        nAMELineEdit = new QLineEdit(frame);
        nAMELineEdit->setObjectName(QString::fromUtf8("nAMELineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nAMELineEdit);

        eMAILLabel = new QLabel(frame);
        eMAILLabel->setObjectName(QString::fromUtf8("eMAILLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, eMAILLabel);

        eMAILLineEdit = new QLineEdit(frame);
        eMAILLineEdit->setObjectName(QString::fromUtf8("eMAILLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, eMAILLineEdit);

        tELLabel = new QLabel(frame);
        tELLabel->setObjectName(QString::fromUtf8("tELLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, tELLabel);

        tELLineEdit = new QLineEdit(frame);
        tELLineEdit->setObjectName(QString::fromUtf8("tELLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, tELLineEdit);

        Cancel = new QPushButton(frame);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Cancel);

        Confirm = new QPushButton(frame);
        Confirm->setObjectName(QString::fromUtf8("Confirm"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Confirm);


        horizontalLayout_5->addLayout(formLayout);


        verticalLayout_2->addWidget(frame);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 287, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Contact List", nullptr));
#ifndef QT_NO_TOOLTIP
        New->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>New</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        New->setText(QApplication::translate("MainWindow", "New", nullptr));
        Back->setText(QApplication::translate("MainWindow", "Back", nullptr));
        nAMELabel_2->setText(QApplication::translate("MainWindow", "NAME", nullptr));
        eMAILLabel_2->setText(QApplication::translate("MainWindow", "EMAIL", nullptr));
        tELLabel_2->setText(QApplication::translate("MainWindow", "TEL", nullptr));
        eDITLabel->setText(QApplication::translate("MainWindow", "EDIT", nullptr));
        Delete_Button->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        Edit_Button->setText(QApplication::translate("MainWindow", "Edit", nullptr));
        nAMELabel->setText(QApplication::translate("MainWindow", "NAME", nullptr));
        eMAILLabel->setText(QApplication::translate("MainWindow", "EMAIL", nullptr));
        tELLabel->setText(QApplication::translate("MainWindow", "TEL", nullptr));
        Cancel->setText(QApplication::translate("MainWindow", "Cancel", nullptr));
        Confirm->setText(QApplication::translate("MainWindow", "Comfirm", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
