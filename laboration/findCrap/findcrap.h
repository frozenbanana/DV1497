#ifndef FINDCRAP_H
#define FINDCRAP_H

#include <QMainWindow>

namespace Ui {
class FindCrap;
}

class FindCrap : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindCrap(QWidget *parent = 0);
    ~FindCrap();

private slots:
    void on_goButton_clicked();
    void getTextFile(QString fileName);

    void on_searchButton_clicked();

private:
    Ui::FindCrap *ui;
};

#endif // FINDCRAP_H
