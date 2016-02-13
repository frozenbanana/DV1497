#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "findcrap.h"
#include "ui_findcrap.h"

FindCrap::FindCrap(QWidget *parent) : QMainWindow(parent), ui(new Ui::FindCrap){
    ui->setupUi(this);
    void getTextFile(QString fileName);
}

FindCrap::~FindCrap(){
    delete ui;
}

void FindCrap::on_goButton_clicked(){
    QString word = ui->lineEdit->text();
    ui->textEdit->find(word,QTextDocument::FindWholeWords);
}

void FindCrap::getTextFile(QString fileName){
    QFile myFile(fileName);
    myFile.open(QIODevice::ReadOnly);
    QTextStream textStream(&myFile);
    QString line = textStream.readAll();
    myFile.close();
    ui->textEdit->setPlainText(line);
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor,1);
}

void FindCrap::on_searchButton_clicked()
{
    QString fileName = ui->pathLine->text();
    getTextFile(fileName);
}
