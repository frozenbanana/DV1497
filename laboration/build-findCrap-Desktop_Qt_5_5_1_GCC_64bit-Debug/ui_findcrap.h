/********************************************************************************
** Form generated from reading UI file 'findcrap.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDCRAP_H
#define UI_FINDCRAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindCrap
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *goButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *pathLine;
    QPushButton *searchButton;
    QMenuBar *menuBar;
    QMenu *menuFindCrap;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FindCrap)
    {
        if (FindCrap->objectName().isEmpty())
            FindCrap->setObjectName(QStringLiteral("FindCrap"));
        FindCrap->resize(757, 473);
        centralWidget = new QWidget(FindCrap);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 451, 311));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        goButton = new QPushButton(widget);
        goButton->setObjectName(QStringLiteral("goButton"));

        horizontalLayout->addWidget(goButton);


        verticalLayout->addLayout(horizontalLayout);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(470, 10, 253, 29));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pathLine = new QLineEdit(widget1);
        pathLine->setObjectName(QStringLiteral("pathLine"));

        horizontalLayout_2->addWidget(pathLine);

        searchButton = new QPushButton(widget1);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout_2->addWidget(searchButton);

        FindCrap->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FindCrap);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 757, 25));
        menuFindCrap = new QMenu(menuBar);
        menuFindCrap->setObjectName(QStringLiteral("menuFindCrap"));
        FindCrap->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FindCrap);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FindCrap->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FindCrap);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FindCrap->setStatusBar(statusBar);

        menuBar->addAction(menuFindCrap->menuAction());

        retranslateUi(FindCrap);

        QMetaObject::connectSlotsByName(FindCrap);
    } // setupUi

    void retranslateUi(QMainWindow *FindCrap)
    {
        FindCrap->setWindowTitle(QApplication::translate("FindCrap", "FindCrap", 0));
        label->setText(QApplication::translate("FindCrap", "Search for:", 0));
        goButton->setText(QApplication::translate("FindCrap", "Go!", 0));
        searchButton->setText(QApplication::translate("FindCrap", "Get text file", 0));
        menuFindCrap->setTitle(QApplication::translate("FindCrap", "FindCrap", 0));
    } // retranslateUi

};

namespace Ui {
    class FindCrap: public Ui_FindCrap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDCRAP_H
